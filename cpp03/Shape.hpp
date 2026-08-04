/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shape.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 15:20:04 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/04 15:55:43 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_HPP
# define SHAPE_HPP
# include <string>
#include <iostream>
// if u know u r making a generic class make its data protected
class Shape
{
  protected:
	std::string _name;
	double _area;

  public:
	Shape();
	Shape(std::string const &name);
	~Shape();

	double getArea() const;
	std::string getName() const;
	void printInfo() const;
};
#endif