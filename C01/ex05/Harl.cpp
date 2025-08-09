/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:19:43 by trpham            #+#    #+#             */
/*   Updated: 2025/08/09 15:13:43 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	funcArr[0] = &Harl::debug;
	funcArr[1] = &Harl::info;
	funcArr[2] = &Harl::warning;
	funcArr[3] = &Harl::error;
}

Harl::~Harl()
{
}

void Harl::debug( void )
{
	std::cout << "DEBUG: 🐞🪲🐛👾" << std::endl;
}
void Harl::info( void )
{
	std::cout << "INFO: 🚀🚁🚂🚃🚄 " << std::endl;
}

void Harl::warning( void )
{
	std::cout << "WARNING: ⚠️❗⚠️❗ " << std::endl;
}

void Harl::error( void )
{
	std::cout << "ERROR: ❌❌❌❌ " << std::endl;
}

/* 
	A function pointer is a variable that stores the address of a function.
	A function pointer to a normal function: void (*ptr)() = &func1;
	A function pointer to class member function: void (ClassName::*ptr)() = &ClassName::func1;
	Call and bind rule :: obj.*funcArr or this->*funcArr;
	Local variable declared inside function but not in class: void		(Harl::*funcArr[4])(void) = {&Harl::debug, ... };
*/
void Harl::complain( std::string level )
{
	std::string	arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (int i = 0; i < 4; i++)
	{
		if (level == arr[i])
			(this->*funcArr[i])();
	}
}

