/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:48:02 by trpham            #+#    #+#             */
/*   Updated: 2025/09/17 11:59:55 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Brain
{
protected:
	std::string ideas[100];
	
public:
	Brain();
	~Brain();
	Brain(const Brain& other);
	Brain& operator= (const Brain& other);

	void		getIdeas() const;
	void		setIdeas(std::string& idea);
};

