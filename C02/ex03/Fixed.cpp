/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:35:49 by trpham            #+#    #+#             */
/*   Updated: 2025/08/12 22:37:31 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionBit = 8;

Fixed::Fixed(void): _rawValue{0}
{
}

Fixed::Fixed(const int	intNum)
{
	int64_t	temp = static_cast<int64_t>(intNum);
	
	temp <<= _fractionBit;
	if (temp < std::numeric_limits<int>::min() 
			|| temp > std::numeric_limits<int>::max())
		throw std::overflow_error("Constructor with intNum overflow");
	_rawValue = static_cast<int>(temp);
}

Fixed::Fixed(const float fNum)
{
	int64_t	temp = static_cast<int64_t>(fNum);
	
	temp = std::roundf(fNum * (1 << _fractionBit));
	if (temp < std::numeric_limits<int>::min() 
			|| temp > std::numeric_limits<int>::max())
		throw std::overflow_error("Constructor with intNum overflow");
	_rawValue = static_cast<int>(temp);
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed& copy)
{
	*this = copy;
}

/* @attention: checks if the object you are assigning to is different from the object you are assigning from. */
Fixed& Fixed::operator = (const Fixed& copy)
{
	if (this != &copy) 
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
	if (this->_rawValue == std::numeric_limits<int>::max())
		throw std::overflow_error("Increment overflow");
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
	if (this->_rawValue == std::numeric_limits<int>::min())
		throw std::overflow_error("Increment overflow");
	this->_rawValue--;
	return (*this);
}

Fixed	Fixed::operator-- (int)
{
	Fixed	old = *this;
	operator--();
	return (old);
}

Fixed&	Fixed::min (Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed&	Fixed::min (const Fixed& a, const Fixed& b)
{
	if (a < b)
		return a;
	return b;
}
	
Fixed&	Fixed::max (Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed&	Fixed::max (const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	return b;	
}