#ifndef CAT_HPP
#define CAT_HPP

// #include "Animal.hpp"
#include "AAnimal.hpp"
// class Cat : public Animal
class Cat : public AAnimal
{
	public:
		Cat();
		Cat(const std::string& name);
		~Cat();

		void makeSound() const;
};

#endif