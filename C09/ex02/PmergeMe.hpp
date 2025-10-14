/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:53:31 by trpham            #+#    #+#             */
/*   Updated: 2025/10/14 15:32:11 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <string>

#define INPUT_ERR "Error: input a sequence of positive intergers"
#define OVERFLOW_ERR "Error: overflowed"


class PmergeMe
{
private:
	std::vector<int> _vec;
	
public:
	PmergeMe() = default;
	~PmergeMe() = default;
	PmergeMe(const PmergeMe& other) = default;
	PmergeMe& operator= (const PmergeMe& other) = default;

	void addNumToVec(int num);
	void printVec();
	void sortVec();
};

