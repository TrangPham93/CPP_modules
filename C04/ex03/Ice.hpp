/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:18:58 by trpham            #+#    #+#             */
/*   Updated: 2025/09/17 13:45:52 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{

public:
	Ice();
	~Ice();
	Ice(const Ice& other);
	Ice& operator= (const Ice& other);
	
	Ice* clone() const override;
	void use(ICharacter& target) override;
};

