#ifndef CAT_HPP
#define CAT_HPP

// #include "Animal.hpp"
#include "AAnimal.hpp"
#include "ISerializable.hpp"
// class Cat : public Animal
class Cat : public AAnimal , public ISerializable
{
	public:
		Cat();
		Cat(const std::string& name);
		~Cat();

		void makeSound() const;
		virtual std::string serialize() const ;

};

#endif