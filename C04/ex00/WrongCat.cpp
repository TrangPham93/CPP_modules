/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:07:19 by trpham            #+#    #+#             */
/*   Updated: 2025/09/11 14:15:22 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat class: constructor is called" << std::endl;
	type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat class: destructor is called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WrongCat class: copy constructor is called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat class: copy assignment operator is called" << std::endl;
	WrongAnimal::operator=(other);
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat makes sound: meow meow" << std::endl;	
}