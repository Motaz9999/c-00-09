#include <iostream>
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"

void printHeader(const std::string &title)
{
    std::cout << "\n======================================" << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << "======================================" << std::endl;
}
void printLine(void)
{
    std::cout << "=============================================================" << std::endl;
}

int main()
{

    printHeader("1. SUBJECT MANDATORY TEST");
    {
        IMateriaSource *src = new MateriaSource(); // interface pointer to class obj//the interface base to class
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        printLine();
        ICharacter *me = new Character("me");
        AMateria *tmp; // pointer not obj on stack
        printLine();
        tmp = src->createMateria("ice");  // make a clone and give it to the tmp
        me->equip(tmp);                   // give him materia
        tmp = src->createMateria("cure"); // new one materia
        me->equip(tmp);                   // give him materia
        printLine();
        ICharacter *bob = new Character("bob");
        printLine();
        me->use(0, *bob);
        me->use(1, *bob);
        printLine();
        delete bob;
        delete me;
        delete src;
        printLine();
    }

    printHeader("2. MATERIASOURCE CAPACITY & UNKNOWN TYPES");
    {
        IMateriaSource *src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        printLine();
        AMateria *extra = new Ice();
        src->learnMateria(extra); // cant add more
        printLine();
        AMateria *unknown = src->createMateria("fire");
        if (unknown == NULL)
            std::cout << "[SUCCESS] Correctly returned NULL for unknown Materia 'fire'." << std::endl;
        printLine();
        delete src;
        printLine();
    }
    printHeader("3. INVENTORY LIMITS & NULL EQUIP");
    {
        ICharacter *cloud = new Character("Cloud");
        ICharacter *enemy = new Character("Sephiroth");
        printLine();

        cloud->equip(NULL);
        printLine();

        AMateria *m0 = new Ice();
        AMateria *m1 = new Cure();
        AMateria *m2 = new Ice();
        AMateria *m3 = new Cure();
        AMateria *m4 = new Ice();
        printLine();

        cloud->equip(m0);
        cloud->equip(m1);
        cloud->equip(m2);
        cloud->equip(m3);
        cloud->equip(m4); // cant do shit here
        printLine();
        delete m4;
        printLine();
        cloud->use(0, *enemy); // ice
        cloud->use(1, *enemy); // cure
        cloud->use(2, *enemy); // ice
        cloud->use(3, *enemy); // cure
        printLine();
        cloud->use(-1, *enemy); // out of bounds
        cloud->use(4, *enemy);
        cloud->use(10, *enemy);
        printLine();
        delete enemy;
        delete cloud;
        printLine();
    }
    printHeader("4. UNEQUIP & FLOOR HANDLING");
    {
        ICharacter *tifa = new Character("Tifa");
        ICharacter *target = new Character("Target");
        printLine();
        AMateria *mat = new Ice();
        tifa->equip(mat);
        tifa->use(0, *target);
        printLine();
        tifa->unequip(0);
        printLine();
        tifa->use(0, *target); // nothing happens
        printLine();
        tifa->unequip(0);
        tifa->unequip(-5);
        tifa->unequip(42);
        printLine();
        delete target;
        delete tifa;
        printLine();
    }
    printHeader("5. DEEP COPY VERIFICATION (NO SHALLOW COPY)");
    {
        Character *original = new Character("Original");
        original->equip(new Ice());
        original->equip(new Cure());
        printLine();

        Character *copyConstructed = new Character(*original);
        printLine();

        Character assigned("Assigned");
        assigned.equip(new Ice());
        assigned = *original;
        printLine();
        delete original;
        printLine();
        ICharacter *dummy = new Character("Dummy");
        std::cout << "-- Testing Copy Constructed Character after original deletion --" << std::endl;
        copyConstructed->use(0, *dummy);
        copyConstructed->use(1, *dummy);
        printLine();
        std::cout << "-- Testing Assigned Character after original deletion --" << std::endl;
        assigned.use(0, *dummy);
        assigned.use(1, *dummy); // same as copy
        printLine();

        delete dummy;
        delete copyConstructed;
        printLine();
    }

    printHeader("ALL TESTS COMPLETED SUCCESSFULLY");
    return 0;
}