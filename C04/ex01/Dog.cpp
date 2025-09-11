/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:36:44 by trpham            #+#    #+#             */
/*   Updated: 2025/09/11 20:40:17 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog class: constructor is called" << std::endl;
	type = "Dog";
	_dogBrain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog class: destructor is called" << std::endl;
	delete _dogBrain;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog class: copy constructor is called" << std::endl;
	_dogBrain = new Brain(*other._dogBrain);
}

/* 
delete and reallocate to guarantees a fresh copy, even if 
_dogBrain was uninitialized (deference unititialized will cause undefined).*/
Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog class: copy assignment operator is called" << std::endl;
	if (this != &other)
	{
		Animal::operator= (other);
		delete _dogBrain;
		_dogBrain = new Brain(*other._dogBrain);
	}
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Dog barks: woof woof " << std::endl;	
}

void	Dog::getBrain() const
{
	_dogBrain->getIdeas();
}

void	Dog::setBrain(std::string idea)
{
	_dogBrain->setIdeas(idea);
}