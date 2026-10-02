/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 22:03:41 by moodeh            #+#    #+#             */
/*   Updated: 2026/10/03 01:13:26 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

//   private:
// 	std::string _name; // name of character
// 	AMateria *_inventory[4];
// this character can have inventory and can put up to 4 items
// the array is a 4 pointer to diff elements
//    tFloorNode *_floorItems;
void Character::addToFloor(tFloorNode **head, AMateria *mat)
{
	tFloorNode *ptr;
	tFloorNode *newNode;

	if (head == NULL)
	{
		*head = new tFloorNode;
		(*head)->materia = mat;
		(*head)->next = NULL;
		return;
	}
	ptr = *head;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	newNode = new tFloorNode;
	newNode->materia = mat;
	newNode->next = NULL;
	ptr->next = newNode;
	newNode = NULL;
	return;
}

void Character::deleteFloor(tFloorNode **head)
{
	tFloorNode *ptr;

	while (head != NULL)
	{
		ptr = *head;
		*head = (*head)->next;
		delete ptr->materia;
		delete ptr;
	} // like this we delete the whole list
}

Character::Character() : ICharacter(), _name("unknown"), _floorItems(NULL)
{
	std::cout << "[Character] default constructor called for " << _name << std::endl;
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
}

Character::Character(const std::string &name) : ICharacter(), _name(name),
												_floorItems(NULL)
{
	std::cout << "[Character] parametrized constructor called for " << _name << std::endl;
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
}
// copy const
Character::Character(const Character &other) : ICharacter(), _name(other._name),
											   _floorItems(NULL)
{
	tFloorNode *ptr;

	std::cout << "[Character] copy constructor called for " << _name << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i] != NULL)
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	// now make new list from the list i have floor in it
	ptr = other._floorItems;
	while (ptr != NULL)
	{
		addToFloor(&_floorItems, ptr->materia->clone());
		ptr = ptr->next;
	} // now its must full copy
}

Character &Character::operator=(const Character &other)
{
	tFloorNode *ptr;

	std::cout << "[Character] copy assignment operator called for " << _name << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete _inventory[i];//btw its ok to be NULL
			_inventory[i] = NULL;
			if (other._inventory[i] != NULL)
				this->_inventory[i] = other._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
		deleteFloor(&_floorItems);
		_floorItems = NULL;
		ptr = other._floorItems;
		while (ptr != NULL)
		{
			addToFloor(&_floorItems, ptr->materia->clone());
			ptr = ptr->next;
		}
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "[Character] destructor called for " << _name << std::endl;
	deleteFloor(&_floorItems);
	for (int i = 0; i < 4; i++)
	{
		delete _inventory[i];
		_inventory[i] = NULL;
	} // all heap free
} // best practice

// now what i must implement from the other class
const std::string &Character::getName() const
{
	return _name;
}
void Character::equip(AMateria *m)
{
	int i = 0;
	while (_inventory[i] != NULL) // this to check if all slots are full
	{
		i++;
	}
	if (i == 4) // full
		return;
	_inventory[i] = m;
}
// fill the inventory from 0 to 3 until its full
void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3) // out range
		return;
	if (_inventory[idx] == NULL)
		return;
	addToFloor(&_floorItems, _inventory[idx]);
	_inventory[idx] = NULL;
}

//  from the inventory without DELETE
void Character::use(int idx, ICharacter &target)
{
	// use the inventory
	if (idx < 0 || idx > 3) // out range
		return;
	if (_inventory[idx] == NULL)
		return;
	_inventory[idx]->use(target);
}
