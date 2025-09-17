/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:48:37 by trpham            #+#    #+#             */
/*   Updated: 2025/09/17 12:31:56 by trpham           ###   ########.fr       */
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
		if (!other.ideas[i].empty())
			this->ideas[i] = other.ideas[i];
		else
			break;
	}
}

Brain& Brain::operator= (const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		{
			if (!other.ideas[i].empty())
				this->ideas[i] = other.ideas[i];
			else
				break;
		}
	}
	return *this;
}

void Brain::getIdeas() const
{
	for (int i = 0; i < 100; i++)
	{
		if (!ideas[i].empty())
			std::cout << ideas[i] << std::endl;
		else
			break;
	}
}

void Brain::setIdeas(std::string& idea)
{
	for (int i = 0; i < 100; i++)
	{
		if (ideas[i].empty())
		{
			ideas[i] = idea;
			return;
		}
	}
	std::cout << "full ideas, can not add" << std::endl;
}