#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

//cus AMateria is abs class and base class for this class
class Cure : public AMateria
{
private:
protected:
public:
    Cure();//def
    Cure(const std::string & type);
    Cure(const Cure &other);
    Cure& operator=(const Cure &other);
    virtual ~Cure();//must be virtual best practice

    //now what it inherit from base class
    virtual AMateria* clone() const ;
    virtual void use(ICharacter & target);
};
#endif