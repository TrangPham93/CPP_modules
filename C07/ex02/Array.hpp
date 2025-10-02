/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 21:29:54 by trpham            #+#    #+#             */
/*   Updated: 2025/10/02 23:02:05 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>


template <class T>
class Array
{
private:
	T* _arr;
	unsigned int _size;
public:
	Array();
	~Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator=(const Array& other);

	T& operator[](unsigned int index);
	unsigned int size() const;
};

#include "Array.tpp"


