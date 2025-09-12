/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:26:24 by trpham            #+#    #+#             */
/*   Updated: 2025/09/11 15:00:59 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal
{
	private:

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
		dispatch will decide at runtime the version of function to be used*/
		virtual void	makeSound() const;
		std::string		getType() const;
		void			setType(std::string newType);
};
