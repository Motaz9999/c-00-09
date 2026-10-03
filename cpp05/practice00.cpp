#include <iostream>

int divide(int numerator, int denominator)
{
    if (denominator == 0)
    {
        std::cout << "[divide] Error: division by zero!" << std::endl;
        return -1; // this is ambiguity bc it can also be a result of error
    }
    return numerator / denominator;
}

int main()
{
    std::cout << "--- Case 1: A genuine error ---" << std::endl;
    int result1 = divide(10, 0);
    std::cout << "Result: " << result1 << std::endl;
    std::cout << "\n--- Case 2: A perfectly legitimate answer that happens to be -1 ---" << std::endl;
    int result2 = divide(-10, 10);
    std::cout << "Result: " << result2 << std::endl;
    std::cout << "Notice: result1 and result2 are IDENTICAL, for completely" << std::endl;
    std::cout << "different reasons. Nothing in the return value distinguishes" << std::endl;
    std::cout << "'an error happened' from 'the answer is legitimately -1'." << std::endl;
    std::cout << "\n--- Case 3: The caller forgets to check anything at all ---" << std::endl;
    int total = divide(100, 0) + divide(50, 5);
    std::cout << "Total (silently wrong): " << total << std::endl;
    std::cout << "The compiler enforced nothing here. The error sentinel from" << std::endl;
    std::cout << "the first call was used as if it were real data, and the" << std::endl;
    std::cout << "program kept running on a corrupted value with no diagnostic." << std::endl;

    return 0;
}