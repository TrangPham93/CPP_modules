/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:15:34 by trpham            #+#    #+#             */
/*   Updated: 2025/10/02 21:18:51 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	multiply5(int& x)
{
	x = x * 5;
}

void	capitalizeStr(std::string& s)
{
	for (unsigned int i = 0; i < s.length(); i++)
	{
		s[i] = toupper(s[i]);
	}
}

template <typename T> 
void printMe(T x)
{
	std::cout << "type: " << typeid(x).name() << " and value: " << x << std::endl;
}

int main( void ) 
{
	std::cout << "\n------------int------------\n" << std::endl; 
	int arr[3] = {2, 0, 100};
	
	::iter(arr, 3, multiply5);
	
	for (int i = 0; i < 3; i++)
		std::cout << arr[i] << std::endl;
	
	std::cout << "\n------------string------------\n" << std::endl; 
	std::string* strPtr = new std::string[4]{"don't", "look", "up", "!!"};
	::iter(strPtr, 4, capitalizeStr);
	
	for (int i = 0; i < 4; i++)
		std::cout << strPtr[i] << std::endl;

	delete[] strPtr;
	
	std::cout << "\n-------function-template------\n" << std::endl;
	float arrFloat[100];
	for (int i = 0; i < 100; i++)
		arrFloat[i] = i;

	::iter(arrFloat, 100, printMe<float>);
	
	
	return 0;
}