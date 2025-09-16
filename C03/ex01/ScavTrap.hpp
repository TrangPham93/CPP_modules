/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:14:44 by trpham            #+#    #+#             */
/*   Updated: 2025/09/16 12:03:35 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

/* 3 modes of inheritance:
	- public: Public member of the base class will become public in the derived 
	class and protected members of the base class will become protected 
	in the derived class.
	- protected: Both public and protected members of the base class will become
	 protected in the derived class.
	- private: Both public members and protected members of the base class will 
	become private in the derived class. Private mode is the default mode 
	--> The private members in the base class cannot be directly accessed 
	in the derived class, while protected and public members can be 
	directly accessed.*/ 
class ScavTrap : public ClapTrap
{

public:
	/*  constructors and destructors are not inherited by the derived class, 
	but can be called from the base class in the order of inheritance*/
	ScavTrap(void);

	/* polymorphism: in C++, we can do it at both runtime and compile time.
	For runtime polymorphism, we have to use the virtual functions. */
	~ScavTrap();
	ScavTrap(std::string newName);
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator= (const ScavTrap& other);

	void	attack(const std::string& target);
	void	guardGate();
};

