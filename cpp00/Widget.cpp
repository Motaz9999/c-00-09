/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Widget.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:11:35 by moodeh            #+#    #+#             */
/*   Updated: 2026/06/23 14:27:56 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Widget.hpp"

//   public:
// 	Widget(const std ::string &name);
// 	~Widget(void);
// 	void printInfo(void) const;
// 	static int getInstanceCount(void);

//   private:
// 	const std::string _name;
// 	const int id;
// 	static int _instanceCount;
int Widget::_instanceCount = 0;
Widget::Widget (const std::string &name) : _name(name) , _id(_instanceCount)
{
    Widget::_instanceCount++;
    std::cout << "[+] Widget #" << this->_id << "(\""<<this->_name << "\") created" << "Total alive : " <<Widget::_instanceCount << std::endl;
}
Widget::~Widget(void)
{
        Widget::_instanceCount--;
    std::cout << "[-] Widget #" << this->_id
              << " (\"" << this->_name << "\") destroyed. "
              << "Total alive: " << Widget::_instanceCount << std::endl;
}

void Widget::printInfo(void) const 
{
    std :: cout << "Widget #"<<this->_id << " : " << this->_name << std::endl;
}

int Widget::getInstanceCount(void) 
{
    return Widget::_instanceCount;
}