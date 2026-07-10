/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice04.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 19:41:01 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/10 21:54:41 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

void demoStream()
{
    std::cout << "=== Demo 1: Stream Insertion ===" << std::endl;
    Point a(3, 4);
    Point b(1, 2);
    
    std::cout << "\n  a = " << a << std::endl;
    std::cout << "  b = " << b << std::endl;
    std::cout << "\n  Chained: " << a << " and " << b << std::endl;

    std::cout << std::endl;
}

void demoEquality()
{
 std::cout << "=== Demo 2: Equality ===" << std::endl;

    Point a(3, 4);
    Point b(3, 4);   // same coordinates as a
    Point c(1, 2);   // different

    std::cout << "\n  a = " << a << "  b = " << b << "  c = " << c << std::endl;

    std::cout << "\n  a == b : " << (a == b ? "true" : "false") << std::endl;  // true
    std::cout << "  a == c : " << (a == c ? "true" : "false") << std::endl;  // false
    std::cout << "  a != c : " << (a != c ? "true" : "false") << std::endl;  // true
    std::cout << "  a != b : " << (a != b ? "true" : "false") << std::endl;  // false

    std::cout << std::endl;
}

void demoOrdering() {
    std::cout << "=== Demo 3: Ordering ===" << std::endl;

    Point p1(1, 5);   // smaller x
    Point p2(2, 0);   // larger x — p1 < p2 regardless of y
    Point p3(1, 3);   // same x as p1, smaller y — p3 < p1

    std::cout << "\n  p1 = " << p1
              << "  p2 = " << p2
              << "  p3 = " << p3 << std::endl;

    // p1 vs p2: different x → compare x only
    std::cout << "\n  p1 < p2  : " << (p1 < p2  ? "true" : "false") << std::endl; // true  (1 < 2)
    std::cout << "  p1 > p2  : " << (p1 > p2  ? "true" : "false") << std::endl; // false
    std::cout << "  p2 <= p1 : " << (p2 <= p1 ? "true" : "false") << std::endl; // false
    std::cout << "  p2 >= p1 : " << (p2 >= p1 ? "true" : "false") << std::endl; // true

    // p1 vs p3: same x → compare y
    std::cout << "\n  p3 = (1,3), p1 = (1,5) — same x, compare y:" << std::endl;
    std::cout << "  p3 < p1  : " << (p3 < p1  ? "true" : "false") << std::endl; // true  (3 < 5)
    std::cout << "  p3 > p1  : " << (p3 > p1  ? "true" : "false") << std::endl; // false
    std::cout << "  p3 <= p1 : " << (p3 <= p1 ? "true" : "false") << std::endl; // true
    std::cout << "  p3 >= p1 : " << (p3 >= p1 ? "true" : "false") << std::endl; // false

    std::cout << std::endl;
}


void demoEqualPoints() {
    std::cout << "=== Demo 4: Equal Points ===" << std::endl;

    Point a(4, 4);
    Point b(4, 4);

    std::cout << "\n  a = " << a << "  b = " << b << std::endl;
    std::cout << "\n  a == b : " << (a == b ? "true" : "false") << std::endl; // true
    std::cout << "  a != b : " << (a != b ? "true" : "false") << std::endl; // false
    std::cout << "  a <  b : " << (a <  b ? "true" : "false") << std::endl; // false
    std::cout << "  a >  b : " << (a >  b ? "true" : "false") << std::endl; // false
    std::cout << "  a <= b : " << (a <= b ? "true" : "false") << std::endl; // true
    std::cout << "  a >= b : " << (a >= b ? "true" : "false") << std::endl; // true

    std::cout << std::endl;
}

int main() {
    demoStream();
    demoEquality();
    demoOrdering();
    demoEqualPoints();

    std::cout << "=== All demos complete. ===" << std::endl;
    return 0;
}