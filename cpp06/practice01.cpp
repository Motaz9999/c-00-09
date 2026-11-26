/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice01.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 06:40:32 by moodeh            #+#    #+#             */
/*   Updated: 2026/11/26 06:53:10 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Animal
{
public:
    Animal(int age) : _age(age) {}
    virtual ~Animal() {}
    int getAge() const { return _age; }

protected:
    int _age;
};

class Dog : public Animal
{
public:
    Dog(int age, int loyaltyScore) : Animal(age), _loyaltyScore(loyaltyScore) {}
    int getLoyaltyScore() const { return _loyaltyScore; }

private:
    int _loyaltyScore;
};

class Cat : public Animal
{
public:
    Cat(int age) : Animal(age) {}
};

int main()
{
    std::cout << "--- Numeric promotions (widening, no data loss) ---" << std::endl;
    int i = 42;
    double promoted = static_cast<double>(i); // from int to double its ok
    std::cout << "static_cast<double>(42) = " << promoted << std::endl;
    char c = 'A';
    int charPromoted = static_cast<int>(c); // from char to int so this is how we get ascii code
    std::cout << "static_cast<int>('A') = " << charPromoted << std::endl;
    std::cout << "\n--- Numeric demotions (narrowing, lossy but well-defined) ---" << std::endl;
    // from big to small
    double pi = 3.99;
    int truncated = static_cast<int>(pi);
    std::cout << "static_cast<int>(3.99) = " << truncated << std::endl;

    int big = 1000;
    char narrowed = static_cast<char>(big);
    // well-defined by the standard's conversion
    // rules, even though the result is implementation-defined for out-of-range
    // signed char targets -- NOT undefined behavior, unlike Section 7.1's Behavior 4.
    // return it to int 1000
    std::cout << "static_cast<char>(1000) = " << static_cast<int>(narrowed)
              << " (printed as int so it's readable)" << std::endl;

    std::cout << "\n--- Pointer up-casting (always safe, static_cast or implicit) ---" << std::endl;
    Dog realDog(3, 95);
    Animal *animalPtr = static_cast<Animal *>(&realDog);
    std::cout << "animalPtr->getAge() = " << animalPtr->getAge() << std::endl;
    std::cout << "\n--- Pointer down-casting (compiles because Dog IS related to Animal) ---" << std::endl;
    Dog *backToDog = static_cast<Dog *>(animalPtr);
    std::cout << "backToDog->getLoyaltyScore() = " << backToDog->getLoyaltyScore() << std::endl;
    std::cout << "Correct here only because animalPtr genuinely pointed at a Dog." << std::endl;
    std::cout << "static_cast checked that Dog and Animal are RELATED at compile" << std::endl;
    std::cout << "time -- it still performed no runtime check that this specific" << std::endl;
    std::cout << "object really is one. Getting that wrong here is exactly as" << std::endl;
    std::cout << "undefined as Section 7.1's Behavior 4. static_cast fixes the" << std::endl;
    std::cout << "'unrelated types' half of the problem, not the 'wrong object'" << std::endl;
    std::cout << "half -- Section 7.3's dynamic_cast is what actually checks that." << std::endl;
    std::cout << "\n--- End of program ---" << std::endl;
    return 0;
}