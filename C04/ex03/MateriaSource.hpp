/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 16:13:59 by trpham            #+#    #+#             */
/*   Updated: 2025/09/17 14:28:31 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria*	_inventoryM[4];
	
public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource& other);
	MateriaSource& operator= (const MateriaSource& other);

	void 		learnMateria(AMateria* m) override;
	AMateria*	createMateria(std::string const & type) override;
};

