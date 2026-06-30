/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice02.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 18:25:25 by moodeh            #+#    #+#             */
/*   Updated: 2026/06/29 23:49:22 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int x = 99;//var with memory and location in it
// int &ref = x;// ref to exact memory so act like it another name to the same var
// int *ptr = &x;//ptr is new var holding the address of another variable and when u use it you need to dereference it
// //same as int *ptr = &ref;

#include <iostream>
#include <string>

class DataPacket
{
  public:
	std::string _source;
	double _payload[64]; // copying is expensive for this array
	DataPacket(std::string const &source) : _source(source)
	{
		for (int i = 0; i < 64; i++)

			this->_payload[i] = i * 0.5;
		std::cout << "[DataPacket] '" << _source << "' constructed" << std::endl;
	}
	DataPacket(DataPacket const &other) : _source(other._source)
	{
		for (int i = 0; i < 64; i++)
			_payload[i] = other._payload[i];
		std::cout << "[DataPacket] '" << _source << "' COPY-CONSTRUCTRED. (expensive!)" << std::endl;
	}
	~DataPacket()
	{
		std::cout << "[DataPacket] '" << _source << "' destroyed" << std::endl;
	}
};
void	processByValue(DataPacket var)
{
	std::cout << "processByValue :" << var._source << std::endl;
}
void	processByConstRef(DataPacket const& var)
{
	std::cout << "ProcessByConstRef: source =" << var._source << std::endl;
}

void	renamePacket(DataPacket &packet, std::string const &newName)
{
	packet._source = newName;
	std::cout << " renamePacket : " << packet._source << std::endl;
}
void	demoAlias(void)
{
	int	x;
	int	y;

	std::cout << "\n--- Demo 1: Reference as Alias ---" << std::endl;
	x = 10;
	int &ref = x;
	std::cout << " x = " << x << " address " << &x << std::endl;
	std::cout << "ref = " << ref << "address " << &ref << std ::endl;
	ref = 99;
	std::cout << "after adding 90 to ref var \n x = " << x << " address " << &x << std::endl;
	std::cout << "ref = " << ref << "address " << &ref << std ::endl;
	y = 55;
	ref = y;
	std::cout << "after make y  and y = ref (y=55)\n x = (modified through ref)" << x << " address " << &x << std::endl;
	std::cout << " y = " << y << " address " << &y << std::endl;
	std::cout << "ref = " << ref << "address " << &ref << std ::endl;
	std::cout << "  ref still refers to x: &ref == &x is " << (&ref == &x ? "true" : "false") << std::endl;
}
void	demoEfficiency(void)
{
	std::cout << "\n--- Demo 2: Pass by Value vs. const Ref ---" << std::endl;
	DataPacket pkt("sensor7"); // on stack
	std::cout << "\n calling processByvalue :" << std::endl;
	processByValue(pkt);
	std::cout << "\n  Calling processByConstRef:" << std::endl;
	processByConstRef(pkt);
  
}
void demoModification()
{
      std::cout << "\n---- Demo 3: Modification via Reference Parameter----"<<std::endl;
    DataPacket pkt("original name");
    
    std::cout << "  Before: " << pkt._source << std::endl;
    renamePacket(pkt, "new-name");
    std::cout << "  After:  " << pkt._source << std::endl;
}
class Thermostat {
  public:
  double _temperature;
  Thermostat(double t) :_temperature(t)
  {
  }  
  double &temperature()
  {
    return _temperature;//return ref to this value so the fun name work as var to this var 
  }
  double const& temperature() const //wont change anything in this fun var  bc its const
  {
    return _temperature;
  }
};
void demoReturnRef()
{
        std::cout << "\n--- Demo 4: Returning a Reference ---" << std::endl;
        Thermostat t(20.0);
            std::cout << "  Initial temperature: " << t.temperature() << std::endl;
            t.temperature() = 25.5;
               std::cout << "  After t.temperature() = 25.5: " << t._temperature << std::endl;
}
class Character {
public:
    std::string name;
	
    Character(std::string n) : name(n) {}

    // الدالة الأولى
    void attack() {
        std::cout << name << " attacked player ⚔️\n";
    }

    // الدالة الثانية
    void defend() {
        std::cout << name << "defend player 🛡️\n";
    }
};

int	main(void)
{
	demoAlias();
	demoEfficiency();
	demoModification();
	demoReturnRef();
	std::string DataPacket::*pSource =NULL;//like this i make the ptr for class pSource for using it on str member
	pSource = &DataPacket::_source;//now its point to source from class dataPacket
	DataPacket d("ll");
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n"<<d.*pSource << std::endl;
	
	std::cout << "\n--- All demos complete. ---" << std::endl;
	Character a("ahmad");
	Character b("Youse");
	//bc all fun i have are (i want to use are have the same signature) void (Character::* actionButton)(void); 
	void (Character::* funPtrButton)();
	funPtrButton = &Character::attack;//
	//ok now i can use this ptr to do 2 differnt things
	(a.*funPtrButton)();
	(b.*funPtrButton)();//both attacked
	funPtrButton = &Character::defend;
	(a.*funPtrButton)();
	(b.*funPtrButton)();
	return (0);
}