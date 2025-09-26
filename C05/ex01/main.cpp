/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:49:34 by trpham            #+#    #+#             */
/*   Updated: 2025/09/26 12:33:35 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/* the object method throws exception, so the object goes out of scope in 
try block, resulting in destructor called. 
After that, catch block print the message, so exception is printed after 
destructor */
int	main()
{
	std::cout << "\n----------test-1---------\n" << std::endl;
	try
	{
		Bureaucrat	Jim("Jim", 2);
		
		std::cout << Jim << std::endl;
		Jim.incrementGrade();		
		std::cout << Jim << std::endl;
		
		Form	pass25("entrance exam", 25, 12);
		std::cout << pass25 << std::endl;

		pass25.beSigned(Jim);
		std::cout << pass25 << std::endl;
		pass25.beSigned(Jim);
		std::cout << pass25 << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;		
	}
	
	std::cout << "\n----------test-2---------\n" << std::endl;
	try
	{
		Bureaucrat	Jim("Jim", 28);
		
		std::cout << Jim << std::endl;
		Jim.incrementGrade();		
		std::cout << Jim << std::endl;
		
		Form	pass25("entrance exam", 25, 12);
		std::cout << pass25 << std::endl;

		Jim.signForm(pass25);
		std::cout << pass25 << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;		
	}
	
	std::cout << "\n----------test-3---------\n" << std::endl;
	try
	{
		Bureaucrat	Jim("Jim", 28);
		
		std::cout << Jim << std::endl;
		Jim.incrementGrade();		
		std::cout << Jim << std::endl;
		
		Form	pass25("entrance exam", 0, 12);
		std::cout << pass25 << std::endl;

		Jim.signForm(pass25);
		std::cout << pass25 << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;		
	}
	return 0;
}