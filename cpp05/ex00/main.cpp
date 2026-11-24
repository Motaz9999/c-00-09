#include "Bureaucrat.hpp"
#include <iostream>
using std::cout;
using std::endl;
int main()
{
    cout << "--- Creating valid Bureaucrats ---" << endl;
    try
    {
        Bureaucrat b1("Alice", 1);
        cout << b1 << endl;

        Bureaucrat b2("Bob", 150);
        cout << b2 << endl;
    }
    catch (const std::exception &e)
    {
        cout << "Unexpected exception: " << e.what() << endl;
    }

    cout << "\n--- Attempting to create a Bureaucrat with grade 0 (too high) ---" << endl;
    try
    {
        Bureaucrat invalid("Charlie", 0);
        cout << invalid << endl; // never reached
    }
    catch (const std::exception &e)
    {
        cout << "Caught: " << e.what() << endl;
    }

    cout << "\n--- Attempting to create a Bureaucrat with grade 151 (too low) ---" << endl;
    try
    {
        Bureaucrat invalid("Dana", 151);
        cout << invalid << endl; // never reached
    }
    catch (const std::exception &e)
    {
        cout << "Caught: " << e.what() << endl;
    }

    cout << "\n--- test   decrementGrade() incrementGrade() ---" << endl;
    try
    {
        Bureaucrat edge("ana", 100);
        cout << edge << endl;
        edge.decrementGrade();
        cout << edge << "after dec" << endl;
        edge.incrementGrade();
        cout << edge << "after inc" << endl;
    }
    catch (const std::exception &e)
    {
        cout << "Caught: " << e.what() << endl;
    }

    cout << "\n--- Pushing a valid Bureaucrat past the boundary via incrementGrade() ---" << endl;
    try
    {
        Bureaucrat edge("Eve", 1);
        cout << edge << endl;
        edge.incrementGrade(); // grade 1 is already the highest -- should throw
        cout << edge << endl;  // never reached
    }
    catch (const std::exception &e)
    {
        cout << "Caught: " << e.what() << endl;
    }

    cout << "\n--- Pushing a valid Bureaucrat past the boundary via decrementGrade() ---" << endl;
    try
    {
        Bureaucrat edge("adam", 150);
        cout << edge << endl;
        edge.decrementGrade(); // grade 1 is already the highest -- should throw
        cout << edge << endl;  // never reached
    }
    catch (const std::exception &e)
    {
        cout << "Caught: " << e.what() << endl;
    }

    cout << "\n--- End of program ---" << endl;
    return 0;
}
