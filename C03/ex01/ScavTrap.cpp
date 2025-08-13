/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:14:41 by trpham            #+#    #+#             */
/*   Updated: 2025/08/13 17:43:13 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap constructor is called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor is called" << std::endl;
}

ScavTrap::ScavTrap(std::string newName)
{
	this->setName(newName);
	std::cout << "ScavTrap parameterized constructor is called" << std::endl;

}
