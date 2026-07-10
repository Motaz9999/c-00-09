/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 21:03:50 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/10 21:50:23 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// class Point{
//     public:
//     Point();
Point::Point():_x(0) , _y(0)
{    std::cout << "[Point] Default constructor: " << *this << std::endl;}

//     Point(int x , int y);
Point::Point(int x , int y):_x(x) , _y(y)
{    std::cout << "[Point] Parameterized constructor: " << *this << std::endl;}

//     Point(Point const &other);
Point::Point(Point const& other) :_x(other._x) , _y(other._y)
{
        std::cout << "[Point] Copy constructor: " << *this << std::endl;
}
//     ~Point();
Point::~Point()
{
        std::cout << "[Point] Destructor: " << *this << std::endl;

}
//     Point& operator=(Point const &other);
Point& Point::operator=(Point const &other)
{
        std::cout << "[Point] Copy assignment" << std::endl;

    if(this == &other)
    return *this ; 
    this->_x = other._x;
    this->_y = other._y;
    return *this;
}
int Point::getX() const { return _x; }
int Point::getY() const { return _y; }

std::ostream& operator<<(std::ostream& os, Point const& p)
{
    os << "(" << p._x << ", " << p._y << ")";
    return os ;
}

// //comparisons ops
// //main ones == ,<
// //derived != > <= >=
bool operator==(Point const& obj1, Point const& obj2)
{
    if (obj1.getX() == obj2.getX() && obj1.getY() == obj2.getY())
    return true ;
    return false ;     
}

//first comp with x if equal comp with y
//obj1 < obj2
bool operator<(Point const &obj1 , Point const& obj2)
{
    if (obj1.getX() != obj2.getX())
    return (obj1.getX() < obj2.getX());
    return (obj1.getY() < obj2.getY());
}

//obj1 > obj2
bool operator>(Point const &obj1 , Point const& obj2)
{
    return (obj2 < obj1);
}
//obj1 >= obj2
//so this mean !(obj2 < obj1) 
//its like 5 >= 4
// !(5 < 4) it will return true bc
// if we ask also this 
// 10 >= 10
// !(10 < 10  ) also true 
bool operator>=(Point const &obj1 , Point const& obj2)
{
 return !(obj1 < obj2);   
}
//obj1 <= obj2
//3 <= 4 -> !(4 < 3) 
bool operator<=(Point const &obj1 , Point const& obj2)
{
    return !(obj2 < obj1);
}
bool operator!=(Point const &obj1 , Point const& obj2)
{
    return !(obj1 == obj2);
}

