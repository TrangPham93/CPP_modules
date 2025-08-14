/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:34:58 by trpham            #+#    #+#             */
/*   Updated: 2025/08/14 12:23:41 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
	Point	a(10, 8.2);
	Point	b(1, 0.2);
	Point	c(6.04, 7);
	Point	p(15, 17);
	// Point	p(4, 3);
	
	try
	{
		if (bsp(a, b, c, p))
			std::cout <<"p inside triangle" << std::endl;
		else
			std::cout << "p outside triangle " << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return (1);
	}
	
	return 0;
}