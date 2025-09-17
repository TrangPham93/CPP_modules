/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:06:37 by trpham            #+#    #+#             */
/*   Updated: 2025/09/17 20:28:40 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

// class AForm;

class ShrubberyCreationForm : public AForm
{
private:
	
public:
	ShrubberyCreationForm();
	~ShrubberyCreationForm();
	// ShrubberyCreationForm(const std::string& target);

	void	beSigned(Bureaucrat& b) override;
	
	
};


