/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 16:15:39 by trpham            #+#    #+#             */
/*   Updated: 2025/09/17 16:19:49 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource: constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventoryM[i] = nullptr;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource: destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		delete _inventoryM[i];
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	std::cout << "MateriaSource: copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other._inventoryM[i])
			_inventoryM[i] = other._inventoryM[i]->clone();
		else
			_inventoryM[i] = nullptr;
	}
}

MateriaSource& MateriaSource::operator= (const MateriaSource& other)
{
	std::cout << "MateriaSource: copy assignment operator called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete _inventoryM[i];
		_inventoryM[i] = nullptr;
	}
	for (int i = 0; i < 4; i++)
	{
		if (other._inventoryM[i])
			_inventoryM[i] = other._inventoryM[i]->clone();
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
	std::cout << "MateriaSource: learn material" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inventoryM[i] == nullptr)
		{
			_inventoryM[i] = m;
			return;
		}
	}
	std::cout << "MateriaSource: know 4 materials at most" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventoryM[i] && _inventoryM[i]->getType() == type)
			return _inventoryM[i];
	}
	return 0;
}