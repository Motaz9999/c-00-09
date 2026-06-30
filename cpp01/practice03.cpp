/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice03.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 13:09:16 by moodeh            #+#    #+#             */
/*   Updated: 2026/06/30 13:16:07 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Vector2D
{
    public:
    double _x , _y ;
    Vector2D(double x , double y ) :_x(x) , _y(y){} 
};
void demoMemberData()
{
    std::cout << "\n--- Demo 1: Pointer to Member Data ---" << std::endl;
    
    double Vector2D::*memPtr ;
    memPtr = &Vector2D::_x;
    Vector2D v(3.0, 4.0);
    Vector2D *ptrToVar = &v;
    std::cout << " Accessing x via member pointer (object): " << v.*memPtr<<std::endl;
    std::cout <<" Accessing x via member pointer (pointer): "<<ptrToVar->*memPtr<<std::endl;
    std::cout << "now After making memPtr = &Vector2D::_y it will print y on the same exact call \n"
}
int	main(void)
{
	demoMemberData();
	demoMemberFunction();
	demoDispatchTable();
	demoPassingMemberPtr();
	std::cout << "\n--- All demos complete. ---" << std::endl;
	return (0);
}
