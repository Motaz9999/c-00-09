/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 21:26:24 by moodeh            #+#    #+#             */
/*   Updated: 2026/10/03 00:05:00 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "Cure.hpp"
# include "ICharacter.hpp"
# include "Ice.hpp"
// for crating a linked list cus i cant direct free the item
typedef struct sFloorNode
{
	AMateria	*materia;
	tFloorNode	*next;
}				tFloorNode;

class Character : public ICharacter
{
  private:
	std::string _name; // name of character
	AMateria *_inventory[4];
	// this character can have inventory and can put up to 4 items
	// the array is a 4 pointer to diff elements
	tFloorNode *_floorItems;
	void addToFloor(tFloorNode **head, AMateria *mat);
		// helper fun for linked list
	void deleteFloor(tFloorNode **head);

  protected:
  public:
	Character();
	Character(const std::string &name);
	Character(const Character &other);
	Character &operator=(const Character &other);
	virtual ~Character(); // best practice

	// now what i must implement from the other class
	virtual const std::string &getName() const; // no = 0
	virtual void equip(AMateria *m);
	// fill the inventory from 0 to 4 until its full
	virtual void unequip(int idx);
	//  from the inventory without DELETE
	virtual void use(int idx, ICharacter &target);
	// its the same use as in AMateria but plus index
	// next step
};
#endif