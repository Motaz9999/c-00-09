/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Coordinates.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 21:30:27 by moodeh            #+#    #+#             */
/*   Updated: 2026/06/22 21:36:56 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Coordinates.hpp"

// private :
// const int _id;
// int _x;
// int _y;
Coordinates::Coordinates(int x, int y, int id) : _id(id), _x(x), _y(y)
{
	std::cout << "Coordinates #" << this->_id << "constructed at (" << this->_x << " ," << this->_y << ")" << std::endl;
}
void Coordinates::print(void) const
{
    std::cout << "point #" << this->_id << "-> ("  << this->_x << " ," << this->_y << ")" << std::endl;
} 
