/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:40:14 by trpham            #+#    #+#             */
/*   Updated: 2025/09/11 20:53:36 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat class: constructor is called" << std::endl;
	type = "Cat";
	_catBrain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat class: destructor is called" << std::endl;
	delete _catBrain;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat class: copy constructor is called" << std::endl;
	_catBrain = new Brain(*other._catBrain);
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat class: copy assignment operator is called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete _catBrain;
		_catBrain = new Brain(*other._catBrain);
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Cat makes sound: meow meow" << std::endl;	
}

void	Cat::getBrain() const
{
	_catBrain->getIdeas();
}

void	Cat::setBrain(std::string idea)
{
	_catBrain->setIdeas(idea);
}