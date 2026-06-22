/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice4.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 19:02:28 by moodeh            #+#    #+#             */
/*   Updated: 2026/06/22 19:14:36 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

void innerScope(void)
{
    std :: cout << "\n== Inner Scope ==" << std :: endl;
    Logger temp("temp");
    temp.doSomething();
    std :: cout << "\n== finish Inner Scope == "<< std :: endl;
}

int main(void)
{
    std ::cout << "== main() starts ==" << std ::endl;
    Logger a;
    Logger b("first");
    Logger c("second");
    a.doSomething();
    b.doSomething();
    c.doSomething();
    innerScope();
    a.doSomething();
    return 0;
}
