/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:19:43 by trpham            #+#    #+#             */
/*   Updated: 2025/09/17 11:03:33 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
private:
	
public:
	Cure();
	~Cure();
	Cure(const Cure& other);
	Cure& operator= (const Cure& other);
	
	Cure* clone() const;
	void use(ICharacter& target);
};
