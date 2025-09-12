/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:20:11 by trpham            #+#    #+#             */
/*   Updated: 2025/09/12 15:05:38 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria()
{
	std::cout << "Cure: constructor called" << std::endl;
	this->type = "cure";
}

Cure::~Cure()
{
	std::cout << "Cure: destructor called" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other)
{
	std::cout << "Cure: copy constructor called" << std::endl;
}

Cure& Cure::operator= (const Cure& other)
{
	std::cout << "Cure: copy assignment operator called" << std::endl;
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}
	
Cure* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}