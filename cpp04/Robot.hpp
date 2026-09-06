#ifndef ROBOT_HPP
# define ROBOT_HPP

#include "Animal.hpp"
class Robot : public Animal
{
    private:
    int *_batteryLog;//spacial attribute on HEAP btw
    protected:
    public:
    	Robot();
		Robot(const std::string& name);
		~Robot();
    virtual void makeSound() const ;
}; 
#endif