/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 18:51:53 by moodeh            #+#    #+#             */
/*   Updated: 2026/10/01 20:30:28 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"
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
        Cat c;//on stack

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
        std::cout <<"============================="<<std::endl;
        std::cout <<"======WrongClasses==========="<<std::endl;
        std::cout <<"============================="<<std::endl;
    {
        {
        const WrongAnimal *meta = new WrongAnimal();
        const WrongAnimal *j = new WrongDog();
        const WrongAnimal *i = new WrongCat();

        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        std::cout << meta->getType() << " " << std::endl;

        i->makeSound(); 
        j->makeSound();
        meta->makeSound();//all print some animal sound
        delete meta;
        delete j;
        delete i;
    }
    std::cout <<"============================="<<std::endl;
    {
        const WrongAnimal *meta2 = new WrongAnimal();
        const WrongAnimal *dog = new WrongDog();
        const WrongAnimal *cat = new WrongCat();

        std::cout << meta2->getType() << std::endl;
        std::cout << dog->getType() << std::endl;
        std::cout << cat->getType() << std::endl;

        meta2->makeSound();
        dog->makeSound();
        cat->makeSound();//same here

        delete meta2;
        delete dog;
        delete cat;
    }
        std::cout <<"============================="<<std::endl;

    {
        WrongAnimal a;
        WrongDog d;
        WrongCat c;

        a.makeSound();
        d.makeSound();
        c.makeSound();
        WrongAnimal *arr[3];
        arr[0] = &a;
        arr[1] = &d;
        arr[2] = &c;

        for (int i = 0; i < 3; i++)
        {
            arr[i]->makeSound();
        }
    }
    
    }
    return 0;
}
