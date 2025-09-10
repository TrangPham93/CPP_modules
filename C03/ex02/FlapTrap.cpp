/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:16:21 by trpham            #+#    #+#             */
/*   Updated: 2025/09/10 13:35:32 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FlapTrap.hpp"

FlapTrap::FlapTrap(void) : ClapTrap()
{
	std::cout << "FlapTrap constructor is called" << std::endl;
	this->setHitPoint(100);
	this->setEnergyPoint(100);
	this->setAttackDamage(30);
}

FlapTrap::FlapTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FlapTrap parameterized constructor is called" << std::endl;
	this->setHitPoint(100);
	this->setEnergyPoint(100);
	this->setAttackDamage(30);
}

FlapTrap::~FlapTrap(void)
{
	std::cout << "FlapTrap destructor is called" << std::endl;
}

FlapTrap::FlapTrap(const FlapTrap& other) : ClapTrap(other)
{
	std::cout << "FlapTrap copy constructor is called" << std::endl;
}

FlapTrap& FlapTrap::operator= (const FlapTrap& other)
{
	std::cout << "FlapTrap copy assignment operator is called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

void FlapTrap::highFivesGuys(void)
{
	std::cout << "Let's high five guys" << std::endl;
}
