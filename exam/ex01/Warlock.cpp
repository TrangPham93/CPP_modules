/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 10:27:29 by trpham            #+#    #+#             */
/*   Updated: 2025/09/23 17:57:19 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title)
{
	_name = name;
	_title = title;	
	std::cout << this->_name << ": This looks like another boring day."
		<< std::endl;
}
Warlock::~Warlock()
{
	std::cout << this->_name << ": My job here is done!" << std::endl;
}

Warlock::Warlock(const Warlock& other)
{
	_title = other._title;
	_name = other._name;
}

Warlock& Warlock::operator= (const Warlock& other)
{
	std::cout << _name << "copy \n";
	if (this != &other)
	{
		_name = other._name;
		_title = other._title;
	}
	return (*this);	
}

		
std::string Warlock::getName() const
{
	return _name;
}

std::string	Warlock::getTitle() const
{
	return _title;
}

void	Warlock::setTitle( const std::string& title)
{
	_title = title;
}

void	Warlock::introduce() const
{
	std::cout << this->_name << ": I am " << this->_name 
		<< ", " << this->_title << " !" << std::endl;
}

