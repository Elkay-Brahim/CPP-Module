/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:33:01 by bchifour          #+#    #+#             */
/*   Updated: 2023/09/24 12:56:24 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const & name) : _name(name), _count(0)
{
	std::cout << "Default constructor\n";
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(Character const & copy)
{
	std::cout << "Copy constructor\n";
	*this = operator=(copy);

}

Character & Character::operator=(Character const & assign)
{
	if (this != &assign)
	{
		this->_name = assign._name;
		for (int i = 0; i < 4; i++)
			*this->_inventory[i] = *assign._inventory[i];
		this->_count = assign._count;
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	if (this->_count < 4 && m != NULL && this->_inventory[this->_count] == NULL)
	{
		this->_inventory[this->_count] = m;
		this->_count++;
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && _count > idx && this->_inventory[idx] != NULL)
	{
		this->_inventory[idx] = NULL;
		this->_count--;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4	&& this->_inventory[idx] != NULL)
		this->_inventory[idx]->use(target);
}