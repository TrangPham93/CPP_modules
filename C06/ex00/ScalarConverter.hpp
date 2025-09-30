/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:04:17 by trpham            #+#    #+#             */
/*   Updated: 2025/09/30 22:49:10 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <climits>


/* 
	Implicit type conversion (also known as coercion) is the conversion of one type of data to another type automatically by the compiler when needed. It happens automatically when:
    Operations are performed on values of different data types.
    If you pass an argument to a function that expects a different data type.
    Assigning a value of one data type to a variable of another data type. 
	It is possible for implicit conversions to lose information, signs can be lost (when signed is implicitly converted to unsigned), and overflow can occur (when long long is implicitly converted to float)
	
	Explicit type conversion, also called type casting is the conversion of one type of data to another type manually by a programmer
	- C style casting: (type) expression
	- C++ style:  cast operators:	
		- Static Cast: Used for standard compile time type conversions --> To use static_cast in case of inheritance, the base class must be accessible, non virtual and unambiguous.
		- Dynamic Cast: Used for runtime type conversion in polymorphism and inheritance -->  It is mainly used in inherited class hierarchies for safely casting the base class pointer or reference to derived class (called downcasting). To work with dynamic_cast, there must be one virtual function in the base class.
		- Const Cast: Removes or adds const or volatile qualifiers.
		- Reinterpret Cast: Used for low-level reinterpretation of bits (e.g., converting pointers).
*/
class ScalarConverter
{
private:
	
public:
	/* since it cannot be instantiated, so the object is not created and don't need to be deleted. If it's used as based, shouldn't delete destructor */
	ScalarConverter() = delete;
	~ScalarConverter();

	static void convert (std::string str);
};

enum	eType
{
	TYPE_CHAR,	
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	SPECIALS,
	UNKNOWN
};
