/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:57:38 by trpham            #+#    #+#             */
/*   Updated: 2025/10/14 11:07:11 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

size_t RPN::size()
{
	return std::distance(_fl.begin(), _fl.end());
}

void RPN::addNumber(int num)
{
	_fl.push_front(num);
}

void RPN::printFL()
{
	for (auto i : _fl)
		std::cout << i << " " << std::endl;
}