#include <iostream>
#include <stdexcept>
#include <string>

// A tiny resource that logs its own lifetime, so leaks are visible as
// a simply missing "freed" line rather than something we have to take on faith.
class Resource
{
private:
    std::string _name;

public:
    Resource(const std::string &name) : _name(name)
    {
        std::cout << "  [Resource] '" << _name << "' allocated" << std::endl;
    }
    ~Resource()
    {
        std::cout << "  [Resource] '" << _name << "' freed" << std::endl;
    }
};

void riskyStep()
{
    throw std::runtime_error("something went wrong mid-function");
}
// BROKEN: leaks the Resource if riskyStep() throws, because the
// "delete r;" at the end is a normal statement -- it is simply never
// reached once control leaves via an exception. Stack unwinding only
// runs destructors for objects with AUTOMATIC storage duration; a raw
// pointer variable has no destructor of its own to call.
void leakyFunction()
{
    Resource *r = new Resource("leaky");
    riskyStep();
    delete r; // never reached
}
// MANUAL FIX: wrap the risky code, catch everything, clean up
// explicitly, then re-throw the original exception so the caller
// still sees the real failure. This works, but it's boilerplate that
// has to be repeated correctly at every single call site that
// allocates a resource this way.
void manuallyFixedFunction()
{
    Resource *r = new Resource("Manually-guarded");
    try
    {
        riskyStep();
    }
    catch (...)
    {
        delete r; // clean up before the exception continues
        throw;    // preserve the original exception, per Section
    }
    delete r; // reached only if riskyStep() succeeded
}
// RAII FIX: no pointer, no manual try/catch/delete at all. 'r' has
// automatic storage duration, so stack unwinding (Section 6.2) simply
// destroys it like any other local object on the way out -- success
// or failure, it makes no difference to this function's code.
void raiiFixedFunction()
{
    Resource r("raii-guarded");
    riskyStep();
}
int main()
{
    std::cout << "--- BROKEN: leak on throw ---" << std::endl;

    try
    {
        leakyFunction();
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }
    std::cout << "Notice: no '...freed' line above. 'leaky' was never released." << std::endl;
    std::cout << "\n--- MANUAL FIX: explicit try/catch/delete/rethrow ---" << std::endl;
    try
    {
        manuallyFixedFunction();
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << "This time 'manually-guarded' WAS freed -- but only because we" << std::endl;
    std::cout << "remembered to wrap it correctly." << std::endl;

    std::cout << "\n--- RAII FIX: no manual cleanup code at all ---" << std::endl;
    try
    {
        raiiFixedFunction();
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }
    std::cout << "'raii-guarded' was freed automatically by stack unwinding," << std::endl;
    std::cout << "with zero exception-handling code inside raiiFixedFunction()." << std::endl;

    std::cout << "\n--- End of program ---" << std::endl;
    return 0;
}