/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 20:57:09 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/10 21:12:59 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
#include <string>
class Point{
    public:
        friend std::ostream& operator<<(std::ostream& os, Point const& p);
    Point();
    Point(int x , int y);
    Point(Point const &other);
    ~Point();
    Point& operator=(Point const &other);
        int getX() const;
    int getY() const;
    private:
    int _x , _y;
};
//comparisons ops
//main ones == ,<
//derived != > <= >=
bool operator==(Point const& obj1, Point const& obj2);
bool operator<(Point const &obj1 , Point const& obj2);

bool operator>(Point const &obj1 , Point const& obj2);
bool operator>=(Point const &obj1 , Point const& obj2);
bool operator<=(Point const &obj1 , Point const& obj2);
bool operator!=(Point const &obj1 , Point const& obj2);

#endif