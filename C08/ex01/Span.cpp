/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:28:45 by trpham            #+#    #+#             */
/*   Updated: 2025/10/06 16:16:19 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N): _maxInt(N)
{
}

Span::Span(const Span& other): _maxInt(other._maxInt), _vec(other._vec)
{
}

Span& Span::operator= (const Span& other)
{
	if (this != &other)
	{
		_maxInt = other._maxInt;
		_vec = other._vec;
	}
	return *this;
}
	
void Span::addNumber(int const number)
{
	if (_vec.size() >= _maxInt)
		throw std::runtime_error("Container already contains its maximum number of intergers");
	_vec.push_back(number);
}
	
unsigned int Span::shortestSpan()
{
	if (_vec.size() <= 1)
		throw std::runtime_error("Container has less than 2 elements, cannot calculate span");
	std::vector<int> tmp(_vec);
	std::sort(tmp.begin(), tmp.end());
	unsigned int shortestSpan = tmp[1] - tmp[0];
	for (size_t i = 1; i < tmp.size(); i++)
	{
		unsigned int diff = tmp[i] - tmp[i - 1];
		if ( diff < shortestSpan)
			shortestSpan = diff;
	}
	return shortestSpan;
}
	
unsigned int Span::longestSpan()
{
	if (_vec.size() <= 1)
		throw std::runtime_error("Container has less than 2 elements, cannot calculate span");
	int	max = *std::max_element(_vec.begin(), _vec.end());
	int min = *std::min_element(_vec.begin(), _vec.end());
	return static_cast<unsigned int>(max - min);
}

void	Span::addNumber(std::vector<int>::iterator itbegin, 
			std::vector<int>::iterator itend)
{
	if (_vec.size() + std::distance(itbegin, itend) >= _maxInt)
		throw std::runtime_error("Amount of numbers is larger than container's size");
	for (std::vector<int>::iterator it = itbegin; it == itend; it++)
	{
		_vec.insert(_vec.end(), *it);
	}
}
