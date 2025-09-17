/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:18:31 by trpham            #+#    #+#             */
/*   Updated: 2025/09/17 13:36:22 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "\n------default testing---------------\n\n";

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;
	
	std::cout << "\n------deep copy DOG testing---------------\n\n";
	
	Dog	dog1;
	dog1.setBrain("hello");
	dog1.setBrain("no");
	dog1.makeSound();
	
	Dog	dog2 = dog1;
	std::cout << "dog1 brain: " <<std::endl;
	dog1.getBrain();
	std::cout << "dog2 is a deep copy of dog1 brain: " << std::endl;
	dog2.getBrain();

	std::cout << "\n------deep copy CAT testing---------------\n\n";
	
	Cat	cat1;
	cat1.setBrain("meo");
	cat1.setBrain("meow");
	cat1.makeSound();
	
	Cat	cat2 = cat1;
	cat1.setBrain("new meao");
	std::cout << "cat1 brain: " <<std::endl;
	cat1.getBrain();
	std::cout << "cat 2 is a deep copy of cat1 brain: " << std::endl;
	cat2.getBrain();

	std::cout << "\n------ ANIMAL testing---------------\n\n";
	
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