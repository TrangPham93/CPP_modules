/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:16:32 by trpham            #+#    #+#             */
/*   Updated: 2025/09/16 12:06:10 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{

public:
	FragTrap(void);
	FragTrap(std::string name);
	~FragTrap();
	FragTrap(const FragTrap& other);
	FragTrap& operator= (const FragTrap& other);

	void highFivesGuys(void);
};


