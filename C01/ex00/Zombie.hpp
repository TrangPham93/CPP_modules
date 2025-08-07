/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:09:24 by trpham            #+#    #+#             */
/*   Updated: 2025/08/07 16:26:36 by trpham           ###   ########.fr       */
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

		void		announce( void );
		std::string	get_name( void );
		void		set_name( std::string );
};

Zombie*				newZombie( std::string name );
void				randomChump( std::string name );

#endif