/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:06:43 by trpham            #+#    #+#             */
/*   Updated: 2025/09/17 22:58:50 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* 	Base class private members are initialized only by the base class constructor.
	Derived class constructor calls the base constructor to initialize the base part.
	Derived class can only initialize its own members in its initializer list. */
ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm("ShrubberyCreationForm", 145, 137), _target("unknown")
{
	std::cout << "Shrubbery Form: constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Form: destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "Shrubbery Form: para_constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target)
{
	std::cout << "Shrubbery Form: copy constructor called" << std::endl;	
}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm& other)
{
	std::cout << "Shrubbery Form: copy assignment operator called" 
		<< std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSignStatus())
		throw ShrubberyCreationForm::FormNotSigned();
	else if (executor.getGrade() > this->getExecuteGrade())
		throw Bureaucrat::GradeTooLowException();
	
	std::ofstream shrubFile;
	shrubFile.open(_target + "_shrubbery");

	if (!shrubFile.is_open())
		throw "Error in creating file";
	shrubFile << "       ccee88oo\n"
             "    C8O8O8Q8PoOb o8oo\n"
             " dOB69QO8PdUOpugoO9bD\n"
             "CgggbU8OU qOp qOdoUOdcb\n"
             "    6OuU  /p u gcoUodpP\n"
             "       \\\\\\//  /douUP\n"
             "         \\\\\\////\n"
             "          |||/\\\n"
             "          |||\\/\n"
             "          |||||\n"
             "    .....//||||\\\\....\n" << std::endl;
	shrubFile.close();	
}

