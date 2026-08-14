/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amphibious.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 21:46:08 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/14 21:46:09 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMPHIBIOUS_HPP
# define AMPHIBIOUS_HPP
# include "SwimmingAnimal.hpp"
# include "WalkingAnimal.hpp"
class Amphibious : public WalkingAnimal, public SwimmingAnimal
{
  public:
	Amphibious(const std::string &name);
	~Amphibious();
};
#endif