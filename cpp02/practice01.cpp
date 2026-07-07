/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice01.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 00:03:25 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/08 00:20:29 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "String.hpp"

void	verifyCopyConstruction(void)
{
	std::cout << "=== Verification 1: Copy Construction ===" << std::endl;
	String a("hello");
	String b(a); // copy constructor
	std::cout << "\n  After String b(a):" << std::endl;
	a.print("a");
	b.print("b");
	b.setContent("world");
	std::cout << "\n  After b.setContent(\"world\"):" << std::endl;
	a.print("a");
	b.print("b");
	std::cout << std::endl;
}

// copy other obj data
void	verifyCopyAssignment(void)
{
	std::cout << "=== Verification 2: Copy Assignment ===" << std::endl;
	String a("first");
	String b("second");
	std::cout << "\n  Before b = a:" << std::endl;
	a.print("a");
	b.print("b");
	b = a;
	std::cout << "\n  After b = a:" << std::endl;
	a.print("a");
	b.print("b");
	a.setContent("modified");
	std::cout << "\n  After a.setContent(\"modified\"):" << std::endl;
	a.print("a"); // "modified"
	b.print("b");
	std::cout << std::endl;
}

// a = a must leave a completely unchanged.
void	verifySelfAssignment(void)
{
	std::cout << "=== Verification 3: Self-Assignment ===" << std::endl;
	String a("same");
	std::cout << "\n  Before a = a:" << std::endl;
	a.print("a");
	a = a; // Step 1 guard fires: this == &other — returns immediately
	std::cout << "\n  After a = a:" << std::endl;
	a.print("a"); // unchanged — "same", same address
	std::cout << std::endl;
}

void	verifyChaining(void)
{
	std::cout << "=== Verification 4: Assignment Chaining ===" << std::endl;
	String a("alpha");
	String b("beta");
	String c("gamma");
	std::cout << "\n  Before a = b = c:" << std::endl;
	a.print("a");
	b.print("b");
	c.print("c");
	a = b = c;
	// Parses as: a = (b = c)
	// (b = c): b gets deep copy of c — returns String& to b
	// (a = b): a gets deep copy of b (which is now "gamma") — returns String& to a
	c.setContent("World");
	std::cout << "\n  After and set content of c to \" world\" a = b = c:" << std::endl;
	a.print("a"); // "gamma"
	b.print("b"); // "gamma"
	c.print("c"); // "gamma" — unchanged, still owns its own buffer
	std::cout << std::endl;
}

void	useString(String s)
{
 // copy constructor called here
	std::cout << "  Inside useString: ";
	s.print("s");
} // s's destructor fires here — frees s's own buffer, not a's
void	verifyPassByValue(void)
{
	std::cout << "=== Verification 5: Pass by Value ===" << std::endl;
	String a("passed");
	std::cout << "\n  Calling useString(a):" << std::endl;
	useString(a); // deep copy made — s is independent
	std::cout << "\n  After useString returns:" << std::endl;
	a.print("a"); // intact — s's destructor did not free a's buffer
	std::cout << std::endl;
}

int	main(void)
{
	verifyCopyConstruction();
	verifyCopyAssignment();
	verifySelfAssignment();
	verifyChaining();
	verifyPassByValue();

	std::cout << "=== All verifications complete. ===" << std::endl;
	return (0);
}