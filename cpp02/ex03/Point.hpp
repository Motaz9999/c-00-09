/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 21:13:08 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/01 10:05:05 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"
class Point
{
private:
    Fixed const _x;
    Fixed const _y;
public:
    Point();
    Point(float const x ,float const y);
    Point(Point const &other);
    Point& operator=(Point const &other); 
    ~Point();
    bool operator==(Point const &other) const ;
    Fixed getX() const ;
    Fixed getY() const ;
};
bool bsp( Point const a, Point const b, Point const c, Point const point);//outside the class


#endif