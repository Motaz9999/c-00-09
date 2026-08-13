/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Car.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 21:09:07 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/13 21:46:28 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAR_HPP
#define CAR_HPP

# include "Vehicle.hpp"
// car is a Vehicle
class Car : public Vehicle
{
  protected:
	int _doors;

  private:
  public:
	Car();
	Car(const std::string &brand, int doors);
	~Car();
};
#endif