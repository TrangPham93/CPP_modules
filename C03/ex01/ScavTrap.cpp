/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:14:41 by trpham            #+#    #+#             */
/*   Updated: 2025/08/13 22:26:27 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

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

// ScavTrap::ScavTrap(const ScavTrap& other)
// {
	
// }

// ScavTrap& ScavTrap::operator= (const ScavTrap& other)
// {
	
// }


