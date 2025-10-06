/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:28:48 by trpham            #+#    #+#             */
/*   Updated: 2025/10/06 16:16:25 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
private:
	unsigned int		_maxInt;
	std::vector<int>	_vec;
	
public:
	Span() = delete;
	~Span() = default;
	Span(const Span& other);
	Span& operator= (const Span& other);
	Span(unsigned int N);

	void	addNumber(int const number);
	void	addNumber(std::vector<int>::iterator itbegin, 
					std::vector<int>::iterator itend);
	unsigned int shortestSpan();
	unsigned int longestSpan();
};


