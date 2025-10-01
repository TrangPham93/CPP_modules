/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:52:06 by trpham            #+#    #+#             */
/*   Updated: 2025/10/01 22:36:05 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstdlib>
#include <iostream>
#include <ctime>

class Base
{

public:
	virtual ~Base();

};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

