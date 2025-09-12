/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:48:02 by trpham            #+#    #+#             */
/*   Updated: 2025/09/11 20:32:44 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Brain
{
private:
	
public:
	Brain();
	~Brain();
	Brain(const Brain& other);
	Brain& operator= (const Brain& other);

	std::string ideas[100];
	void		getIdeas() const;
	void		setIdeas(std::string& idea);
};

