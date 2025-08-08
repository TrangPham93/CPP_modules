/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 13:26:38 by trpham            #+#    #+#             */
/*   Updated: 2025/08/08 15:45:23 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <fstream>

class Sed
{
private:
	std::string	_filename;
	std::string	_s1;
	std::string	_s2;
	
public:
	Sed(void);
	~Sed(void);

	void				set_filename(std::string& name);
	void				set_s1(std::string replaced);
	void				set_s2(std::string replacing);
	const std::string&	get_filename(void);
	const std::string&	get_s1(void);
	const std::string&	get_s2(void);
		
	// const std::string&: not modify input but accept temporaries
	void	new_sed(const std::string& filename, const std::string& s1, const std::string& s2);
	
};
