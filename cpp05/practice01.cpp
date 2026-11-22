#include <string>
#include <iostream>
using std::cout;
using std::endl;

class ResourceGuard
{
private:
    std::string _name;

public:
    ResourceGuard(const std::string &name) : _name(name) // constructor
    {
        std::cout << "  [ResourceGuard] Acquiring '" << _name << "'" << std::endl;
    }
    ~ResourceGuard()
    {
        std::cout << "  [ResourceGuard] Releasing '" << _name << "' (destructor)" << std::endl;
    }
};

int divide(int x, int y)
{
    if (y == 0)
        throw std::string("Division by zero");
    return x / y;
}
void validateAge(int age)
{
    if (age < 0)
        throw age; // its ok but bad practice (it works fine )
}

void level3(int denominator)
{
    std::cout << "[level3] About to divide..." << std::endl;
    int result = divide(100, denominator);//error happen inside
    std::cout << "[level3] Result was: " << result << std::endl; // never reached if it throws
}
void level2(int denominator)
{
    ResourceGuard guard("level2's resource");
    std::cout << "[level2] Calling level3..." << std::endl;
    level3(denominator);//error inside it 
    std::cout << "[level2] level3 returned normally" << std::endl; // never
}
void level1(int denominator)
{
    std::cout << "[level1] Calling level2..." << std::endl;
    level2(denominator);//error inside it 
    std::cout << "[level1] level2 returned normally" << std::endl; // never
}
int main()
{
    cout << "--- Basic mechanics: try / throw / catch ---" << endl;
    try
    {
        int res = divide(10, 0);
        cout << "Result: " << res << endl; // never reach
    }
    catch (const std::string &e)
    {
        cout << "Caught exception: " << e << endl;
    }
    std::cout << "\n--- Throwing a non-object type (legal, but poor practice) ---" << std::endl;
    try
    {
        validateAge(-5);
    }
    catch (int badAge)
    {
        std::cout << "Caught exception: invalid age ->" << badAge << std::endl;
        std::cout << "(Notice there's no message here -- just a bare int. We'll fix" << std::endl;
        std::cout << "this properly with std::exception in Section 6.3.)" << std::endl;
    }
    std::cout << "\n--- Stack unwinding : watch the destructor fire on the way up ---" << endl;
    try
    {
        level1(0);//catch error inside inside ... till the divide fun 
    }
    catch (const std::string &e)
    {
        std::cout << "[MAIN] Caught exception: " << e << endl;
    }

    std::cout << "\n--- End of program ---" << std::endl;

    return 0;
}