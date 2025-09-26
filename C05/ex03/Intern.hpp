/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 17:13:59 by trpham            #+#    #+#             */
/*   Updated: 2025/09/26 12:45:36 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

class Intern
{
private:
	
public:
	Intern();
	~Intern();
	Intern(const Intern& other) = delete;
	Intern& operator=(const Intern& other) = delete;
	
	AForm*	makeForm(std::string const formName, std::string const target);
};

