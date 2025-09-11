/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:48:37 by trpham            #+#    #+#             */
/*   Updated: 2025/09/11 20:46:24 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain: constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain: destructor called" << std::endl;	
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain: copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = other.ideas[i];
	}
}

Brain& Brain::operator= (const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		{
			this->ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

void Brain::getIdeas() const
{
	for (int i = 0; i < 100; i++)
	{
		if (!ideas[i].empty())
		{
			std::cout << ideas[i] << std::endl;
		}
	}
}

void Brain::setIdeas(std::string& idea)
{
	for (int i = 0; i < 100; i++)
	{
		if (ideas[i].empty())
		{
			ideas[i] = idea;
			break;
		}
		if (i == 100)
		{
			std::cout << "full idea, can not add" << std::endl;
			break;
		}
	}
}