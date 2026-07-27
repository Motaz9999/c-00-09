/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice07.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 06:58:02 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/27 07:52:21 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Comprehensive demonstration of the Fixed class.
// Suppresses most OCF log messages after the construction section
// by using a stripped variant — comments indicate where constructors fire.
#include "Fixed.hpp"

void	demoConstruction(void)
{
	std::cout << "=== Demo 1: Construction ===" << std::endl;
	Fixed zero;       // default: rawBits = 0, value = 0.0
	Fixed fromInt(3); // raw = 768  , value =3.0
	Fixed fromFloat(1.5f);
	Fixed fromFloat2(0.1f); // raw 26  , value = 0.10156
	std::cout << "\n  zero      = " << zero << " (rawBits=" << zero.getRawBits() << ")" << std::endl;
	std::cout << "  fromInt   = " << fromInt << " (rawBits=" << fromInt.getRawBits() << ")" << std::endl;
	std::cout << "  fromFloat = " << fromFloat << " (rawBits=" << fromFloat.getRawBits() << ")" << std::endl;
	std::cout << "  0.1f repr = " << fromFloat2 << " (rawBits=" << fromFloat2.getRawBits() << ") ← nearest representable value to 0.1" << std::endl;
	std::cout << "\n  toInt():  fromFloat.toInt()  = " << fromFloat.toInt() << "  (1.5 truncated to 1)" << std::endl;
	std::cout << "  toFloat() fromInt.toFloat()  = " << fromInt.toFloat() << std::endl;
	std::cout << std::endl;
}
void	demoComparison(void)
{
	std::cout << "=== Demo 2: Comparison ===" << std::endl;
	Fixed a(1.5f); // rawBits = 384
	Fixed b(2.0f); // rawBits = 512
	Fixed c(1.5f); // rawBits = 384
	std::cout << "\n  a=" << a << "  b=" << b << "  c=" << c << std::endl;
	std::cout << "\n  a < b  : " << (a < b ? "true" : "false") << std::endl;
	// true
	std::cout << "  a > b  : " << (a > b ? "true" : "false") << std::endl;
	// false
	std::cout << "  a == c : " << (a == c ? "true" : "false") << std::endl;
	// true
	std::cout << "  a != b : " << (a != b ? "true" : "false") << std::endl;
	// true
	std::cout << "  b >= a : " << (b >= a ? "true" : "false") << std::endl;
	// true
	std::cout << "  a <= c : " << (a <= c ? "true" : "false") << std::endl;
	// true
	std::cout << std::endl;
}

