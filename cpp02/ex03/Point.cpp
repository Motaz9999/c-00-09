/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 21:23:17 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/01 10:15:22 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// class Point
// {
// private:
//     Fixed const _x;
//     Fixed const _y;
// public:
Point::Point() : _x(0), _y(0)
{
	std::cout << "Default constructor" << std::endl;
}
Point::Point(float const x, float const y) : _x(x), _y(y)
{
	std::cout << "parameterize constructor" << std::endl;
}
Point::Point(Point const &other) : _x(other._x), _y(other._y)
{
	std::cout << "copy constructor" << std::endl;
}
Point &Point::operator=(Point const &other)
{
	std::cout << "Assignment operator" << std::endl;
	if (this == &other)
	{
		return (*this);
	}
	(void)other; // cant change const
	return (*this);
}
Point::~Point()
{
	std::cout << "destructor" << std::endl;
}
bool Point::operator==(Point const &other) const
{
	if (this->_x != other._x)
		return (false);

	if (this->_y != other._y)
		return (false);

	return (true);
}
Fixed Point::getX() const
{
	return (this->_x);
}
Fixed Point::getY() const
{
	return (this->_y);
}

Fixed	crossProduct(Point const &p1, Point const &p2, Point const &p3)
{
	return ((p2.getX() - p1.getX()) * (p3.getY() - p1.getY())) - ((p2.getY()
			- p1.getY()) * (p3.getX() - p1.getX()));
}
// a , b , c for triangle
// point to check
// True if the point is inside the triangle. False otherwise.
// Thus, if the point is a vertex or on an edge, it will return False.
// so we have lines here FROM point to another this line
// how i know if the point is right or left the line ?
// so p1-p2 = line
// and we have 2d cross to find area
// maybe its neg or pos the value its self its nor important
// ok triangle have 3 lines from a->b , b->c , c->a
// now we have a point how to check if it inside these 3 lines ?
// so when do cross product with the point and all points (---) or (+++) if it inside or (-+-) (++-) if outside
// so we must check if have differ sign
// each triangle must be with clock or reverse
bool	bsp(Point const a, Point const b, Point const c, Point const p)
{
	if (a == p || b == p || c == p)
	{
		return (false);
	}
	Fixed d1 = crossProduct(a, b, p);
	Fixed d2 = crossProduct(b, c, p);
	Fixed d3 = crossProduct(c, a, p);
	if (d1 == Fixed(0) || d2 == Fixed(0) || d3 == Fixed(0))
		return (false);                                                      
			// must all have values
	bool allPositive = (d1 > Fixed(0)) && (d2 > Fixed(0)) && (d3 > Fixed(0));//must be true
		// all must be pos
	bool allNegative = (d1 < Fixed(0)) && (d2 < Fixed(0)) && (d3 < Fixed(0));//must be false
		// all must be neg
	return (allPositive || allNegative);//true || false , true|| true , false||false                              
		// return this
} // outside the class
