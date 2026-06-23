/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice6.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 09:41:30 by moodeh            #+#    #+#             */
/*   Updated: 2026/06/23 12:06:30 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Reading.hpp"

void displayReading(const Reading &r)
{
    r.printSummary();
}
int main(void)
{
    Reading morning(18.5 , "Garden");
    displayReading(morning);
    const Reading frozen(-20.0, "Freezer");//must only use const funs
    frozen.printSummary();
    morning.recordAccess();
    morning.recordAccess();

        std::cout << "\nTotal access count for 'morning': "
              << morning.getAccess() << std::endl;
}