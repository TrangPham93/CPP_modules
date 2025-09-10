/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:00:07 by trpham            #+#    #+#             */
/*   Updated: 2025/09/10 19:18:04 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ScavTrap(), FragTrap() 
{
	std::cout << "DiamondTrap constructor is called" << std::endl;
	this->_name = ClapTrap::getName();
	this->setHitPoint(FragTrap::getHitPoint());
	this->setEnergyPoint(ScavTrap::getEnergyPoint());
	this->setAttackDamage(FragTrap::getAttackDamage());
}

DiamondTrap::DiamondTrap(std::string newName) : 
	ClapTrap(newName + "_clap_name")
{
	std::cout << "DiamondTrap parameterized constructor is called" << std::endl;
	this->_name = newName;
	this->setHitPoint(FragTrap::getHitPoint());
	this->setEnergyPoint(ScavTrap::getEnergyPoint());
	this->setAttackDamage(FragTrap::getAttackDamage());
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor is called" << std::endl;
}

std::string	DiamondTrap::getDiamondName()
{
	return this->_name;
}

void	DiamondTrap::attack(const std::string target)
{
	std::cout << "DiamonTrap attack" << std::endl;
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My name is " << _name 
	<< " | My ClapTrap name is " << ClapTrap::getName() << std::endl;
}