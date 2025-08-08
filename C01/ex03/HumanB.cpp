/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 21:08:02 by trpham            #+#    #+#             */
/*   Updated: 2025/08/08 13:13:10 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(void)
{}

HumanB::HumanB(std::string name)
{	
	_name = name;
	_weapon = nullptr;
}

HumanB::~HumanB()
{
}

std::string	HumanB::getName(void)
{
	return (_name);
}

void	HumanB::setName(std::string name)
{
	_name = name;
}

std::string	HumanB::getWeapon(void)
{
	return (_weapon->getType());
}

void	HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}

void	HumanB::attack(void)
{
	if (_weapon)
		std::cout << _name << " attacks with their " 
			<< _weapon->getType() << std::endl;
	else
		std::cout << _name << " has no weapon" << std::endl;
}
