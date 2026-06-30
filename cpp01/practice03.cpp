/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice03.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 13:09:16 by moodeh            #+#    #+#             */
/*   Updated: 2026/06/30 14:25:22 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Vector2D
{
  public:
	double _x, _y;
	Vector2D(double x, double y) : _x(x), _y(y)
	{
	}
};
void	demoMemberData(void)
{
	Vector2D	*ptrToVar;

	std::cout << "\n--- Demo 1: Pointer to Member Data ---" << std::endl;
	double Vector2D::*memPtr;
	memPtr = &Vector2D::_x;
	Vector2D v(3.0, 4.0);
	ptrToVar = &v;
	std::cout << " Accessing x via member pointer (object): " << v.*memPtr << std::endl;
	std::cout << " Accessing x via member pointer (pointer): " << ptrToVar->*memPtr << std::endl;
	std::cout << "now After making memPtr = &Vector2D::_y it will print y on the same exact call \n";
	memPtr = &Vector2D::_y;
	std::cout << " Accessing y via member pointer (object): " << v.*memPtr << std::endl;
	std::cout << " Accessing y via member pointer (pointer): " << ptrToVar->*memPtr << std::endl;
	std::cout << "now After adjusting the value from the ptr to member  v.*memPtr = 77; \n";
	v.*memPtr = 77;
	std::cout << " Accessing y via member pointer (object): " << v.*memPtr << std::endl;
	std::cout << " Accessing y via member pointer (pointer): " << ptrToVar->*memPtr << std::endl;
}
class Transmitter
{
  public:
	std::string _id;
	Transmitter(std::string const &id) : _id(id)
	{
	}
	void sendAck() const
	{
		std::cout << "[" << this->_id << "] sending ACK" << std::endl;
	}
	void sendNak() const
	{
		std::cout << "[" << this->_id << "] sending NAK" << std::endl;
	}
	void sendPing() const
	{
		std::cout << " [" << _id << "] Sending PING" << std::endl;
	}
};
void	demoMemberFunction(void)
{
	Transmitter	*tp;

	std::cout << "\n--- Demo 2: Pointer to Member Function ---" << std::endl;
	void (Transmitter::*signal)(void) const = NULL;
	signal = &Transmitter::sendAck;
	Transmitter t("TX-01");
	tp = &t;
	(t.*signal)();
	(tp->*signal)();
	signal = &Transmitter::sendNak;
	(t.*signal)();
	(tp->*signal)();
	signal = &Transmitter::sendPing;
	(t.*signal)();
}

class Harl
{
  public:
	void debug() const
	{
		std::cout << "  [DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	}
	void info() const
	{
		std::cout << "  [INFO] I cannot believe adding extra bacon costs more money!" << std::endl;
	}
	void warning() const
	{
		std::cout << "  [WARNING] I think I deserve to have some extra bacon for free." << std::endl;
	}
	void error() const
	{
		std::cout << "  [ERROR] This is unacceptable. I want to speak to the manager." << std::endl;
	}
	void complain(std::string const &level)
	{
		std::string const levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
		void (Harl::*reaction[4])() const = {&Harl::debug , &Harl::info , &Harl::warning , &Harl::error};
		for (int i = 0; i < 4; i++)
		{
			if (levels[i] == level){
				(this->*reaction[i])(); // it call the fun from its ptr
			return ;}
		}
		std::cout << "  [UNKNOWN] Harl doesn't know what to say about '" << level << "'." << std::endl;
	}
};
void	demoDispatchTable(void)
{
	Harl	harl;

	std::cout << "\n--- Demo 3: Dispatch Table (Harl Pattern) ---" << std::endl;
	harl.complain("DEBUG");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("INFO");
	harl.complain("SILENT");
}
void	applyToAll(Transmitter *group, int count,
		void (Transmitter::*action)() const)
{
	for (int i = 0; i < count; i++)
	{
		(group[i].*action)();
	}
}
void	demoPassingMemberPtr(void)
{
	Transmitter	group[3] = {Transmitter("TX-A"), Transmitter("TX-B"),
			Transmitter("TX-C")};

	std::cout << "\n--- Demo 4: Member Function Pointer as Argument ---" << std::endl;
	std::cout << "  Broadcasting ACK to all transmitters:" << std::endl;
	applyToAll(group, 3, &Transmitter::sendAck);
	std::cout << "  Broadcasting PING to all transmitters:" << std::endl;
	applyToAll(group, 3, &Transmitter::sendAck);
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
