/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 18:02:19 by moodeh            #+#    #+#             */
/*   Updated: 2026/09/10 16:59:57 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP
#include <string>

class AAnimal
{
    private:
    protected:
    std::string _name;
    public:
    AAnimal();
    AAnimal(const std::string &name);//tell here it looks like normal class
    AAnimal(const AAnimal &obj);
    AAnimal& operator=(const AAnimal &obj);
    virtual ~AAnimal();//now its polymorphic class
    
    std::string getName() const;

    virtual void makeSound() const = 0;// this is pure Virtual Fun now the class is Abstract class
    virtual AAnimal* clone() const = 0;//pure fun
    
};
#endif