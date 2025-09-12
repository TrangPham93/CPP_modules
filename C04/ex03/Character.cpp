/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:25:02 by trpham            #+#    #+#             */
/*   Updated: 2025/09/12 16:12:07 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	std::cout << "Character: constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

Character::~Character()
{
	std::cout << "Character: destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
}

Character::Character(std::string name)
{
	std::cout << "Character: para_constructor called" << std::endl;
	_name = name;
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

Character::Character(const Character& other)
{
	std::cout << "Character: copy constructor called" << std::endl;
	this->_name = other._name;
	for (int i = 0; i < 4; i++)
	{
		delete this->_inventory[i];
		this->_inventory[i] = (other._inventory[i]);
	}
}
Character& Character::operator= (const Character& other)
{
	std::cout << "Character: copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete this->_inventory[i];
			this->_inventory[i] = other._inventory[i];
		}
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	
	for (int i = 0; i < 4; i++)
	{
		if ((*_inventory)[i].getType().empty())
		{
			(*_inventory)[i] = *m;
			break;
		}
		if (i == 4)
		{
			std::cout << "full inventory" << std::endl;
			break;
		}
	}
}
void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	// what does it do?
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return ;
	(*_inventory)[idx].use(target);
}
