/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:06:43 by trpham            #+#    #+#             */
/*   Updated: 2025/09/18 11:03:38 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* 	Base class private members are initialized only by the base class constructor.
	Derived class constructor calls the base constructor to initialize the base part.
	Derived class can only initialize its own members in its initializer list. */
RobotomyRequestForm::RobotomyRequestForm() 
	: AForm("RobotomyRequestForm", 72, 45), _target("unknown")
{
	std::cout << "Robotomy Form: constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy Form: destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "Robotomy Form: para_constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target)
{
	std::cout << "Robotomy Form: copy constructor called" << std::endl;	
}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm& other)
{
	std::cout << "Robotomy Form: copy assignment operator called" 
		<< std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSignStatus())
	{
		std::cout << "Robotomy failed" << std::endl;
		throw RobotomyRequestForm::FormNotSigned();
	}
	else if (executor.getGrade() > this->getExecuteGrade())
	{
		std::cout << "Robotomy failed" << std::endl;
		throw Bureaucrat::GradeTooLowException();
	}
	std::cout << "Makes drilling noises: zzzzzzzzzzzzzzz" << std::endl;
	std::cout << _target << " has been robotomized successfully 50% of the time" 
		<< std::endl;
}

