/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Widget.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:07:16 by moodeh            #+#    #+#             */
/*   Updated: 2026/06/23 14:13:58 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIDGET_HPP
# define WIDGET_HPP
# include <iostream>
# include <string>

class Widget
{
  public:
	Widget(const std ::string &name);
	~Widget(void);
	void printInfo(void) const;
	static int getInstanceCount(void);

  private:
	const std::string _name;
	const int _id;
	static int _instanceCount;
};
#endif