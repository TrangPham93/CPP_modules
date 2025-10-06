/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:28:20 by trpham            #+#    #+#             */
/*   Updated: 2025/10/06 16:34:36 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	std::cout << "\n---------subject-test---------\n\n";
	Span sp = Span(5);
	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n---------subject-test---------\n\n";

	Span longsp(15000);
	std::vector<int> insertVec = {2, 23, -1, 8}; 
	try
	{
		longsp.addNumber(0);
		longsp.addNumber(insertVec.begin(), insertVec.end());
		

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	
	return 0;
}