/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 13:28:55 by trpham            #+#    #+#             */
/*   Updated: 2025/08/08 15:19:45 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed()
{
}

Sed::~Sed()
{
}

void	Sed::set_filename(std::string& name)
{
	_filename = name;
}

void	Sed::set_s1(std::string replaced)
{
	_s1 = replaced;
}

void	Sed::set_s2(std::string replacing)
{
	_s2 = replacing;
}

const std::string&	Sed::get_filename(void)
{
	return _filename;
}

const std::string&	Sed::get_s1(void)
{
	return _s1;
}

const std::string&	Sed::get_s2(void)
{
	return _s2;
}


void	Sed::new_sed(const std::string& filename, const std::string& s1, const std::string& s2)
{
	_filename = filename;
	_s1 = s1;
	_s2 = s2;
}