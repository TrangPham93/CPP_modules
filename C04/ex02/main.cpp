/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:18:31 by trpham            #+#    #+#             */
/*   Updated: 2025/09/12 12:40:38 by trpham           ###   ########.fr       */
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
			herd[i] = new Dog();
		else
			herd[i] = new Cat();	
	}
	
	for (int i = 0; i < amount; i++)
		herd[i]->makeSound();
		
	for (int i = 0; i < amount; i++)
		delete herd[i];
		
	return 0;
}