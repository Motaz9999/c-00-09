/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISerializable.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 17:29:55 by moodeh            #+#    #+#             */
/*   Updated: 2026/09/09 19:10:15 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISerializable_HPP
# define ISerializable_HPP
# include <string>
class ISerializable
{
    public:
    virtual ~ISerializable(){} // so no need fo
    virtual std::string serialize() const =0;//pure fun so this is abs class or INTERFACE
};
#endif