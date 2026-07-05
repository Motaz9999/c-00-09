/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 17:53:50 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/05 18:35:42 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"

int	main(void)
{
    Harl m;
    m.complain("DEBUG");
    m.complain("ERROR");
    m.complain("WARNING");
    m.complain("de");
    m.complain("INFO");
    return 0;
}