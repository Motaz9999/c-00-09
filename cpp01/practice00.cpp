/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice00.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 16:48:22 by moodeh            #+#    #+#             */
/*   Updated: 2026/06/27 17:31:24 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Sensor
{
  private:
	/* data */
  public:
	std::string _name;
	double _value;
	Sensor(std::string const &name, double value);
	~Sensor();
};

Sensor::Sensor(std::string const &name, double value) : _name(name),
	_value(value)
{
	std::cout << "[Sensor] '" << this->_name << "' constructed on  the " << std::endl;
}
Sensor::~Sensor()
{
	std::cout << "[Sensor] '" << this->_name << "' destroyed." << std::endl;
}

void	stackDemo(void)
{
	std::cout << "\n--- Stack Demo ---" << std::endl;
	Sensor temp("Temperature.", 21.5);
	std::cout << "stack." << std::endl;
	std::cout << "Value :" << temp._value << std::endl;
}
Sensor	*heapAlloc(void)
{
	Sensor	*s;

	std::cout << "\n--- Heap Alloc ---" << std::endl;
	s = new Sensor("Pressure", 101.3);
	std::cout << "heap." << std::endl;
	return (s); // return the pointer(the obj is on the heap)
}

// new[] delete[]
void	arrayDemo(void)
{
	int		size;
	double	*readings;

	std::cout << "\n--- Array Demo ---" << std::endl;
	size = 5;
	readings = new double[size];
	// array of doubles in heap but have ptr called readings in stack that can access the array
	for (int i = 0; i < size; i++)
	{
		readings[i] = i * 1.1;
		std::cout << "  readings[" << i << "] = " << readings[i] << std::endl;
	}
	// now we must free the heap i used after i finish using it
	delete[] readings;
	readings = NULL;
	std::cout << "  Array deleted." << std::endl;
}
int	main(void)
{
	stackDemo();
	std::cout << "(Back in main: Sensor 'Temperature' is already gone.)" << std::endl;
	Sensor *ptr = heapAlloc();                                                                 
		// still alive even if the fun end
	std::cout << "(Back in main: Sensor 'Pressure' still lives at " << ptr << ")" << std::endl;
		// print the loc in heap
	std::cout << "  Value: " << ptr->_value << std::endl;
	delete ptr;
	ptr = NULL;
	arrayDemo();
	return (0);
}