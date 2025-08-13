/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:05:56 by trpham            #+#    #+#             */
/*   Updated: 2025/08/13 17:11:42 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	_hitPoint = 10;
	_energyPoint = 10;
	_attackDamage = 0;
	std::cout << "Constructor is called." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor is called." << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name {name}
{	
	_hitPoint = 10;
	_energyPoint = 10;
	_attackDamage = 0;
	std::cout << "Parameterized constructor is called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	this->_name = other._name;
	this->_hitPoint = other._hitPoint;
	this->_energyPoint = other._energyPoint;
	this->_attackDamage = other._attackDamage;
	std::cout << "Copy constructor is called." << std::endl;
}

ClapTrap& ClapTrap::operator= (const ClapTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoint = other._hitPoint;
		this->_energyPoint = other._energyPoint;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoint > 0 && this->_hitPoint > 0)
	{
		this->_energyPoint--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target 
			<< ", causing " << this->_attackDamage << " points of damage!" 
			<< std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name 
			<< " doesn't have enough energy or hit point to attack" 
			<< std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount <= 0)
		throw std::out_of_range("takeDamage must be in range positive");
	if (this->_hitPoint >= amount)
	{
		std::cout << "ClapTrap " << this->_name << " take " 
			<< amount << " damage!" << std::endl;
		this->_hitPoint -= amount;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " has " 
			<< this->_hitPoint<< " hit points "
			<< ", can take " << this->_hitPoint << " more damages!" 
			<< std::endl;
		this->_hitPoint -= this->_hitPoint;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (amount <= 0)
		throw std::out_of_range("beRepaired must be positive]");
	if (this->_energyPoint > 0 && this->_hitPoint > 0)
	{
		this->_energyPoint--;
		this->_hitPoint += amount;
		std::cout << "ClapTrap " << this->_name << " repaired itself, " 
			<< " getting " << amount << " hit point back!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name 
			<< " doesn't have enough energy or hit point to be repaired "
			<< this->_energyPoint << std::endl;
	}
}

std::string ClapTrap::getName(void)
{
	return _name;
}

void ClapTrap::setName(std::string newName)
{
	std::cout << "Set name: " << newName << std::endl;
	_name = newName;
}
unsigned int	ClapTrap::getHitPoint(void)
{
	return _hitPoint;
}
unsigned int	ClapTrap::getEnergyPoint(void)
{
	return _energyPoint;
}
unsigned int	ClapTrap::getAttackDamage(void)
{
	return _attackDamage;
}
void	ClapTrap::setAttackDamage(int newAttackDamage)
{
	if (newAttackDamage < 0 || newAttackDamage > 10)
		throw std::out_of_range("set AttackDamage is in range [0, 10]");
	std::cout << "Set attack damage: " << newAttackDamage << std::endl;
	_attackDamage = newAttackDamage;
}