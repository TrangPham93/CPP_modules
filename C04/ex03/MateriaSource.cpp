/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 16:15:39 by trpham            #+#    #+#             */
/*   Updated: 2025/09/13 11:26:52 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource()
{
	std::cout << "MateriaSource: constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource: destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria* m)
{
	
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	
}