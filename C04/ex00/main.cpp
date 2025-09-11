/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:18:31 by trpham            #+#    #+#             */
/*   Updated: 2025/09/11 14:24:41 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/* If you are using a pointer to an object, use -> to access its members. 
	(*meta).makeSound() == meta->makeSound */
int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;

	std::cout << "\n----------test-wrong-cat--------------\n" << std::endl;
	
	const WrongAnimal* wAnimal = new WrongAnimal();
	const WrongAnimal* wCat = new WrongCat();
	
	std::cout << wAnimal->getType() << " " << std::endl;
	std::cout << wCat->getType() << " " << std::endl;
	wCat->makeSound(); //will output the animal sound!
	wAnimal->makeSound();
	delete wCat;
	delete wAnimal;
	
	return 0;
}