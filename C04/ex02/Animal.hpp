/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:26:24 by trpham            #+#    #+#             */
/*   Updated: 2025/09/17 13:27:54 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

/* An abstract class is a class that cannot be used to create objects directly. It is meant to be a base class that provides a common interface but doesn't define full behavior.
A class becomes abstract if it has at least one pure virtual function. */
class Animal
{

	/* Protected access modifier is similar to that of private access
	modifiers, the difference is that the class member declared as Protected
	are inaccessible outside the class but they can be accessed by any 
	subclass(derived class) of that class */
	protected:
		std::string	type;
		
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal& other);
		Animal& operator= (const Animal& other);
		
		/* 	A virtual function is a member function in the base class
		that can be overridden in derived classes. 
			Static binding happends at compiling time, will ignore the fact
		that actual obj is Cat and use the pointer type.
			Virtual will indicate that the function may be overriden, dynamic
		dispatch will decide at runtime the version of function to be used
			A pure virtual function is a function declared in a base class that 
		must be overridden in any derived class.
		The = 0 means “no default implementation”.
		It forces derived classes to implement the function */
		virtual void	makeSound() const = 0;
		std::string		getType() const;
		void			setType(std::string newType);
};
