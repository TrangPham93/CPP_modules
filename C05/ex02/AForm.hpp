/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:18:04 by trpham            #+#    #+#             */
/*   Updated: 2025/09/17 22:18:41 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	_formName;
	bool				_isSign;
	const unsigned int	_signGrade;
	const unsigned int	_executeGrade;

public:
	AForm() = delete; //no default constructor, always initialize properly
	virtual ~AForm();
	AForm(std::string name, unsigned int signGrade, unsigned int executeGrade);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);

	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
	
	std::string 	getFormName() const;
	bool			getSignStatus() const;
	unsigned int	getSignGrade() const;
	unsigned int	getExecuteGrade() const;

	void			beSigned(Bureaucrat& b);
	virtual void	execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator << (std::ostream& out, AForm& obj);


