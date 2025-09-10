/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:05:58 by trpham            #+#    #+#             */
/*   Updated: 2025/09/10 19:18:25 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	dmond("newDiamond");

	try
	{
		std::cout << dmond.getDiamondName() << " has " << dmond.getHitPoint() 
			<< " hit points, "
			<< dmond.getEnergyPoint() << " energy points" << std::endl;
		dmond.attack("newTarget");
		dmond.whoAmI();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " <<e.what() << '\n';
		return (1);
	}	
	return (0);
}