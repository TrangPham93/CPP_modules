/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:10:55 by trpham            #+#    #+#             */
/*   Updated: 2025/09/11 14:13:58 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal class: constructor is called" << std::endl;
	type = "None";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal class: destructor is called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	std::cout << "WrongAnimal class: parameterized constructor is called" 
		<< std::endl;
	type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "WrongAnimal class: copy constructor is called" << std::endl;
	type = other.type;
}

WrongAnimal& WrongAnimal::operator= (const WrongAnimal& other)
{
	std::cout << "WrongAnimal class: copy assignment operator is called" 
		<< std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "The WrongAnimal makes sound" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::setType(std::string newType)
{
	type = newType;
}