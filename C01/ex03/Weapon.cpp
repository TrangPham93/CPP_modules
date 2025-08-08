/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 21:07:07 by trpham            #+#    #+#             */
/*   Updated: 2025/08/08 13:02:33 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{}

Weapon::Weapon(std::string	Weapon)
{
	_type = Weapon;
}

Weapon::~Weapon(void)
{}

const std::string&	Weapon::getType(void) const
{
	return (_type);
}

void	Weapon::setType(std::string newType)
{
	_type = newType;
}

