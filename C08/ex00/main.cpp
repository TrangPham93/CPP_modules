/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:15:34 by trpham            #+#    #+#             */
/*   Updated: 2025/10/08 10:42:26 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main( void ) 
{
	std::cout << "\n---------array------------\n\n";
	std::array<int,6> arr = {1, 0, 3, 100, 5, -2};
	
	try
	{
		std::array<int,6>::iterator pos = easyfind(arr, 5);
		std::cout << "first occurance of 5: " << pos << std::endl;
		std::cout << "first occurance of 5: " << *pos << std::endl;

		std::array<int,6>::iterator nepos = easyfind(arr, -2);
		std::cout << "first occurance of -2: " << nepos << std::endl;
		std::cout << "first occurance of -2: " << *nepos << std::endl;
		
		std::array<int,6>::iterator nopos = easyfind(arr, -1);
		std::cout << "first occurance of -1: " << nopos<< std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n---------vector------------\n\n";
	std::vector<int> vec = {1, 0, 3, 100, 5, -2};
	
	try
	{
		// Iterator of vector container: This iterator is a wrapper around a pointer, 
		// not a pointer itself.
		// It behaves like a pointer (supports *, ++, etc.),
		// but you can’t directly print it — because std::ostream (<<) doesn’t
		// know how to handle it.
		std::vector<int>::iterator pos = easyfind(vec, 5);
		std::cout << "first occurance of 5: " << *pos << std::endl;

		std::vector<int>::iterator nepos = easyfind(vec, -2);
		std::cout << "first occurance of -2: " << *nepos << std::endl;
		
		std::vector<int>::iterator nopos = easyfind(vec, -1);
		std::cout << "first occurance of -1: " << *nopos<< std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}