/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:06:37 by trpham            #+#    #+#             */
/*   Updated: 2025/09/18 11:04:18 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string	_target;
	
public:
	PresidentialPardonForm();
	~PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator= (const PresidentialPardonForm& other);

	void	execute(Bureaucrat const & executor) const override;
};


