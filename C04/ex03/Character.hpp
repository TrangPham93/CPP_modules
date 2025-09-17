/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:24:01 by trpham            #+#    #+#             */
/*   Updated: 2025/09/17 16:15:59 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string		_name;
		AMateria*		_inventory[4];
		
	public:
		Character();
		~Character();
		Character(std::string name);
		Character(const Character& other);
		Character& operator= (const Character& other);

		std::string const & getName() const override;
		void equip(AMateria* m) override;
		void unequip(int idx) override;
		void use(int idx, ICharacter& target) override;

		AMateria*	getInvMateria(int idx);
};

