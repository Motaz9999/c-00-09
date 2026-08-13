/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice02.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 21:51:28 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/13 21:52:00 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SportsCar.hpp"


int main()
{
    std::cout << "--- Entering scope: constructing a SportsCar ---" << std::endl;
    {
        SportsCar ferrari("Ferrari", 2, 340);
        std::cout << "--- SportsCar fully constructed, now in use ---" << std::endl;
    }
    std::cout << "--- Scope exited: destruction complete ---" << std::endl;
    return (0);
}