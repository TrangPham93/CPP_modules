/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:57:11 by trpham            #+#    #+#             */
/*   Updated: 2025/10/14 11:12:18 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
// #include <string>
#include <forward_list>

#define INPUT_ERR "Error: input RPN inside \"\" and mathematical operator +-*/ only"

/* forward_list:
	 */
class RPN
{
private:
	std::forward_list<int> _fl;
	
public:
	RPN() = default;
	~RPN() = default;
	RPN(const RPN& other) = default;
	RPN& operator= (const RPN& other) = default;
	
	size_t size();
	void addNumber(int num);
	void printFL();
};


