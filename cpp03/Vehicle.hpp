/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vehicle.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 21:01:59 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/13 21:06:19 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEHICLE_HPP
# define VEHICLE_HPP
# include <iostream>
# include <string>
class Vehicle
{
  protected: // child can access them
	std::string _brand;

  private:
  
  public:
  Vehicle();
  Vehicle(std::string const & brand);
  ~Vehicle();
};
#endif