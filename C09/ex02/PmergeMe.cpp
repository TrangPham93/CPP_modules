/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:54:15 by trpham            #+#    #+#             */
/*   Updated: 2025/10/14 15:32:28 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

	
void PmergeMe::addNumToVec(int num)
{
	_vec.push_back(num);
}

void PmergeMe::printVec()
{
	for (size_t i = 0; i < _vec.size(); i++)
	{
		std::cout << " " << _vec[i];
	}
	std::cout << std::endl;
}

void PmergeMe::sortVec()
{
	
}