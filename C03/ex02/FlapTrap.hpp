/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:16:32 by trpham            #+#    #+#             */
/*   Updated: 2025/09/10 13:29:42 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class FlapTrap : public ClapTrap
{
private:
	
public:
	FlapTrap(void);
	FlapTrap(std::string name);
	~FlapTrap();
	FlapTrap(const FlapTrap& other);
	FlapTrap& operator= (const FlapTrap& other);

	void highFivesGuys(void);
};


