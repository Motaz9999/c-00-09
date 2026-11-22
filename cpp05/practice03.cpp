#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    std::cout << "--- Creating valid Bureaucrats ---" << std::endl;
    try
    {
        Bureaucrat b1("Alice", 1);
        std::cout << b1 << std::endl;

        Bureaucrat b2("Bob", 150);
        std::cout << b2 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Attempting to create a Bureaucrat with grade 0 (too high) ---" << std::endl;
    try
    {
        Bureaucrat invalid("Charlie", 0);
        std::cout << invalid << std::endl; // never reached
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Attempting to create a Bureaucrat with grade 151 (too low) ---" << std::endl;
    try
    {
        Bureaucrat invalid("Dana", 151);
        std::cout << invalid << std::endl; // never reached
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Pushing a valid Bureaucrat past the boundary via incrementGrade() ---" << std::endl;
    try
    {
        Bureaucrat edge("Eve", 1);
        std::cout << edge << std::endl;
        edge.incrementGrade(); // grade 1 is already the highest -- should throw
        std::cout << edge << std::endl; // never reached
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- End of program ---" << std::endl;
    return 0;
}