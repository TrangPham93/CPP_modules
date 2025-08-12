/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:34:58 by trpham            #+#    #+#             */
/*   Updated: 2025/08/12 22:43:11 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout <<"fixed-point number a: " << a << std::endl;
	std::cout << "fixed-point number ++a: " << ++a << std::endl;
	std::cout << "fixed-point number a: " << a << std::endl;
	std::cout << "fixed-point number a++: " <<a++ << std::endl;
	std::cout << "fixed-point number a: " << a << std::endl;
	
	std::cout << "fixed-point number b: " << b << std::endl;
	std::cout <<"fixed-point number max(a, b): " << Fixed::max( a, b ) 
		<< std::endl;

	std::cout << "--------------My test---------------------\n" << std::endl;
	
	int	num = 2147483;
	try
	{
		Fixed	d(num);
		std::cout << "fixed-point number d: " << d << std::endl;
		std::cout << "d++: " << d++ << std::endl;
		std::cout << "d * a: " << d * a * a << std::endl;
		std::cout << "c / 0: " << d / 0 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	
	return 0;
}