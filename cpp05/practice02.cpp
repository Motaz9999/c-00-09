#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>


using std::cout;
using std::endl;

void checkPositive(int value)
{
    if (value < 0)
        throw std::invalid_argument("Values must not be negative");
}
void checkRange(int value, int min, int max)
{
    if (value < min || value > max)
        throw std::out_of_range("value is outside the allowed range");
}

void riskyOperation()
{
    throw std::runtime_error("Something failed during the ops");
}

int main()
{
    std::cout << "--- Catching different standard exceptions through a single std::exception& ---" << std::endl;

    try
    {
        checkPositive(-1);
    }
    catch (const std::exception &e)
    {
        cout << "CAUGHT : " << e.what() << endl;
    }
    try
    {
        checkRange(150, 0, 100);
    }
    catch (const std::exception &e)
    {
        cout << "CAUGHT : " << e.what() << endl;
    }
    try
    {
        riskyOperation();
    }
    catch (const std::exception &e)
    {
        cout << "CAUGHT : " << e.what() << endl;
    }


std::cout << "\n--- A real standard library exception: vector::at() ---" << std::endl;
    std::vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    
    try
    {
        int value = numbers.at(10);//error here
                std::cout << "Element at index 10: " << value << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cout << "Caught: " << e.what() <<endl;
    }
    
    std::cout << "\n--- End of program ---" << std::endl;

}