void	demoArithmetic(void)
{
	std::cout << "=== Demo 3: Arithmetic ===" << std::endl;
	Fixed a(3.0f);
	Fixed b(1.5f);
	std::cout << "\n  a=" << a << "  b=" << b << std::endl;
    Fixed sum  = a + b;
    Fixed diff = a - b;
    Fixed prod = a * b;
    Fixed quot = a / b;
    
    std::cout << "\n  a + b = " << sum  << "  (rawBits: "
              << a.getRawBits() << " + " << b.getRawBits()
              << " = " << sum.getRawBits() << ")" << std::endl;  // 4.5
              
              
    std::cout << "  a - b = " << diff << "  (rawBits: "
              << a.getRawBits() << " - " << b.getRawBits()
              << " = " << diff.getRawBits() << ")" << std::endl;  // 1.5

              
    std::cout << "  a * b = " << prod << "  (rawBits: "
              << "(" << a.getRawBits() << " * " << b.getRawBits()
              << ") >> 8 = " << prod.getRawBits() << ")" << std::endl;  // 4.5

    std::cout << "  a / b = " << quot << "  (rawBits: "
              << "(" << a.getRawBits() << " << 8) / " << b.getRawBits()
              << " = " << quot.getRawBits() << ")" << std::endl;  // 2.0
    Fixed small(0.1f);
    Fixed tenth(0.1f);
    
    std::cout << "\n  0.1f + 0.1f + ... (10 times):" << std::endl;
    
    Fixed acc(0.0f);
    
    for (int i = 0; i < 10; ++i)
        acc = acc + small;
    std::cout << "  Result = " << acc
              << "  (exact floating-point 1.0f: 1.0)" << std::endl;
    // Fixed-point: 26 * 10 = 260 rawBits = 260/256 ≈ 1.01563 (accumulated rounding)

    std::cout << std::endl;

}
void demoIncrementDecrement()
{
    std::cout << "=== Demo 4: Increment and Decrement ===" << std::endl;

    Fixed f(1.0f);   // rawBits = 256

    std::cout << "\n  f starts at: " << f
              << " (rawBits=" << f.getRawBits() << ")" << std::endl;

    // Prefix ++ — each step adds 1/256 ≈ 0.00390625
    Fixed pre = ++f;
    std::cout << "\n  After ++f:" << std::endl;
    std::cout << "  f   = " << f   << " (rawBits=" << f.getRawBits()   << ")" << std::endl;
    std::cout << "  pre = " << pre << " (rawBits=" << pre.getRawBits() << ")" << std::endl;
    // Both show the incremented value — prefix returns the modified object.

    // Postfix ++ — returns old value
    Fixed post = f++;
    std::cout << "\n  After f++:" << std::endl;
    std::cout << "  f    = " << f    << " (rawBits=" << f.getRawBits()    << ")" << std::endl;
    std::cout << "  post = " << post << " (rawBits=" << post.getRawBits() << ")" << std::endl;
    // f shows incremented; post shows the value before the increment.

    // Decrement
    Fixed g(0.5f);   // rawBits = 128
    std::cout << "\n  g starts at: " << g
              << " (rawBits=" << g.getRawBits() << ")" << std::endl;
    --g;
    std::cout << "  After --g: " << g
              << " (rawBits=" << g.getRawBits() << ")" << std::endl;
    // rawBits 128 - 1 = 127 → 127/256 ≈ 0.49609

    std::cout << std::endl;
}
void demoMinMax() {
    std::cout << "=== Demo 5: min and max ===" << std::endl;

    Fixed a(3.5f);
    Fixed b(1.2f);

    std::cout << "\n  a=" << a << "  b=" << b << std::endl;
    std::cout << "\n  Fixed::min(a, b) = " << Fixed::min(a, b) << std::endl;  // 1.2...
    std::cout << "  Fixed::max(a, b) = " << Fixed::max(a, b) << std::endl;  // 3.5

    // Non-const: the returned reference is modifiable
    Fixed::min(a, b) = Fixed(0.0f);   // sets b to 0 (b is the min)
    std::cout << "\n  After Fixed::min(a, b) = 0.0f:" << std::endl;
    std::cout << "  a = " << a << "  b = " << b << std::endl;
    // a unchanged (3.5), b is now 0.0

    // Const version
    Fixed const ca(5.0f);
    Fixed const cb(2.0f);
    std::cout << "\n  const min(5.0, 2.0) = " << Fixed::min(ca, cb) << std::endl; // 2.0
    std::cout << "  const max(5.0, 2.0) = " << Fixed::max(ca, cb) << std::endl; // 5.0

    std::cout << std::endl;
}
void demoCombined() {
    std::cout << "=== Demo 6: Combined Expression ===" << std::endl;

    Fixed a(4.0f);
    Fixed b(2.0f);
    Fixed c(1.5f);

    // (a + b) * c
    Fixed result = (a + b) * c;
    std::cout << "\n  (" << a << " + " << b << ") * " << c
              << " = " << result << std::endl;   // (4 + 2) * 1.5 = 9.0

    // min of result and a
    std::cout << "  min(" << result << ", " << a << ") = "
              << Fixed::min(result, a) << std::endl;   // min(9.0, 4.0) = 4.0

    std::cout << std::endl;
}
int	main(void)
{
	demoConstruction();
	demoComparison();
	demoArithmetic();
	demoIncrementDecrement();
	demoMinMax();
	 demoCombined();

	std::cout << "=== All demos complete. ===" << std::endl;
	return (0);
}