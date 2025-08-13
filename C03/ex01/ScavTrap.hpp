/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:14:44 by trpham            #+#    #+#             */
/*   Updated: 2025/08/13 17:42:14 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ClapTrap.hpp"

/* 3 modes of inheritance:
	- public: Public member of the base class will become public in the derived class and protected members of the base class will become protected in the derived class.
	- protected: Both public and protected members of the base class will become protected in the derived class.
	- private: Both public members and protected members of the base class will become private in the derived class. Private mode is the default mode 
The private members in the base class cannot be directly accessed in the derived class, while protected and public members can be directly accessed.*/ 
class ScavTrap : public ClapTrap
{
private:
	

public:
	ScavTrap(void);
	~ScavTrap();
	ScavTrap(std::string newName);
};

