/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 10:27:29 by trpham            #+#    #+#             */
/*   Updated: 2025/09/24 11:51:17 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title)
	:_name(name), _title(title)
{
	std::cout << this->_name << ": This looks like another boring day."
		<< std::endl;
	_spellBook = new SpellBook();
}
Warlock::~Warlock()
{
	std::cout << this->_name << ": My job here is done!" << std::endl;
	delete _spellBook;
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

void	Warlock::learnSpell(const ASpell* spell)
{
	_spellBook->learnSpell(spell);
}

void	Warlock::forgetSpell(const std::string spellName)
{
	_spellBook->forgetSpell(spellName);
}

void	Warlock::launchSpell(const std::string spellName, const ATarget& target)
{
	ASpell* newSpell = _spellBook->createSpell(spellName, target);
	if (newSpell)
		newSpell->launch(target);
	delete newSpell;
}