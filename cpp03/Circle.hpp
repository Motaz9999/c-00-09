/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Circle.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 15:56:13 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/04 15:57:41 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCLE_HPP
# define CIRCLE_HPP
# include "Shape.hpp"

class Circle : public Shape
{
  private:
	double _radius; // just for circle shape
  public:
	Circle();
	Circle(double radius);
	~Circle();
};
#endif