/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:05:58 by trpham            #+#    #+#             */
/*   Updated: 2025/09/10 12:00:55 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	scT("scav");
	ScavTrap	scT2;
	
	scT2.setName("newScav");
	try
	{
		std::cout << scT.getName() << " has " << scT.getHitPoint() 
			<< " hit points, "
			<< scT.getEnergyPoint() << " energy points and attack damage is "
			<< scT.getAttackDamage() << std::endl;
		std::cout << scT2.getName() << " has " << scT2.getHitPoint() 
			<< " hit points, "
			<< scT2.getEnergyPoint() << " energy points and attack damage is "
			<< scT2.getAttackDamage() << std::endl;
			
		std::cout << "\n------------battle--------------\n" << std::endl;
		
		scT.attack(scT2.getName());
		scT2.takeDamage(scT.getAttackDamage());
		scT2.attack(scT.getName());
		scT.takeDamage(scT2.getAttackDamage());
		scT2.attack(scT.getName());
		scT.takeDamage(scT2.getAttackDamage());
		scT.guardGate();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " <<e.what() << '\n';
		return (1);
	}
	std::cout << scT.getName() << " has " << scT.getHitPoint() 
		<< " hit points, "
		<< scT.getEnergyPoint() << " energy points" << std::endl;
	std::cout << scT2.getName() << " has " << scT2.getHitPoint() 
		<< " hit points, "
		<< scT2.getEnergyPoint() << " energy points" << std::endl;
	return (0);
}