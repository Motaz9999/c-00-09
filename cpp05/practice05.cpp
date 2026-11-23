#include <iostream>
#include <exception>

class BaseException : public std::exception
{
public:
    virtual const char *what() const throw()
    {
        return "BaseException";
    }
};

class DerivedException : public BaseException
{
public:
    virtual const char *what() const throw()
    {
        return "DerivedException: something specific went wrong";
    }
};



void riskyOperation()
{
    throw DerivedException();
}

// Logs the exception at this level, then lets it continue propagating
// upward UNCHANGED via a bare "throw;" -- the caller above still sees
// a DerivedException, exactly as it was originally thrown.
void logAndRethrowCorrectly()
{
    try
    {
        riskyOperation();
    }
    catch (const BaseException &e)
    {
        std::cout << "[logAndRethrowCorrectly] Logging: " << e.what() << std::endl;
        throw; // re-throws the SAME exception object, preserving its real type
    }
}

// The tempting-looking but WRONG alternative: "throw e;" constructs a
// brand new exception from e. Since e's declared type here is
// BaseException, this slices exactly like any other by-value copy.
void logAndRethrowIncorrectly()
{
    try
    {
        riskyOperation();
    }
    catch (const BaseException& e)
    {
        std::cout << "[logAndRethrowIncorrectly] Logging: " << e.what() << std::endl;
        throw e; // throws a NEW BaseException, sliced from e
    }
}

int main()
{
    // NOTE: a "catch (BaseException e)" block -- catching a polymorphic
    // type BY VALUE -- deliberately does not appear as compiled code
    // here. Under the 42 flags (-Wextra specifically), GCC refuses to
    // compile it at all:
    //   error: catching polymorphic type 'class BaseException' by value
    //          [-Werror=catch-value=]
    // Compiled separately without -Werror to see what that warning is
    // protecting against, the by-value catch DOES compile and DOES
    // slice: it catches "BaseException" instead of "DerivedException:
    // something specific went wrong" -- the exact same slicing bug
    // from Section 5.6, just triggered through a catch clause instead
    // of an ordinary assignment.

    std::cout << "--- Catching by REFERENCE: no slicing ---" << std::endl;
    try
    {
        riskyOperation();
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught by reference: " << e.what() << std::endl;
    }

    std::cout << "Virtual dispatch through the reference found the real override." << std::endl;

    std::cout << "\n--- catch(...): catches literally anything, but tells you nothing ---" << std::endl;

    try
    {
        throw 3.14; // an unexpected type nobody wrote a specific handler for
    }
    catch (...)
    {
        std::cout << "Caught something via catch(...). No type, no message --" << std::endl;
        std::cout << "just proof the program is still alive. Use as a last resort." << std::endl;
    }

    std::cout << "\n--- Re-throwing: bare 'throw;' preserves the original type ---" << std::endl;
    try
    {
        logAndRethrowCorrectly();
    }
    catch (const std::exception &e)
    {
        std::cout << "[main] Final handler received: " << e.what() << std::endl;
    }
    std::cout << "\n--- Re-throwing: 'throw e;' silently slices instead ---" << std::endl;
    try
    {
        logAndRethrowIncorrectly();
    }
    catch (const BaseException &e)
    {
        std::cout << "[main] Final handler received: " << e.what() << std::endl;
    }
    std::cout << "\n--- End of program ---" << std::endl;

    return 0;
}