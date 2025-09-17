/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:18:10 by trpham            #+#    #+#             */
/*   Updated: 2025/09/17 22:39:54 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// AForm::AForm() 
// 	: _formName("unknown"), _isSign(false), _signGrade(1), _executeGrade(1)
// {
// 	std::cout << "Form: constructor called" << std::endl;
// }

AForm::~AForm()
{
	std::cout << "Form: destructor called" << std::endl;
}

AForm::AForm(std::string name, unsigned int signGrade, 
	unsigned int executeGrade) :_formName(name), _isSign(false), 
	_signGrade(signGrade), _executeGrade(executeGrade)
{
	std::cout << "Form: para_constructor called" << std::endl;
	if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other): _formName(other._formName), 
	_isSign(other._isSign), _signGrade(other._signGrade),
	_executeGrade(other._executeGrade)
{
	std::cout << "Form: copy constructor called" << std::endl;
	if (other._signGrade < 1 || other._executeGrade < 1)
		throw AForm::GradeTooLowException();
	else if (other._signGrade > 150 || other._executeGrade > 150)
		throw AForm::GradeTooHighException();
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		_isSign = other._isSign;
	return (*this);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Exception: Form's grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Exception: Form's grade is too low";
}

const char* AForm::FormNotSigned::what() const throw()
{
	return "Exception: Form is not signed yet";
}

void	AForm::beSigned(Bureaucrat& b)
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

std::string AForm::getFormName() const
{
	return _formName;
}

bool	AForm::getSignStatus() const
{
	return _isSign;
}

unsigned int	AForm::getSignGrade() const
{
	return _signGrade;
}

unsigned int	AForm::getExecuteGrade() const
{
	return _executeGrade;	
}

std::ostream& operator << (std::ostream& out, AForm& obj)
{
	out << "Form " << obj.getFormName() << ", has sign grade of " 
		<< obj.getSignGrade() << " and execute grade of " 
		<< obj.getExecuteGrade() ;
	if (obj.getSignStatus() == true)
		out << " -> is signed";
	else
		out << " -> is not signed";
	return out;
}
