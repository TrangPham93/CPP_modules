/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:18:31 by trpham            #+#    #+#             */
/*   Updated: 2025/09/17 13:39:02 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "\n------default testing---------------\n\n";

	// Animal	aAnimal; //this cannot initiate an animal object
	
	int	amount = 20;
	Animal* herd[amount];
	
	for (int i = 0; i < amount; i++)
	{
		if (i < amount/2)
		{
			std::cout << "[" << i << "]" << std::endl;
			herd[i] = new Dog();
		}
		else
		{
			std::cout << "[" << i << "]" << std::endl;
			herd[i] = new Cat();	
		}
	}
	
	for (int i = 0; i < amount; i++)
	{
		std::cout << "[" << i << "] ";
		herd[i]->makeSound();
	}
		
	for (int i = 0; i < amount; i++)
	{
		std::cout << "[" << i << "]" << std::endl;
		delete herd[i];
	}
		
	return 0;
}