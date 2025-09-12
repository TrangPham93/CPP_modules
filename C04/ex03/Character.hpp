/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:24:01 by trpham            #+#    #+#             */
/*   Updated: 2025/09/12 16:00:34 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria*	_inventory[4];
		
	public:
		Character();
		~Character();
		Character(std::string name);
		Character(const Character& other);
		Character& operator= (const Character& other);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

