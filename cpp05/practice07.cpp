#include <iostream>
#include <string>
#include <stdexcept>

class ThrowingDtor
{
public:
    ~ThrowingDtor()
    {
        std::cout << "[ThrowingDtor] destructor running -- about to throw!" << std::endl;
        throw std::runtime_error("a second exception, from the destructor itself");
    }
};
void triggerDoubleException()
{
    ThrowingDtor td;
    throw std::runtime_error("first exception -- unwinding starts now");
    // As the stack unwinds because of the exception above, td's
    // destructor runs -- and IT throws too. Two exceptions active at
    // once leaves the runtime with no well-defined handler to resume,
    // so it calls std::terminate() instead of trying to pick one.
}
int main()
{
    std::cout << "--- About to trigger two simultaneously-active exceptions ---" << std::endl;
    try
    {
        triggerDoubleException();
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught: " << e.what() << std::endl; // never reached
    }
    std::cout << "This line never prints." << std::endl;
    return 0;
}