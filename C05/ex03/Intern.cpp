/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 17:14:30 by trpham            #+#    #+#             */
/*   Updated: 2025/09/26 15:49:31 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "InternHelper.hpp"

Intern::Intern()
{
	std::cout << "Intern: constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern: destructor called" << std::endl;	
}

eForm	getForm(std::string const formName)
{
	const std::string	formArr[3] = {"shrubbery creation", 
										"robotomy request", 
										"presidential pardon"};
	for (int i = 0; i < 3; i++)
	{
		if (formArr[i] == formName)
			return static_cast<eForm>(i);
	}
	return UNKNOWN;
}

AForm*	Intern::makeForm(std::string const formName, std::string const target)
{
	AForm* createdForm;

	switch (getForm(formName))
	{
	case SHRUBBERY:
		createdForm = new ShrubberyCreationForm(target);
		break;
	case ROBOTOMY:
		createdForm = new RobotomyRequestForm(target);
		break;
	case PARDON:
		createdForm = new PresidentialPardonForm(target);
		break;
	default:
		throw std::runtime_error("Intern: form name doesn't exist");
		break;
	}
	std::cout << "Intern creates " << createdForm->getFormName() << std::endl;
	return createdForm;
}
