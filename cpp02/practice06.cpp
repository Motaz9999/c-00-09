/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice06.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 13:08:44 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/25 13:32:00 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DynamicArray.hpp"

void	demoCanonicalAssignment(void)
{
	std::cout << "=== Demo 1: Canonical Assignment ===" << std::endl;
	DynamicArray a(4, 10); // [10, 10, 10, 10]
	DynamicArray b(3, 99); // [99, 99, 99]
	std::cout << "\n  Before b = a:" << std::endl;
	a.print("a");
	b.print("b");
	a = b;
	std::cout << "\n  After b = a:" << std::endl;
	a.print("a");
	b.print("b");
	a.setAt(0, 999);
	std::cout << "\n  After a.setAt(0, 999):" << std::endl;
	a.print("a"); // [999, 10, 10, 10]
	b.print("b"); // [10, 10, 10, 10] — unchanged
	std::cout << std::endl;
}
void	demoSelfAssignment(void)
{
	std::cout << "=== Demo 2: Self-Assignment ===" << std::endl;
	DynamicArray a(3, 7);
	std::cout << "\n Before a = a:" << std::endl;
	a = a;
	std::cout << "\n  After a = a:" << std::endl;
	a.print("a"); // unchanged
	std::cout << std::endl;
}
void	demoChaining(void)
{
	std::cout << "=== Demo 3: Assignment Chaining ===" << std::endl;
	DynamicArray a(2, 1), b(2, 2), c(2, 3);
	std::cout << "\n  Before a = b = c:" << std::endl;
	a.print("a");
	b.print("b");
	c.print("c");
	a = b = c;
	// all have data as c having
	std::cout << "\n  After a = b = c:" << std::endl;
	a.print("a"); // [3, 3]
	b.print("b"); // [3, 3]
	c.print("c"); // [3, 3]
	std::cout << std::endl;
}

void	demoCopyAndSwap(void)
{
	std::cout << "=== Demo 4: Copy-and-Swap Idiom ===" << std::endl;
	DynamicArray a(3, 5); // [5, 5, 5]
	DynamicArray b(4, 8); // [8, 8, 8, 8]
	std::cout << "\n  Before copy-and-swap assignment:" << std::endl;
	a.print("a");
	b.print("b");
	// Manual copy-and-swap — equivalent in structure to what operator= would do
	// if written in copy-and-swap style:
	std::cout << "\n  Performing copy-and-swap for a = b:" << std::endl;
	{ // Step 1: Create a copy of b — all allocation here.
		// *a is not touched until after this succeeds.
		DynamicArray tmp(b); // copy constructor fires
		std::cout << "  tmp created: ";
		tmp.print("tmp");
		// Step 2: Swap a's internals with tmp.
		// After this: a holds b's content; tmp holds a's old content.
		a.swapWith(tmp);
		std::cout << "  After swap:" << std::endl;
		a.print("a");
		tmp.print("tmp"); // tmp now holds a's old resource
	}
	std::cout << "\n  After copy-and-swap assignment:" << std::endl;
	a.print("a"); // [8, 8, 8, 8] — b's content
	b.print("b"); // [5, 5, 5]    — unchanged
	std::cout << std::endl;
}
int	main(void)
{
	demoCanonicalAssignment();
	demoSelfAssignment();
	demoChaining();
	demoCopyAndSwap();
	std::cout << "=== All demos complete. ===" << std::endl;
	return (0);
}
