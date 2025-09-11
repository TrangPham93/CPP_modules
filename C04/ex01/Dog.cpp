/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:36:44 by trpham            #+#    #+#             */
/*   Updated: 2025/09/11 13:39:54 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog class: constructor is called" << std::endl;
	type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Dog class: destructor is called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog class: copy constructor is called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog class: copy assignment operator is called" << std::endl;
	Animal::operator= (other);
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Dog barks: woof woof " << std::endl;	
}
