/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 12:27:03 by moodeh            #+#    #+#             */
/*   Updated: 2026/06/21 12:47:55 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using std::cout;
using std::endl;
namespace Mathlib
{
struct		Vector
{
	double	x;
	double	y;
};
double	clamp(double value, double min, double max)
{
	cout << "[MathLib] Clamping value: " << value << endl;
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}
void	printVector(const Vector &v)
{
	cout << "MathLib::vector (" << v.x << "," << v.y << ")\n";
}
} // namespace Mathlib

namespace PhysicsLib
{
struct		Vector
{
	double x, y, z;
};
double	clamp(double force, double min, double max)
{
	cout << "[PhysicsLib] Clamping force: " << force << std::endl;
	if (force < min)
		return (min);
	if (force > max)
		return (max);
	return (force);
}
void	printVector(Vector &v)
{
	cout << "Physics ::Vector (" << v.x << " ," << v.y << "," << v.z << ")\n";
}
} // namespace PhysicsLib
namespace MyProject
{
namespace Config
{
const int	MAX_OBJECTS = 100;
void	printConfig(void)
{
	std::cout << "MyProject::Config — MAX_OBJECTS: " << MAX_OBJECTS << std::endl;
}
} // namespace Config

} // namespace MyProject

int	main(void)
{
	double	mathResolute;
	double	physResult;

	Mathlib::Vector mathVec;
	mathVec.x = 0.0;
	mathVec.y = 1.1;
	Mathlib::printVector(mathVec);
	mathResolute = Mathlib::clamp(150.0, 0.0, 100.0);
	cout << "Math ::clamp res" << mathResolute << endl;
	PhysicsLib::Vector phyVec;
	phyVec.x = 1.0;
	phyVec.y = 2.0;
	phyVec.z = 1.0;
	PhysicsLib::printVector(phyVec);
	physResult = PhysicsLib::clamp(250.0, 0.0, 200.0);
	std::cout << "PhysicsLib::clamp(250, 0, 200) = " << physResult << std::endl;

    MyProject::Config::printConfig();
    //if the name spaces inside this file i can use it direct
    cout<<MyProject::Config::MAX_OBJECTS;
    {
        using Mathlib::clamp;
        double r = clamp(42.5 , 0.0 , 30.0);
                std::cout << "Scoped clamp result: " << r << std::endl;

    }
	return (0);
}
