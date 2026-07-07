/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrokenString.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 17:51:10 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/07 18:04:04 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BROKENSTRING_HPP
#define BROKENSTRING_HPP
#include <string>
#include <iostream>
class BrokenString
{
private:
    char *_data;
    int _size;
public:
    BrokenString(std::string const & content);
    ~BrokenString();//have free for ptr
    
    std::string getContent(void) const;
    void overwriteFirstChar(char c);//write on the _data
    void print(std::string const & label) const;
    //no copy constructor  ->      BrokenString(BrokenString &b);
    //no copy assignment -> a = b;
    
};
#endif