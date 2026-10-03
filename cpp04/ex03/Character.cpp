/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 22:03:41 by moodeh            #+#    #+#             */
/*   Updated: 2026/10/03 18:40:15 by moodeh           ###   ########.fr       */
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
	if (!head || !mat)
		return;
	tFloorNode *newNode = new tFloorNode;
	newNode->materia = mat;
	if (*head == NULL)
	{
		*head = newNode;
		return;
	}
	tFloorNode *ptr = *head;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = newNode;
	return;
}

void Character::deleteFloor(tFloorNode **head)
{
	tFloorNode *ptr;
	if (!head)
		return;
	while (*head != NULL)
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
		this->_name = other._name;//must also copy the name
		for (int i = 0; i < 4; i++)
		{
			delete _inventory[i]; // btw its ok to be NULL
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
	deleteFloor(&_floorItems); // first delete all prev materia if they exist
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
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return;
		}
	}
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
