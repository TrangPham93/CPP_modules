/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:00:07 by trpham            #+#    #+#             */
/*   Updated: 2025/09/10 21:01:42 by trpham           ###   ########.fr       */
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

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "DiamondTrap copy constructor is called" << std::endl;
	this->_name = other._name;
	this->setHitPoint(other.getHitPoint());
	this->setEnergyPoint(other.getEnergyPoint());
	this->setAttackDamage(other.getAttackDamage());
}

DiamondTrap&	DiamondTrap::operator= (const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		_name = other._name;
		this->setHitPoint(other.getHitPoint());
		this->setEnergyPoint(other.getEnergyPoint());
		this->setAttackDamage(other.getAttackDamage());
	}
	return *this;
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