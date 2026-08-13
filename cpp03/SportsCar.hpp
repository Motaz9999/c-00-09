/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SportCar.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 21:47:03 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/13 21:48:33 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPORTSCAR_HPP
# define SPORTSCAR_HPP
# include "Car.hpp"
class SportsCar : public Car
{
  protected:
  private:
	int _topSpeed;

  public:
	SportsCar();
	SportsCar(const std::string &brand, int doors, int topSpeed);
	~SportsCar();
};
#endif