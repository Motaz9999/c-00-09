/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 13:00:42 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/31 13:49:13 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
class Fixed
{
    public:
    Fixed();
    Fixed(Fixed const &other);//copy constructerr
    Fixed& operator=(Fixed const &other);//copy assignment 
    ~Fixed();//des
    int getRawBits(void) const;
    void setRawBits(int const raw);
    private:
    int _rawValue;
    static const int _fractionalBits = 8 ; 
};
#endif