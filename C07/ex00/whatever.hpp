/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:14:13 by trpham            #+#    #+#             */
/*   Updated: 2025/10/02 11:43:55 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T> 
T max(T x, T y)
{
	if (x > y)
		return x;
	return y;
}

template <typename T> 
T min(T x, T y)
{
	if (x < y)
		return x;
	return y;
}

template <typename T> 
void swap(T &x, T &y)
{
	T	a;

	a = x;
	x = y;
	y = a;
}
