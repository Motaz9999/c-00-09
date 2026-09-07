/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fish.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 18:21:34 by moodeh            #+#    #+#             */
/*   Updated: 2026/09/07 18:23:19 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FISH_HPP
#define FISH_HPP

#include "AAnimal.hpp"
class Fish : public AAnimal
{
    private :
    protected:
    public :
    	Fish(const std::string& name);
		virtual ~Fish();
        //for example i forgot the to implement the pure fun so now this is an abstract class so it must override the fun 
        
};
#endif