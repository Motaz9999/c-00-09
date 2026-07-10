/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2d.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 17:13:15 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/10 18:06:43 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2D_HPP
# define VECTOR2D_HPP
# include <iostream>
# include <string>
// with OCF
// unary like ! -
// and some compound += -=
// binary as non member - + USE the compound one

class Vector2D
{
  public:
	Vector2D();
	Vector2D(float x, float y);
	Vector2D(Vector2D const &other);
	Vector2D &operator=(Vector2D const &other);
	~Vector2D();
	float getX() const;
	float getY() const;
    //i want to make -obj that dont have parameter but it do return a new vector with neg valus
    //it dosent mod the original obj that called the fun that his member
    Vector2D operator-() const ;
    //--compound assignment as members btw this is binary opr but take one par bc the other is THIS
    //a+=b a-=b modify a in place
    //it have return type (return *this bc chaining)
    //no new obj needed
    Vector2D& operator+=(Vector2D const &rhs);
    Vector2D& operator-=(Vector2D const &rhs);
    //utility
    void print(std::string const& label) const;
  private:
	float _x, _y;
};
//let add some non-member ops 
//i want to use cout << obj to print and i want to add 2 vectors and - them together and these make new obj
Vector2D operator+(Vector2D const &obj1 ,  Vector2D const &  obj2);
Vector2D operator-(Vector2D const &obj1 ,  Vector2D const &  obj2);
std::ostream& operator<<(std::ostream& os , Vector2D const & obj );
#endif