/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:49:34 by trpham            #+#    #+#             */
/*   Updated: 2025/09/19 12:11:38 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"	

/* the object method throws exception, so the object goes out of scope in 
try block, resulting in destructor called. 
After that, catch block print the message, so exception is printed after 
destructor */
int	main()
{
	std::cout << "\n----------test-intern---------\n" << std::endl;
	try
	{
		Intern someRandomIntern;
		AForm* rrf;
		
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");

		delete rrf;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;		
	}

	std::cout << "\n----------non-exist-form---------\n" << std::endl;
	try
	{
		Intern anotherIntern;
		AForm* rrf;
		
		rrf = anotherIntern.makeForm("robotomy", "Bender");

		delete rrf;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;		
	}

	return 0;
}