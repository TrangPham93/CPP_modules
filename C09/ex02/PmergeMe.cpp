/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:54:15 by trpham            #+#    #+#             */
/*   Updated: 2025/10/15 12:35:23 by trpham           ###   ########.fr       */
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
	int level = 1;
	std::vector<std::vector<int>> newVec;
	
	for (size_t i = 0; i < _vec.size(); i += 2)
	{
		if (_vec[i] > _vec[i + 1])
			std::swap(_vec[i], _vec[i + 1]);
		newVec.insert(newVec.end(), {_vec[i], _vec[i + 1]});
	}
	while (1)
	{
		for (size_t i = 0; i < newVec.size(); i += 2)
		{
			std::cout << *newVec[i].rbegin() << std::endl;
			std::cout << *newVec[i + 1].rbegin() << std::endl;
			if (*newVec[i].rbegin() > *newVec[i + 1].rbegin())
				std::swap(newVec[i], newVec[i + 1]);
		}
		
		level *= 2;
		break;
	}
	
	for (size_t i = 0; i < newVec.size(); i += 1)
	{
		std::cout << newVec[i][0] << "-" << newVec[i][1] << std::endl;
	}
	
}