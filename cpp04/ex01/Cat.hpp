#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain *_brain;//this is on heap    
public:
    Cat();
    Cat(const std::string &type);
    Cat(const Cat &other);
    Cat &operator=(const Cat &other);
    virtual ~Cat();

     virtual void makeSound(void) const;//must rewite it if i want it to make another thinges here
};

#endif