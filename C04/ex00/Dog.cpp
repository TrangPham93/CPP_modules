/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:36:44 by trpham            #+#    #+#             */
/*   Updated: 2025/09/17 11:50:27 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog: constructor is called" << std::endl;
	type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Dog: destructor is called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog: copy constructor is called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog: copy assignment operator is called" << std::endl;
	Animal::operator= (other);
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Dog barks: woof woof " << std::endl;	
}
