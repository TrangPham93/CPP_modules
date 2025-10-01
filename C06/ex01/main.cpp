/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:33:19 by trpham            #+#    #+#             */
/*   Updated: 2025/10/01 18:32:48 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
/* Reinterpret casting never fails at runtime, but can silently produce 
incorrect or dangerous results. In round-tripping, the pointer was valid to 
begin with, not changing type, stay in the same runtime context --> safe */
int main()
{
	Data oldData;
	oldData.value = 5;
	std::cout << "oldPtr address:	" << &oldData << std::endl;
	std::cout << "oldPtr value:	" << oldData.value << std::endl;
	
	uintptr_t newPtr;
	newPtr = Serializer::serialize(&oldData);
	std::cout << "serialize val:	" << newPtr << std::endl;

	Data* newData;
	newData = Serializer::deserialize(newPtr);
	std::cout << "newPtr address:	" << newData << std::endl;
	std::cout << "newPtr value:	" << newData->value << std::endl;

	// change data value
	oldData.value = 10;
	std::cout << "oldPtr value:	" << oldData.value << std::endl;
	std::cout << "newPtr value:	" << newData->value << std::endl;
	
	return 0;
}