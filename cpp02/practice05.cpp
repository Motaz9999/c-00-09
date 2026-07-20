/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice05.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 06:47:13 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/19 07:07:24 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Counter.hpp"
#include <iostream>

void	demoPrefixVsPostfix(void)
{
	std::cout << "=== Demo 1: Prefix vs Postfix ===" << std::endl;
	Counter c(5, 0, 10);
	std::cout << "\n  -- Prefix ++ --" << std::endl;
    //return the same obj
    Counter resultPre  = ++c;
    std::cout << "  After ++c:" << std::endl;
    std::cout << "  c          = " << c          << std::endl;   // 6
    std::cout << "  resultPre  = " << resultPre  << std::endl;
    
    std::cout << "\n  -- Postfix ++ --" << std::endl;
    Counter resultPost = c++;
    std::cout << "  After c++:" << std::endl;
    std::cout << "  c           = " << c           << std::endl;  // 7
    std::cout << "  resultPost  = " << resultPost  << std::endl;  // 6 — the 
       std::cout << std::endl;
}
void demoExpressionValue()
{
       std::cout << "=== Demo 2: Expression Value ===" << std::endl;

    Counter c(3, 0, 10);

    std::cout << "\n  c starts at: " << c << std::endl;
    std::cout << "\n  (++c).getValue() = " <<(++c).getValue() <<  "  [c is now: " << c << "]" << std::endl;
    std::cout << "  (c++).getValue() = " << (c++).getValue() << "  [c is now: " << c << "]" << std::endl;
 std::cout << std::endl;
}

void demoPrefixVsPostfixDecrement()
{
    std::cout << "=== Demo 3: Prefix vs Postfix -- ===" << std::endl;

    Counter c(2, 0, 10);

    std::cout << "\n  c starts at: " << c << std::endl;
    Counter pre = --c;
     std::cout << "\n  After --c:" << std::endl;
    std::cout << "  c   = " << c   << std::endl;   // 1
    std::cout << "  pre = " << pre << std::endl; // 1
     Counter post = c--;
    std::cout << "\n  After c--:" << std::endl;
    std::cout << "  c    = " << c    << std::endl;  // 0
    std::cout << "  post = " << post << std::endl;  //1
  std::cout << std::endl;
}

void demoWrapAround() {
    std::cout << "=== Demo 4: Wrap-Around ===" << std::endl;

    Counter c(9, 0, 10);

    std::cout << "\n  c starts at: " << c << std::endl;

    std::cout << "\n  ++c three times from 9 (max=10, wraps to min=0):" << std::endl;
    ++c;   // 9 → 10
    std::cout << "  " << c << std::endl;
    ++c;   // 10 → 0 (wrapped)
    std::cout << "  " << c << std::endl;
    ++c;   // 0 → 1
    std::cout << "  " << c << std::endl;

    std::cout << std::endl;
}
void demoChaining()
{
    std::cout << "=== Demo 5: Prefix Chaining ===" << std::endl;

    Counter c(0, 0, 10);
    std::cout << "\n  c starts at: " << c << std::endl;

    // ++ (++ (++c)) — equivalent to three prefix increments
    ++(++(++c));//++++++c
    std::cout << "  After ++(++(++c)): " << c << std::endl;  // 3

    std::cout << std::endl;
}
int	main(void)
{
	demoPrefixVsPostfix();
	demoExpressionValue();
	demoPrefixVsPostfixDecrement();
	demoWrapAround();
	demoChaining();

	std::cout << "=== All demos complete. ===" << std::endl;
	return (0);
}