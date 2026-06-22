/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Coordinates.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 21:24:17 by moodeh            #+#    #+#             */
/*   Updated: 2026/06/22 21:26:48 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORDINATES_HPP
# define COORDINATES_HPP
# include <iostream>
# include <string>
class Coordinates
{
    public :
    Coordinates(int x , int y , int id);
    void print (void ) const ;
    private :
    const int _id;
    int _x;
    int _y;
};
#endif