#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>
class Animal
{
  private :
  protected:
  std::string _name;
  public:
	Animal();
	Animal(const std::string &name);
	// ~Animal(); old
	virtual ~Animal();//cus we can use the poly

	std::string getName() const;
//	void makeSound() const;

	virtual void makeSound() const;//this update from the original
};
#endif