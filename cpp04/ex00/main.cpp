#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    {
        const Animal *meta = new Animal();
        const Animal *j = new Dog();
        const Animal *i = new Cat();

        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        std::cout << meta->getType() << " " << std::endl;

        i->makeSound(); // will output the cat sound!
        j->makeSound();
        meta->makeSound();
        delete meta;
        delete j;
        delete i;
    }
    std::cout <<"============================="<<std::endl;
    {
        const Animal *meta2 = new Animal();
        const Animal *dog = new Dog();
        const Animal *cat = new Cat();

        std::cout << meta2->getType() << std::endl;
        std::cout << dog->getType() << std::endl;
        std::cout << cat->getType() << std::endl;

        meta2->makeSound();
        dog->makeSound();
        cat->makeSound();

        delete meta2;
        delete dog;
        delete cat;
    }
        std::cout <<"============================="<<std::endl;

    {
        Animal a;
        Dog d;
        Cat c;

        a.makeSound();
        d.makeSound();
        c.makeSound();
        Animal *arr[3];
        arr[0] = &a;
        arr[1] = &d;
        arr[2] = &c;

        for (int i = 0; i < 3; i++)
        {
            arr[i]->makeSound();
        }
        
    }
    return 0;
}
