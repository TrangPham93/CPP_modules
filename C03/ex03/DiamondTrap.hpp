/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:00:27 by trpham            #+#    #+#             */
/*   Updated: 2025/09/10 19:12:03 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string	_name;
	
public:
	DiamondTrap(void);
	DiamondTrap(std::string newName);
	~DiamondTrap();

	std::string	getDiamondName(void);
	void		attack(const std::string target);
	void		whoAmI();
};
