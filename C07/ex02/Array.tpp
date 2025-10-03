/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 21:30:04 by trpham            #+#    #+#             */
/*   Updated: 2025/10/03 11:32:53 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(): _arr(nullptr), _size(0)
{
}

template <typename T>
Array<T>::~Array()
{
	delete[] _arr;
}

template <typename T>
Array<T>::Array(unsigned int n): _size(n)
{
	try
	{
		_arr = new T[n](); // () at the end will zero initialize built-in type and call default constructor for class type
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		throw;
	}	
}

template <typename T>
Array<T>::Array(const Array& other): _size(other._size)
{
	_arr = new T[other._size];
	for (unsigned int i = 0; i < other._size; i++)
		this->_arr[i] = other._arr[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		_size = other._size;
		delete[] _arr;
		_arr = new T[other._size]();
		for (unsigned int i = 0; i < other._size; i++)
			this->_arr[i] = other._arr[i];
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) const
{
	if (index < _size)
		return _arr[index];
	else
		throw std::out_of_range("Index is out of bound");
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}
