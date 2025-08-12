/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:35:49 by trpham            #+#    #+#             */
/*   Updated: 2025/08/12 20:15:57 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionBit = 8;

Fixed::Fixed(void): _rawValue{0}
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int	intNum)
{
	// std::cout << "Int constructor called" << std::endl;
	_rawValue = intNum * (1 << _fractionBit);
}

Fixed::Fixed(const float fNum)
{
	// std::cout << "Float constructor called" << std::endl;
	_rawValue = static_cast<int>(std::roundf(fNum * (1 << _fractionBit)));
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed& Fixed::operator = (const Fixed& copy)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy) //checks if the object you are assigning to is different from the object you are assigning from.
		this->_rawValue = copy.getRawBits();
	return (*this);
}

std::ostream& operator<< (std::ostream& os, const Fixed& other)
{
	os << other.toFloat();
	return (os);
}

int		Fixed::getRawBits( void ) const
{
	return _rawValue;
}

void	Fixed::setRawBits( int const raw )
{
	_rawValue = raw;
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(_rawValue) / (1 << _fractionBit));
}

int	Fixed::toInt( void ) const
{
	return (_rawValue / (1 << _fractionBit));
}

bool	Fixed::operator> (const Fixed& other) const
{
	return (this->_rawValue > other._rawValue);
}

bool	Fixed::operator< (const Fixed& other) const
{
	return (this->_rawValue < other._rawValue);
}

bool	Fixed::operator>= (const Fixed& other) const
{
	return (this->_rawValue >= other._rawValue);
}

bool	Fixed::operator<= (const Fixed& other) const
{
	return (this->_rawValue <= other._rawValue);
}

bool	Fixed::operator== (const Fixed& other) const
{
	return (this->_rawValue == other._rawValue);
}

// @attention	operator== has been defined over, so can use obj comparison
bool	Fixed::operator!= (const Fixed& other) const
{
	return !(*this == other);
}

/* @return: a new Fixed obj with new rawValue, modify neither of objs, keep the fraction of floating point */
Fixed	Fixed::operator+ (const Fixed&other) const
{
	Fixed	f;
	int64_t	temp = static_cast<int64_t>(this->_rawValue) + other._rawValue;
	
	if (temp > std::numeric_limits<int>::max() 
		|| temp < std::numeric_limits<int>::min())
		throw std::overflow_error("Addition overflow");
	
	f._rawValue = static_cast<int32_t>(temp);
	return (f);
}

Fixed	Fixed::operator- (const Fixed&other) const
{
	Fixed	f;
	int64_t	temp = static_cast<int64_t>(this->_rawValue) - other._rawValue;
	
	if (temp > std::numeric_limits<int>::max() 
		|| temp < std::numeric_limits<int>::min())
		throw std::overflow_error("Subtraction overflow");
	
	f._rawValue = static_cast<int32_t>(temp);
	return (f);
}

/*  @note: 
	- multiplication of 2 rawValue can overflow, so use int64 to holf temp.
	- */
Fixed	Fixed::operator* (const Fixed&other) const
{
	Fixed	f;
	int64_t temp = static_cast<int64_t>(this->_rawValue) * other._rawValue;
	
	temp = temp >> _fractionBit;
	if (temp > std::numeric_limits<int>::max() 
		|| temp < std::numeric_limits<int>::min())
		throw std::overflow_error("Multiplication overflow");
		
	f._rawValue = static_cast<int>(temp);
	return (f);
}

Fixed	Fixed::operator/ (const Fixed&other) const
{
	Fixed	f;
	
	if (other._rawValue == 0)
		throw std::runtime_error("Divided by 0");
		
	int64_t	numerator = static_cast<int64_t>(this->_rawValue) << _fractionBit;
	int64_t	temp = numerator / other._rawValue;
	if (temp > std::numeric_limits<int>::max() 
		|| temp < std::numeric_limits<int>::min())
		throw std::overflow_error("Division overflow");
		
	f._rawValue = static_cast<int>(temp);
	return (f);
}

/* @note: prefix
	Fixed b = ++a;
	a.rawValue++;
	return b.rawValue = a.rawValue after increment.
*/
Fixed&	Fixed::operator++ (void)
{
	this->_rawValue++;
	return (*this);
}

/* @note: postfix
	Fixed b = a++;
	a.rawValue++;
	return b.rawValue = a.rawValue before increment.
*/
Fixed	Fixed::operator++ (int)
{
	Fixed	old = *this;
	operator++();
	return (old);
}

Fixed&	Fixed::operator-- (void)
{
	this->_rawValue--;
	return (*this);
}
