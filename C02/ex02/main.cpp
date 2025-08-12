/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:34:58 by trpham            #+#    #+#             */
/*   Updated: 2025/08/13 00:06:34 by trpham           ###   ########.fr       */
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

	std::cout << "\n--------------My test---------------------\n" << std::endl;
	
	int		numInt = 214836;
	float	numFloat = 362.32f;
	try
	{
		Fixed	objF(numFloat);
		std::cout << "fixed-point objF	: " << objF << std::endl;
		std::cout << "objF++		: " << objF++ << std::endl;
		std::cout << "objF		: " << objF << std::endl;
		std::cout << "objF		: " << objF << std::endl;
		std::cout << "objF * a	: " << objF * a << std::endl;
		// std::cout << "objF / 0	: " << objF / 0 << std::endl;
		
		Fixed	objI(numInt);
		std::cout << "\nfixed-point objI	: " << objI << std::endl;
		std::cout << "objF > objI	: " << (objF > objI) << std::endl;
		std::cout << "min		: " << Fixed::min(objF , objI) << std::endl;
		std::cout << "max		: " << Fixed::max(objF , objI) << std::endl;
		std::cout << "objF + objI	: " << objF + objI << std::endl;
		std::cout << "objF * objI	: " << objF * objI << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return (1);
	}
	
	return 0;
}