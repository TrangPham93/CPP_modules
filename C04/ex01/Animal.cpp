/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:29:22 by trpham            #+#    #+#             */
/*   Updated: 2025/09/11 13:55:25 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal class: constructor is called" << std::endl;
	type = "None";
}

Animal::~Animal()
{
	std::cout << "Animal class: destructor is called" << std::endl;
}

Animal::Animal(std::string type)
{
	std::cout << "Animal class: parameterized constructor is called" 
		<< std::endl;
	type = type;
}

Animal::Animal(const Animal& other)
{
	std::cout << "Animal class: copy constructor is called" << std::endl;
	type = other.type;
}

Animal& Animal::operator= (const Animal& other)
{
	std::cout << "Animal class: copy assignment operator is called" 
		<< std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "The animal makes sound" << std::endl;
}

std::string	Animal::getType() const
{
	return type;
}

void Animal::setType(std::string newType)
{
	type = newType;
}