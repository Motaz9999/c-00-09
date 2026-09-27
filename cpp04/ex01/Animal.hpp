#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
protected:
    std::string _type;

public:
    Animal();
    Animal(const std::string &type);
    Animal(const Animal &other);
    Animal &operator=(const Animal &other);
    virtual ~Animal();

    std::string getType() const; //there is no need to make this function virtual since it does not need to be overridden in derived classes
    virtual void makeSound() const;
};

#endif