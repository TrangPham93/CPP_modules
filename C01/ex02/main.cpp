/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 20:42:09 by trpham            #+#    #+#             */
/*   Updated: 2025/08/08 12:32:45 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*
	Pointer to str stores the address of str. 
		- A pointer can be reassigned
		- A pointer has its own memory address and size on the stack
		- can be nullptr
		- can have pointer to pointer
	-> If pointer arithmetic or passing a NULL pointer is needed. For example, for arrays (Note that accessing an array is implemented using pointer arithmetic).
	-> To implement data structures like a linked list, a tree, etc. and their algorithms. This is so because, in order to point to different cells, we have to use the concept of pointers.
	Reference or alias for str. 
		- Reference cannot be reassigned, must be assigned at initialization.
		- A reference shares the same memory address with the original variable and takes up no space on the stack.
		- cannot be nullptr.
		- cannot have reference to reference
	-> In function parameters and return types.
*/
int	main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str; 
	
	std::cout << "Memory address of str var	 :	" << &str << std::endl;
	std::cout << "Memory address of stringPTR:	" << stringPTR << std::endl;
	std::cout << "Memory address of stringREF:	" << &stringREF << std::endl;
	
	std::cout << "---------------------------" << std::endl;
	std::cout << "Value of str var		: " << str << std::endl;
	std::cout << "Value of str stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of str stringREF: " << stringREF << std::endl;
	
	return 0;
}