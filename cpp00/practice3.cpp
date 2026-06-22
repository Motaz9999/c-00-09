/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice3.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:27:13 by moodeh            #+#    #+#             */
/*   Updated: 2026/06/22 15:16:53 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BankAccount.hpp"

int	main(void)
{
	std ::cout << " create accs \n";
	BankAccount alice("Alice", 1000.0);
	BankAccount bob("Bob", 300.0);

	std::cout << "\n── Normal operations ──────────────────────" << std::endl;

	alice.deposit(250.0);
	alice.withdraw(100.0);
	alice.printStatement();

	std::cout << "\n── Error cases ────────────────────────────" << std::endl;

	// Attempt to withdraw more than available
	bob.withdraw(1000.0);

	// Attempt to deposit a negative amount
	bob.deposit(-50.0);

	// Attempt to deposit zero
	bob.deposit(0.0);

	bob.printStatement();

	std::cout << "\n── Using getters ──────────────────────────" << std::endl;

	std::cout << "Alice's owner  : " << alice.getOwner() << std::endl;
	std::cout << "Alice's balance: " << alice.getBalance() << std::endl;
	return (0);
}