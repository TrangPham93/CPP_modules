/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 21:08:09 by trpham            #+#    #+#             */
/*   Updated: 2025/08/08 12:30:36 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
private:
	std::string _name;
	Weapon*		_weapon;
	
public:
	HumanB(void);
	HumanB(std::string name);
	~HumanB(void);

	std::string	getName(void);
	void		setName(std::string name);
	std::string	getWeapon(void);
	void		setWeapon(Weapon& weapon);
	void		attack(void);
};
