#ifndef ROBOT_HPP
# define ROBOT_HPP
// #include "Animal.hpp"
// class Robot : public Animal
# include "AAnimal.hpp"
# include "ISerializable.hpp"
class Robot : public AAnimal, public ISerializable
{
  private:
	int *_batteryLog; // spacial attribute on HEAP btw
  protected:
  public:
	Robot();
	Robot(const std::string &name);
	Robot(const Robot &obj);
	Robot& operator=(const Robot &obj);
	~Robot();
	virtual void makeSound() const;
	virtual std::string serialize() const;
	virtual AAnimal* clone() const;
};
#endif