/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 21:07:48 by trpham            #+#    #+#             */
/*   Updated: 2025/08/08 13:12:44 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(void)
{}

HumanA::HumanA(std::string name, Weapon& newWeapon)
{	
	_name = name;
	_weapon = &newWeapon;
}

HumanA::~HumanA()
{
}

std::string	HumanA::getName(void)
{
	return (_name);
}

void	HumanA::setName(std::string name)
{
	_name = name;
}

std::string	HumanA::getWeapon(void)
{
	return (_weapon)->getType();
}

void	HumanA::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}

void	HumanA::attack(void)
{
	if (_weapon && !_weapon->getType().empty())
		std::cout << _name << " attacks with their " 
			<< _weapon->getType() << std::endl;
	else
		std::cout << _name << " has no weapon" << std::endl;
}
