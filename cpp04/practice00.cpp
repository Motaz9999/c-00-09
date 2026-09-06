// File: main.cpp
// Demonstrates the static-dispatch problem from three angles:
// direct calls (works), a heterogeneous array of base pointers (breaks),
// and a base reference parameter (breaks the same way — it isn't a
// "pointer-only" quirk).

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

// ── Demo 1: Direct Calls on Named Objects ──────────────────────────────────
// The static type of `rex` IS `Dog`; the static type of `whiskers` IS `Cat`.
// There is no base-class indirection here, so dispatch is trivially correct.
// This is the baseline — everything "works," which is exactly what makes
// the next demo surprising.
void demoDirectCalls()
{
	std::cout << "=== Demo 1: Direct Calls on Named Objects ===" << std::endl;

	Dog rex("Rex");
	Cat whiskers("Whiskers");

	std::cout << std::endl;
	rex.makeSound();
	whiskers.makeSound();
	std::cout << std::endl;
}

// ── Demo 2: The Broken Animal Array ────────────────────────────────────────
// Each element's DYNAMIC type is Dog, Cat, or Animal — but the array itself
// is declared as Animal*[3]. Every call through zoo[i] resolves against the
// STATIC type (Animal), not whatever the pointer actually points to.
void demoBrokenArray()
{
	std::cout << "=== Demo 2: The Broken Animal Array ===" << std::endl;

	Animal* zoo[3];
	zoo[0] = new Dog("Buddy");
	zoo[1] = new Cat("Luna");
	zoo[2] = new Animal("Generic Beast");

	std::cout << std::endl;
	for (int i = 0; i < 3; i++)
		zoo[i]->makeSound();
	// Expected (naive): "Woof!", "Meow!", then a generic sound.
	// Actual: a generic sound, three times — the Dog and Cat overrides
	// exist, but nothing through an Animal* can reach them.

	std::cout << std::endl;
	for (int i = 0; i < 3; i++)
		delete zoo[i];
	std::cout << std::endl;
}

// ── Demo 3: The Same Problem, By Reference ─────────────────────────────────
// greet() takes its parameter as Animal const&. Even though the argument
// bound to it is a real Dog, the STATIC type inside greet() is Animal — so
// the call to a.makeSound() resolves the exact same way it did for zoo[i].
// This proves the failure is about static vs. dynamic TYPE, not pointers
// specifically.
void greet(Animal const& a)
{
	a.makeSound();
}

void demoReferenceParameter()
{
	std::cout << "=== Demo 3: The Same Problem, By Reference ===" << std::endl;

	Dog rex("Rex");

	std::cout << "\n  Calling rex.makeSound() directly:" << std::endl;
	rex.makeSound();

	std::cout << "\n  Calling greet(rex), where greet takes Animal const&:" << std::endl;
	greet(rex);
	std::cout << std::endl;
}

int main()
{
	demoDirectCalls();
	demoBrokenArray();
	demoReferenceParameter();

	std::cout << "=== All demos complete. ===" << std::endl;
	return 0;
}