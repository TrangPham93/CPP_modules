/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:48:26 by trpham            #+#    #+#             */
/*   Updated: 2025/09/12 13:18:30 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria: constructor called" << std::endl;
	this->type = "none";
}

AMateria::~AMateria()
{
	std::cout << "AMateria: destructor called" << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	std::cout << "AMateria: parameterized constructor called" << std::endl;
	this->type = type;

}

AMateria::AMateria(const AMateria& other)
{
	std::cout << "AMateria: copy constructor called" << std::endl;
	this->type = other.type;
}

AMateria& AMateria::operator= (const AMateria& other)
{
	std::cout << "AMateria: copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

std::string const & AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter& target)
{
	// 
}