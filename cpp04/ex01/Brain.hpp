/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 18:52:09 by moodeh            #+#    #+#             */
/*   Updated: 2026/10/01 18:52:10 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <string>
class Brain
{
private:
    std::string _ideas[100];
protected:
public:
    Brain();
    Brain(const std::string ideas[]); // array cant be ref
    Brain(const Brain &other);
    Brain &operator=(const Brain &other);
    ~Brain();//no need for virtual cus this isnt base class

    const std::string &getIdea(int index) const;//send index and get idea from the array
    void setIdea(int index, const std::string &idea);//set idea inside the array
};
#endif