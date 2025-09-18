/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 17:14:30 by trpham            #+#    #+#             */
/*   Updated: 2025/09/18 17:28:36 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern: constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern: destructor called" << std::endl;	
}

Intern::Intern(const Intern& other)
{
	std::cout << "Intern: copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
	std::cout << "Intern: copy assignment called" << std::endl;
}

AForm*	Intern::makeForm(std::string const formName, std::string const target)
{
	switch (formName)
	{
	case ("ShrubberyCreationForm"):
		ShrubberyCreationForm(target);
		break;
	
	case ():
		RobotomyRequestForm(target);
		break;
	case ():
		PresidentialPardonForm(target);
		break;
		
	default:
		std::cout << "" << std::endl;
		break;
	}
}
