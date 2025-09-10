/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:05:53 by trpham            #+#    #+#             */
/*   Updated: 2025/09/10 11:46:47 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ClapTrap
{
private:
	std::string		_name;
	unsigned int	_hitPoint;
	unsigned int	_energyPoint;
	unsigned int	_attackDamage;
	
public:
	ClapTrap(void);
	ClapTrap(std::string name);
	/* Deleting a derived class object using a pointer of base class type 
	that has a non-virtual destructor results in undefined behavior.
	As a guideline, any time you have a virtual function in a class, 
	you should immediately add a virtual destructor (even if it does nothing). 
	This way, you ensure against any surprises later.  */
	virtual ~ClapTrap();
	ClapTrap(const ClapTrap &other);
	ClapTrap& operator= (const ClapTrap &other);

	void			attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

	std::string 	getName(void);
	void			setName(std::string newName);
	unsigned int	getHitPoint(void);
	void			setHitPoint(int	newHitPoint);
	unsigned int	getEnergyPoint(void);
	void			setEnergyPoint(int	newEnergyPoint);
	unsigned int	getAttackDamage(void);
	void			setAttackDamage(int newAttackDamage);
};


