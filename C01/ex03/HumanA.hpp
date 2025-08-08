/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 21:07:34 by trpham            #+#    #+#             */
/*   Updated: 2025/08/08 12:34:56 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma	once //header file is included only once per translation unit

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
	std::string _name;
	Weapon*		_weapon;
	
public:
	HumanA(void);
	HumanA(std::string name,  Weapon& newWeapon);
	~HumanA(void);

	std::string	getName(void);
	void		setName(std::string name);
	std::string	getWeapon(void);
	void		setWeapon(Weapon& weapon);
	void		attack(void);
};

