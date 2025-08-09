/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:19:31 by trpham            #+#    #+#             */
/*   Updated: 2025/08/09 15:12:35 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

class Harl
{
private:
	void	(Harl::*funcArr[4])(void);
	void 	debug( void );
	void 	info( void );
	void 	warning( void );
	void 	error( void );

public:
	Harl(void);
	~Harl();

	void complain( std::string level );
};

