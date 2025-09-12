/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:19:20 by trpham            #+#    #+#             */
/*   Updated: 2025/09/12 15:03:56 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria()
{
	std::cout << "Ice: constructor called" << std::endl;
	this->type = "ice";
}

Ice::~Ice()
{
	std::cout << "Ice: destructor called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other)
{
	std::cout << "Ice: copy constructor called" << std::endl;
}

Ice& Ice::operator= (const Ice& other)
{
	std::cout << "Ice: copy assignment operator called" << std::endl;
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}
	
Ice* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() 
		<< " *" << std::endl;
}