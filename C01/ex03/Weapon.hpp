/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 21:09:41 by trpham            #+#    #+#             */
/*   Updated: 2025/08/08 13:22:21 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
private:
	std::string			_type;
	
public:
	Weapon(void);
	Weapon(std::string	Weapon);
	~Weapon(void);

	/*
		Constant reference means you return a reference to the actual member variable _type, not a copy, and the caller cannot modify it because it’s const. Adding const at the end means this method promises not to modify any member variable.
		- First const = const return type → caller can’t modify.
		- Last const = const method → method won’t modify object & can be called on const objects. */
	const std::string&	getType(void) const;
	void				setType(std::string newType);
};

#endif