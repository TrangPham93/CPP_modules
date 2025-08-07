/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:09:24 by trpham            #+#    #+#             */
/*   Updated: 2025/08/07 16:33:52 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:
		std::string	_name;
		
	public:
		Zombie( void );
		~Zombie( void );

		std::string	get_name( void );
		void		set_name( std::string );
		void		announce( void );
};
	
// Zombie*				newZombie( std::string name );
// void				randomChump( std::string name );
Zombie* 			zombieHorde( int N, std::string name );

#endif