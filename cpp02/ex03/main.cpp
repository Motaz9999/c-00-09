/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 13:43:35 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/01 10:17:01 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>


int main(void)
{
    // Define the vertices of the triangle ABC
    // A(0, 0), B(10, 0), C(0, 10)
    Point const a(0.0f, 0.0f);
    Point const b(10.0f, 0.0f);
    Point const c(0.0f, 10.0f);

    std::cout << "--- TRIANGLE VERTICES ---" << std::endl;
    std::cout << "A: (0, 0) | B: (10, 0) | C: (0, 10)\n" << std::endl;

    // Test 1: Point strictly INSIDE the triangle
    Point const inside(2.0f, 2.0f);
    std::cout << "Point (2, 2) [Inside]   : " 
              << (bsp(a, b, c, inside) ? "TRUE (Passed)" : "FALSE (Failed)") 
              << std::endl;

    // Test 2: Point strictly OUTSIDE the triangle
    Point const outside(10.0f, 10.0f);
    std::cout << "Point (10, 10) [Outside]: " 
              << (!bsp(a, b, c, outside) ? "FALSE (Passed)" : "TRUE (Failed)") 
              << std::endl;

    // Test 3: Point ON A VERTEX (Should return false)
    Point const vertex(0.0f, 0.0f); // Vertex A
    std::cout << "Point (0, 0) [Vertex A] : " 
              << (!bsp(a, b, c, vertex) ? "FALSE (Passed)" : "TRUE (Failed)") 
              << std::endl;

    // Test 4: Point ON AN EDGE (Should return false)
    Point const edge(5.0f, 0.0f); // On edge AB
    std::cout << "Point (5, 0) [Edge AB]  : " 
              << (!bsp(a, b, c, edge) ? "FALSE (Passed)" : "TRUE (Failed)") 
              << std::endl;

    // Test 5: Point ON THE HYPOTENUSE EDGE (Should return false)
    Point const hypotenuse(5.0f, 5.0f); // On edge BC
    std::cout << "Point (5, 5) [Edge BC]  : " 
              << (!bsp(a, b, c, hypotenuse) ? "FALSE (Passed)" : "TRUE (Failed)") 
              << std::endl;

    return 0;
}

