/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:06:43 by trpham            #+#    #+#             */
/*   Updated: 2025/09/18 11:06:38 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* 	Base class private members are initialized only by the base class constructor.
	Derived class constructor calls the base constructor to initialize the base part.
	Derived class can only initialize its own members in its initializer list. */
PresidentialPardonForm::PresidentialPardonForm() 
	: AForm("PresidentialPardonForm", 25, 5), _target("unknown")
{
	std::cout << "Presidential Form: constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Form: destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "Presidential Form: para_constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), _target(other._target)
{
	std::cout << "Presidential Form: copy constructor called" << std::endl;	
}

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm& other)
{
	std::cout << "Presidential Form: copy assignment operator called" 
		<< std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSignStatus())
		throw PresidentialPardonForm::FormNotSigned();
	else if (executor.getGrade() > this->getExecuteGrade())
		throw Bureaucrat::GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

