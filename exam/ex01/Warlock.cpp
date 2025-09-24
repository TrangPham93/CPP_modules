/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 10:27:29 by trpham            #+#    #+#             */
/*   Updated: 2025/09/23 21:01:56 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title)
{
	_name = name;
	_title = title;	
	std::cout << this->_name << ": This looks like another boring day."
		<< std::endl;
	for (int i= 0; i < 100; i++)
	{
		_spellBook[i] = nullptr;
	}
}
Warlock::~Warlock()
{
	std::cout << this->_name << ": My job here is done!" << std::endl;
	for (int i= 0; i < 100; i++)
	{
		delete _spellBook[i];
	}
}

// Warlock::Warlock(const Warlock& other)
// {
// 	_title = other._title;
// 	_name = other._name;
// }

// Warlock& Warlock::operator= (const Warlock& other)
// {
// 	std::cout << _name << "copy \n";
// 	if (this != &other)
// 	{
// 		_name = other._name;
// 		_title = other._title;
// 	}
// 	return (*this);	
// }

		
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

void	Warlock::learnSpell(const ASpell* spell)
{
	for (int i= 0; i < 100; i++)
	{
		if (_spellBook[i] != nullptr)
		{
			if (_spellBook[i]->getName() == spell->getName())
				return;
		}
	}
	for (int i= 0; i < 100; i++)
	{
		if (_spellBook[i] == nullptr)
		{
			_spellBook[i] = spell->clone();
			return;
		}
	}
}

void	Warlock::forgetSpell(const std::string spellName)
{
	for (int i= 0; i < 100; i++)
	{
		if (_spellBook[i] != nullptr 
			&& _spellBook[i]->getName() == spellName)
		{
			delete _spellBook[i];
			_spellBook[i] = nullptr;
			return;
		}
	}
}

void	Warlock::launchSpell(const std::string spellName, const ATarget& target)
{
	for (int i= 0; i < 100; i++)
	{
		if (_spellBook[i] != nullptr 
			&& _spellBook[i]->getName() == spellName)
		{
			_spellBook[i]->launch(target);
			return;
		}
	}
}