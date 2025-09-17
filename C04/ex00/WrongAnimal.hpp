/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:10:33 by trpham            #+#    #+#             */
/*   Updated: 2025/09/17 11:04:43 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class WrongAnimal
{

	protected:
		std::string	type;
		
	public:
		WrongAnimal();
		virtual ~WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator= (const WrongAnimal& other);
		
		/* A virtual function is a member function in the base class 
		that can be overridden in derived classes. */
		void	makeSound() const;
		std::string		getType() const;
		void			setType(std::string newType);
};
