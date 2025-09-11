/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:35:21 by trpham            #+#    #+#             */
/*   Updated: 2025/09/11 14:01:15 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Dog : public Animal
{
private:
	
public:
	Dog();
	~Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	
	void makeSound() const;
};

