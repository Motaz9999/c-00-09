/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice2.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 16:09:19 by moodeh            #+#    #+#             */
/*   Updated: 2026/06/21 16:42:52 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;
void	printSeparator(void)
{
	cout << "--------------" << endl;
}
void	printStudentRecord(const string &name, int age, double gpa)
{
	cout << "|NAME : " << name << "\n|AGE : " << age << "\n |GPA : " << gpa << endl;
}
bool	readStudentRecord(string &name, int &age, double &gpa)
{
	cout << "Enter ur name : ";
	if (!(cin >> name))
	{
		std::cerr << "Error: failed to read name." << endl;
		return (false);
	}
	cout << "\nEnter ur age";
	if (!(cin >> age))
	{
		cerr << "Error: failed to read age" << endl;
		return (false);
	}
	std::cout << "\nEnter student gpa";
	if (!(std::cin >> gpa))
	{
		std::cerr << "Error: failed to read GPA. "
					<< "Expected a number." << std::endl;
		return (false);
	}
	return (true);
}
int	main(void)
{
	string	name;
	int		age;
	double	gpa;
	int		myInt;
	double	myDouble;
	bool	myBool;
	char	myChar;

	std::cout << "═══════════════════════════════" << std::endl;
	std::cout << "   Student Records System      " << std::endl;
	std::cout << "═══════════════════════════════" << std::endl;
	cout << "line 1 with newline " << '\n';
	cout << "line 1 with endline " << endl;
	myInt = 42;
	myDouble = 3.14159;
	myBool = true;
	myChar = 'A';
	std::cout << "int    : " << myInt << '\n' << "double : " << myDouble << '\n' << "bool   : " << myBool << '\n' << "char   : " << myChar << '\n';
	printSeparator();
	if (!readStudentRecord(name, age, gpa))
		return (1);
    printSeparator();
    printStudentRecord(name , age , gpa);
    printSeparator();
    if (gpa < 2.0)
    cerr << "WARNING: GPA below academic threshold!"<<endl;
	return (0);
}
