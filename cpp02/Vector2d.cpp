/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2d.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 18:06:51 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/10 18:55:54 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector2d.hpp"

// class Vector2D
// {
//   public:
// 	Vector2D();
// 	Vector2D(float x, float y);
// 	Vector2D(Vector2D const &other);
// 	Vector2D &operator=(Vector2D const &other);
// 	~Vector2D();
// 	float getX() const;
// 	float getY() const;
//     //i want to make -obj that dont have parameter but it do return a new vector with neg valus
//     //it dosent mod the original obj that called the fun that his member
//     Vector2D operator-() const ;
//    
	//--compound assignment as members btw this is binary opr but take one par bc the other is THIS
//     //a+=b a-=b modify a in place
//     //it have return type (return *this bc chaining)
//     //no new obj needed
//     Vector2D& operator+=(Vector2D const &rhs);
//     Vector2D& operator-=(Vector2D const &rhs);
//     //utility
//     void print(std::string const& label) const;
//   private:
// 	float _x, _y;
// };
// //let add some non-member ops
// //i want to use cout << obj to print and i want to add 2 vectors an - them together and these make new obj


// 	Vector2D();
// 	Vector2D(float x, float y);
// 	Vector2D(Vector2D const &other);
// 	Vector2D &operator=(Vector2D const &other);
Vector2D::Vector2D(void) : _x(0.0f), _y(0.0f)
{
	std::cout << "[Vector2D] Default constructor: (0, 0)" << std::endl;
}
Vector2D::Vector2D(float x, float y) : _x(x), _y(y)
{
	std::cout << "[Vector2D] Parameterized constructor: (" << _x << "," << _y << ")" << std::endl;
}
Vector2D::Vector2D(Vector2D const &other) : _x(other._x), _y(other._y)
{
	std::cout << "[Vector2D] Copy constructor: (" << _x << "," << _y << ")" << std::endl;
}

// copy assignment
Vector2D &Vector2D::operator=(Vector2D const &other)
{
	std::cout << "[Vector2D] Copy assignment: (" << other._x << "," << other._y << ")" << std::endl;
	if (this == &other)
		return (*this);
	this->_x = other.getX();
	this->_y = other.getY();
	return (*this);
}

Vector2D::~Vector2D()
{
	std::cout << "[Vector2D] Destructor: (" << _x << "," << _y << ")" << std::endl;
}

float Vector2D::getX() const
{
	return (_x);
}
float Vector2D::getY() const
{
	return (_y);
}


// -obj  return new obj with neg values
Vector2D Vector2D::operator-() const
{
        std::cout << "[Vector2D] Unary operator-: negating ("
              << _x << ", " << _y << ")" << std::endl;
    return Vector2D(-this->getX() , -this->getY()); 
}

//mod the values of the obj with another obj (ADDS)
Vector2D& Vector2D::operator+=(Vector2D const &rhs)
{
    std::cout << "[Vector2D] operator+=: ("
              << _x << ", " << _y << ") += ("
              << rhs._x << ", " << rhs._y << ")" << std::endl;
    this->_x += rhs._x ;
    this->_y +=rhs._y; 
    return *this; 
}
Vector2D& Vector2D::operator-=(Vector2D const &rhs)
{
        std::cout << "[Vector2D] operator-=: ("
              << _x << ", " << _y << ") -= ("
              << rhs._x << ", " << rhs._y << ")" << std::endl;
    _x -= rhs._x;
    _y -= rhs._y;
    return *this;
}


void	Vector2D:: print(std::string const &label) const
{
        std::cout << "  " << label << ": ("
              << _x << ", " << _y << ")" << std::endl;
}

//now non member fun
//its add 2 def obj and return a new one  
Vector2D operator+(Vector2D const &obj1 ,  Vector2D const &  obj2)
{
        std::cout << "[operator+] Non-member binary +" << std::endl;

    return Vector2D(obj1.getX() + obj2.getX() , obj1.getY() + obj2.getY());
}
 Vector2D operator-(Vector2D const &obj1 ,  Vector2D const &  obj2)
 {
        std::cout << "[operator-] Non-member binary -" << std::endl;

    Vector2D obj3(obj1);
    obj3 -= obj2;
    return obj3;
 }
 std::ostream& operator<<(std::ostream& os , Vector2D const & obj )
 {
            std::cout << "print stream operator" << std::endl;
            obj.print("called by << stream");
            return os;
 }
 