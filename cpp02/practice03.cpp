/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice03.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 22:31:38 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/10 19:03:32 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector2d.hpp"

//+ - 
//shows the full chain : non member -> copy constructor -> compound 
void demoBinaryArithmetic()
{
        std::cout << "=== Demo 1: Binary operators + and - ===" << std::endl;

    Vector2D a(3.0f, 4.0f);
    Vector2D b(1.0f, 2.0f);

    std::cout << "\n  Computing c = a + b:" << std::endl;
    Vector2D c = a + b ;
     // Call chain:
    //   operator+(a, b) [non-member invoked]
    //     → Vector2D result(a)  [copy constructor: result = (3,4)]
    //     → result += b         [operator+=: result becomes (4,6)]
    //     → return result       [result returned by value]
    //   → c initialized from returned value
     std::cout << "\n  After c = a + b:" << std::endl;
    a.print("a");   // (3, 4) — untouched
    b.print("b");   // (1, 2) — untouched
    c.print("c");   // (4, 6) — new, independent object

        std::cout << "\n  Computing d = a - b:" << std::endl;
    Vector2D d = a - b;
    // Same call chain using operator-= instead.

    std::cout << "\n  After d = a - b:" << std::endl;
    a.print("a");   // (3, 4) — still untouched
    b.print("b");   // (1, 2) — still untouched
    d.print("d");   // (2, 2)

    std::cout << std::endl;
}


//unary opr
//unary -obj return new obj btw this a member fun 

void demoUnaryMinus()
{
    std::cout << "=== Demo 2: Unary operator- ===" << std::endl;

    Vector2D a(3.0f, -5.0f);

    std::cout << "\n  Computing b = -a:" << std::endl;
    Vector2D b = -a ; 
     // Maps to: a.operator-()
    // No parameters — 'this' is the sole operand.
    // Returns a new Vector2D via parameterized constructor.
 std::cout << "\n  After b = -a:" << std::endl;
    a.print("a");     // (3, -5) — unchanged
    b.print("b"); // (-3, 5)
std::cout << "\n  Computing pos = -b:" << std::endl;
Vector2D pos = -b ;
pos.print("pos");
    std::cout << std::endl;

}
//compound ops 
void demoCompoundOperators() {
    std::cout << "=== Demo 3: Compound operators += and -= ===" << std::endl;

    Vector2D a(1.0f, 2.0f);
    Vector2D b(3.0f, 4.0f);
    Vector2D c(0.5f, 0.5f);

    std::cout << "\n  Before a += b:" << std::endl;
    a.print("a");
    a += b; 
    
        std::cout << "\n  After a += b:" << std::endl;
    a.print("a");   // (4, 6)
    b.print("b");   // (3, 4) — unchanged
 std::cout << "\n  Chaining: a += b += c (right to left):" << std::endl;
    a += b += c ;
    a.print("a");   // (7.5, 10.5)
    b.print("b");   // (3.5, 4.5)
    c.print("c");   // (0.5, 0.5) — unchanged
    
    std::cout << "\n  a -= b:" << std::endl;
    a -= b;
    a.print("a");   // (7.5 - 3.5, 10.5 - 4.5) = (4, 6)
        std::cout << std::endl;
}

void demoExpression() {
    std::cout << "=== Demo 4: Combined Expression ===" << std::endl;

    Vector2D a(4.0f, 3.0f);
    Vector2D b(1.0f, 1.0f);
    Vector2D c(2.0f, 2.0f);

    std::cout << "\n  Computing result = (a + b) - c:" << std::endl;
    Vector2D result = (a + b) - c;
    // Step 1: a + b  → operator+(a, b)
    //           → copy a into tmp (copy ctor)
    //           → tmp += b  (operator+=)
    //           → return tmp by value → temporary Vector2D(5, 4)
    
    // Step 2: temporary - c → operator-(temporary, c)
    //           → copy temporary into result_inner (copy ctor)
    //           → result_inner -= c  (operator-=)
    //           → return result_inner by value
    
    // Step 3: result initialized from returned value

    std::cout << "\n  After result = (a + b) - c:" << std::endl;
    a.print("a");          // (4, 3) — unchanged
    b.print("b");          // (1, 1) — unchanged
    c.print("c");          // (2, 2) — unchanged
    result.print("result");// (3, 2)

    std::cout << a <<std::endl;
}
int main() {
    demoBinaryArithmetic();
    demoUnaryMinus();
    demoCompoundOperators();
    demoExpression();

    std::cout << "=== All demos complete. ===" << std::endl;
    return 0;
}
