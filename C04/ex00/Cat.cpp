/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:40:14 by trpham            #+#    #+#             */
/*   Updated: 2025/09/17 11:47:43 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat: constructor is called" << std::endl;
	type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Cat: destructor is called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat: copy constructor is called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat: copy assignment operator is called" << std::endl;
	Animal::operator=(other);
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Cat makes sound: meow meow" << std::endl;	
}
