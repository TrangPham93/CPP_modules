/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 16:13:59 by trpham            #+#    #+#             */
/*   Updated: 2025/09/13 11:32:00 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource, public AMateria
{
private:
	AMateria* 
public:
	MateriaSource();
	~MateriaSource();
	// MateriaSource(const MateriaSource& other);
	// MateriaSource& operator= (const MateriaSource& other);

	void 		learnMateria(AMateria* m);
	AMateria*	createMateria(std::string const & type);
};

