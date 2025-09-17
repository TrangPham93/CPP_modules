/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:49:34 by trpham            #+#    #+#             */
/*   Updated: 2025/09/17 20:32:59 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

/* the object method throws exception, so the object goes out of scope in 
try block, resulting in destructor called. 
After that, catch block print the message, so exception is printed after 
destructor */
int	main()
{
	std::cout << "\n----------test-1---------\n" << std::endl;
	try
	{
		AForm*	newForm = new ShrubberyCreationForm();
		std::cout << newForm->getFormName() << ": sign grade of " 
			<< newForm->getSignGrade() << ", execute grade of " 
			<< newForm->getExecuteGrade() << ", signed == " 
			<< newForm->getSignStatus() << std::endl;
		delete newForm;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;		
	}
		
	return 0;
}