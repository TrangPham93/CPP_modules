/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:18:51 by trpham            #+#    #+#             */
/*   Updated: 2025/09/17 21:31:44 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Bureaucrat
{
private:
	const std::string	_name;
	unsigned int		_grade;	

public:
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(std::string name, unsigned int newGrade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	
	std::string		getName() const;
	unsigned int	getGrade() const;
	void			incrementGrade();
	void			decrementGrade();
};

std::ostream& operator << (std::ostream &out, const Bureaucrat& obj);


