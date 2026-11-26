/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice00.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 04:04:44 by moodeh            #+#    #+#             */
/*   Updated: 2026/11/26 04:19:20 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Animal
{
protected:
    int _age;

public:
    Animal(int age) : _age(age)
    {
    }
    virtual ~Animal() {}
    int getGrade() const { return _age; }
};

class Dog : public Animal
{
private:
    int _loyaltyScore;

public:
    Dog(int age, int loyaltyScore) : Animal(age), _loyaltyScore(loyaltyScore)
    {
    }
    int getLoyaltyScore() const { return _loyaltyScore; }
};

int main()
{
    std::cout << "--- Behavior 1: acts like static_cast (numeric conversion) ---" << std::endl;
    double pi = 3.99;
    int truncated = (int)pi;
    std::cout << "(int)3.99 = " << truncated << std::endl;
    std::cout << "Well-defined, lossy, exactly what static_cast<int> would do." << std::endl;
    std::cout << "\n--- Behavior 2: acts like const_cast (strips a qualifier) ---" << std::endl;
    const char *constGreeting = "hello";
    char *mutableGreeting = (char *)constGreeting; // strip the const
    std::cout << "(char*)constGreeting = \"" << mutableGreeting << "\"" << std::endl;
    std::cout << "Compiles silently. Writing through mutableGreeting here would be" << std::endl;
    std::cout << "undefined behavior, because the string literal it points to is" << std::endl;
    std::cout << "genuinely read-only -- the cast doesn't check that, only removes" << std::endl;
    std::cout << "the compiler's ability to warn you about it." << std::endl;
    std::cout << "\n--- Behavior 3: acts like static_cast on a hierarchy (correct here) ---" << std::endl;

    Dog realDog(3, 95);
    Animal *animalPtr = &realDog; // upcast always safe
    // Dog *backToDog = &animalPtr;//error cant do downcast so must use cast
    Dog *backToDog = (Dog *)animalPtr; // C-style downcast: no runtime check, but happens to be correct

    std::cout << "backToDog->getLoyaltyScore() = " << backToDog->getLoyaltyScore() << std::endl;
    std::cout << "Correct answer, purely because animalPtr genuinely pointed at a Dog." << std::endl;
    std::cout << "The cast itself performed no check that confirmed this." << std::endl;

    std::cout << "\n--- Behavior 4: acts like reinterpret_cast (genuinely dangerous) ---" << std::endl;
    Animal realAnimal(5); // this one is NOT a Dog -- there is no loyalty score anywhere
    Animal *justAnimal = &realAnimal;
    Dog *wrongCast = (Dog *)justAnimal; // same syntax as Behavior 3 -- looks identical
    std::cout << "wrongCast->getLoyaltyScore() = " << wrongCast->getLoyaltyScore() << std::endl;
    std::cout << "This is undefined behavior. There is no _loyaltyScore anywhere in" << std::endl;
    std::cout << "'realAnimal' -- that call read whatever bytes happened to sit next" << std::endl;
    std::cout << "to it in memory and printed them as if they were a real int. It" << std::endl;
    std::cout << "did not crash on this run, on this machine, with this compiler --" << std::endl;
    std::cout << "which is exactly what makes this kind of bug so dangerous." << std::endl;

    std::cout << "\n--- End of program ---" << std::endl;
    return 0;
}