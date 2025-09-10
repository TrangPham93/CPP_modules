/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:05:58 by trpham            #+#    #+#             */
/*   Updated: 2025/09/10 16:55:24 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FlapTrap.hpp"

int	main(void)
{
	ClapTrap	clap("clap");
	ScavTrap	scT("scav");
	FlapTrap	flap("flap");
	
	clap.setAttackDamage(5);
	
	try
	{
		std::cout << clap.getName() << " has " << clap.getHitPoint() 
			<< " hit points, "
			<< clap.getEnergyPoint() << " energy points and attack damage is "
			<< clap.getAttackDamage() << std::endl;
		std::cout << scT.getName() << " has " << scT.getHitPoint() 
			<< " hit points, "
			<< scT.getEnergyPoint() << " energy points and attack damage is "
			<< scT.getAttackDamage() << std::endl;
		std::cout << flap.getName() << " has " << flap.getHitPoint() 
			<< " hit points, "
			<< flap.getEnergyPoint() << " energy points and attack damage is "
			<< flap.getAttackDamage() << std::endl;
			
		std::cout << "\n------------battle--------------\n" << std::endl;
		
		
		clap.attack(scT.getName());
		scT.takeDamage(clap.getAttackDamage());
		flap.attack(scT.getName());
		scT.takeDamage(flap.getAttackDamage());
		scT.attack(flap.getName());
		flap.takeDamage(scT.getAttackDamage());
		scT.guardGate();
		flap.highFivesGuys();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " <<e.what() << '\n';
		return (1);
	}
	std::cout << scT.getName() << " has " << scT.getHitPoint() 
		<< " hit points, "
		<< scT.getEnergyPoint() << " energy points" << std::endl;
	std::cout << clap.getName() << " has " << clap.getHitPoint() 
		<< " hit points, "
		<< clap.getEnergyPoint() << " energy points" << std::endl;
	std::cout << flap.getName() << " has " << flap.getHitPoint() 
		<< " hit points, "
		<< flap.getEnergyPoint() << " energy points" << std::endl;
	return (0);
}