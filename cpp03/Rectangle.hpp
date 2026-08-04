/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rectangle.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 16:01:17 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/04 16:02:34 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECTANGLE_HPP
# define RECTANGLE_HPP
# include "Shape.hpp"
class Rectangle : public Shape
{
  private:
	double _width;
	double _height; // these just for rectangle
  public:
	Rectangle();
	Rectangle(double width, double height);
	~Rectangle();
};
#endif