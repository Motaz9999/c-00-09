/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice01.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 18:11:53 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/07 19:55:13 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BrokenString.hpp"

void	demoSilentMutation(void)
{
	std::cout << "=== Demo 1: Silent Mutation ===" << std::endl;
	BrokenString a("hello");
	BrokenString b(a); // copy constructor make by compiler
	std::cout << "\n  After BrokenString b(a):" << std::endl;
	a.print("a");
	b.print("b"); // both have same _data on the buffer
	std::cout << "\n  Calling b.overwriteFirst('X')..." << std::endl;
	b.overwriteFirstChar('F');
	a.print("a");
	b.print("b"); // both have same _data on the buffer so both will change
	std::cout << std::endl;
}

void	demoDoubleFree(void)
{
	std::cout << "=== Demo 2: Double-Free ===" << std::endl;
	BrokenString a("world");
	std::cout << "\n  Creating b as a shallow copy of a..." << std::endl;
	{
		BrokenString b(a);
		std::cout << "\n  a and b while b is alive:" << std::endl;
		a.print("a");
		b.print("b");
		std::cout << "\n  Leaving inner scope — b's destructor fires:" << std::endl;
	}
		// very dangerous bc now i have dangling pointer if i use it or free it will be error in the program
	std::cout << "\n  b is gone. a now holds a dangling pointer." << std::endl;
	std::cout << "  (Accessing a._data here is undefined behavior — skipped.)" << std::endl;
	std::cout << "  Leaving demoDoubleFree — a's destructor fires:" << std::endl;
	std::cout << std::endl;
}

// it will be leaks bc the assigning operator will replace old with new (leaks)
void	demoAssignmentLeak(void)
{
	std::cout << "=== Demo 3: Assignment Leak ===" << std::endl;
	BrokenString a("first");
	BrokenString b("second");
	std::cout << "\n  Before b = a:" << std::endl;
	a.print("a");
	b.print("b");
	std::cout << "\n  Executing b = a (compiler-generated shallow assignment)..." << std::endl;
	b = a; // obj = obj2 assignment ops bc i dont free the old buffer before assing to the new one 
	// b._data = a._data   b.size = a.size
	// b's original buffer address (the one showing "second" above) is overwritten.
	std::cout << "\n  After b = a:" << std::endl;
    a.print("a");
	b.print("b");

     std::cout << "\n  (Buffer holding \"second\" is leaked — no pointer to it remains.)" << std::endl;
    std::cout << std::endl;
}

int	main(void)
{
	// demoSilentMutation();
	// demoDoubleFree();
	//demoAssignmentLeak();
	std::cout << "=== All demos complete. ===" << std::endl;
	return (0);
}
