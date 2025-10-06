/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:15:34 by trpham            #+#    #+#             */
/*   Updated: 2025/10/06 12:37:03 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main( void ) 
{
	std::array<int,6> arr = {1, 0, 3, 100, 5, -2};
	
	try
	{
		int pos = easyfind(arr, 5);
		std::cout << "first occurance of 5: " << pos << std::endl;

		int nePos = easyfind(arr, -2);
		std::cout << "first occurance of -2: " << nePos << std::endl;
		
		int noPos = easyfind(arr, -1);
		std::cout << "first occurance of -1: " << noPos << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}