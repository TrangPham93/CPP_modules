/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:16:21 by trpham            #+#    #+#             */
/*   Updated: 2025/09/10 21:04:39 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap constructor is called" << std::endl;
	this->setHitPoint(100);
	this->setEnergyPoint(100);
	this->setAttackDamage(30);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap parameterized constructor is called" << std::endl;
	this->setHitPoint(100);
	this->setEnergyPoint(100);
	this->setAttackDamage(30);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor is called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor is called" << std::endl;
	this->setHitPoint(other.getHitPoint());
	this->setEnergyPoint(other.getEnergyPoint());
	this->setAttackDamage(other.getAttackDamage());
}

FragTrap& FragTrap::operator= (const FragTrap& other)
{
	std::cout << "FragTrap copy assignment operator is called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->setHitPoint(other.getHitPoint());
		this->setEnergyPoint(other.getEnergyPoint());
		this->setAttackDamage(other.getAttackDamage());
	}
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "Let's high five guys" << std::endl;
}
