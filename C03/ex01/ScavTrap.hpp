/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:14:44 by trpham            #+#    #+#             */
/*   Updated: 2025/08/14 16:00:57 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ClapTrap.hpp"

/* 3 modes of inheritance:
	- public: Public member of the base class will become public in the derived 
	class and protected members of the base class will become protected 
	in the derived class.
	- protected: Both public and protected members of the base class will become
	 protected in the derived class.
	- private: Both public members and protected members of the base class will 
	become private in the derived class. Private mode is the default mode 
	--> The private members in the base class cannot be directly accessed in the 
	derived class, while protected and public members can be directly accessed.*/ 
class ScavTrap : public ClapTrap
{
private:
	

public:
	/*  constructors and destructors are not inherited by the derived class, 
	but can be called from the base class in the order of inheritance*/
	ScavTrap(void);

	/* Deleting a derived class object using a pointer of base class type 
	that has a non-virtual destructor results in undefined behavior.
	As a guideline, any time you have a virtual function in a class, 
	you should immediately add a virtual destructor (even if it does nothing). 
	This way, you ensure against any surprises later.  */
	~ScavTrap();
	ScavTrap(std::string newName);

	
	// ScavTrap(const ScavTrap& other);
	// ScavTrap& operator= (const ScavTrap& other);

	/* polymorphism: in C++, we can do it at both runtime and compile time.
	For runtime polymorphism, we have to use the virtual functions. */

	void	attack(const std::string& target);
	void	guardGate();
};

