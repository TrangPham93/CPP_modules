/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:14:41 by trpham            #+#    #+#             */
/*   Updated: 2025/08/15 17:35:45 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* call the ClapTrap before the ScavTrap */
ScavTrap::ScavTrap(void): ClapTrap()
{
	std::cout << "ScavTrap constructor is called" << std::endl;
	this->setHitPoint(100);
	this->setEnergyPoint(50);
	this->setAttackDamage(20);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor is called" << std::endl;
}

ScavTrap::ScavTrap(std::string newName): ClapTrap(newName)
{
	std::cout << "ScavTrap parameterized constructor is called" << std::endl;
	this->setHitPoint(100);
	this->setEnergyPoint(50);
	this->setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
	
}

ScavTrap& ScavTrap::operator= (const ScavTrap& other)
{
	
}


void	ScavTrap::attack(const std::string& target)
{
	if (this->getEnergyPoint() > 0 && this->getHitPoint() > 0)
	{
		this->setEnergyPoint((this->getEnergyPoint()) - 1);
		std::cout << "ScavTrap " << this->getName() << " attacks " << target 
			<< ", causing " << this->getAttackDamage() << " points of damage!" 
			<< std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->getName() 
			<< " doesn't have enough energy or hit point to attack" 
			<< std::endl;
	}
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->getName() << " in Gate keeper mode" << std::endl;
}
