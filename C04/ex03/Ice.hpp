/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:18:58 by trpham            #+#    #+#             */
/*   Updated: 2025/09/17 11:03:38 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
private:
	
public:
	Ice();
	~Ice();
	Ice(const Ice& other);
	Ice& operator= (const Ice& other);
	
	Ice* clone() const;
	void use(ICharacter& target);
};

