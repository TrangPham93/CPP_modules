/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:06:43 by trpham            #+#    #+#             */
/*   Updated: 2025/09/17 20:29:23 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* 	Base class private members are initialized only by the base class constructor.
	Derived class constructor calls the base constructor to initialize the base part.
	Derived class can only initialize its own members in its initializer list. */
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) 
{
	std::cout << "Shrubbery Form: constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Form: destructor called" << std::endl;
}

void	ShrubberyCreationForm::beSigned(Bureaucrat& b)
{
	std::cout << "Preprare to sign!!" << std::endl;
	if (b.getGrade() < 1)
		throw AForm::GradeTooHighException();
	else if (b.getGrade() > 150)
		throw AForm::GradeTooLowException();
	if (b.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();
	_isSign = true;	
}