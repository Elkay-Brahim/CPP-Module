/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:15:37 by bchifour          #+#    #+#             */
/*   Updated: 2023/08/07 15:30:04 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	value = 0;
}

Fixed::Fixed(const Fixed& other)
{
	value = other.value;
}

Fixed::Fixed(const int value_int)
{
	value = value_int << fractionalBits;
}

Fixed::Fixed(const float value_float)
{
	value = roundf(value_float * (1 << fractionalBits));
}

Fixed::~Fixed()
{
}

Fixed& Fixed:: operator=(const Fixed& other)
{
	value = other.value;
	return *this;
}

bool Fixed:: operator>(const Fixed& other) const
{
	return value > other.value;
}

bool Fixed:: operator<(const Fixed& other) const
{
	return value < other.value;
}

bool Fixed:: operator>=(const Fixed& other) const
{
	return value >= other.value;
}

bool Fixed:: operator<=(const Fixed& other) const
{
	return value <= other.value;
}

bool Fixed:: operator==(const Fixed& other) const
{
	return value == other.value;
}

bool Fixed:: operator!=(const Fixed& other) const
{
	return value != other.value;
}

Fixed Fixed:: operator+(const Fixed& other) const
{
	Fixed tmp(*this);
	tmp.value = value + other.value;
	return tmp;
}

Fixed Fixed:: operator-(const Fixed& other) const
{
	Fixed tmp(*this);
	tmp.value = value - other.value;
	return tmp;
}

Fixed Fixed:: operator*(const Fixed& other) const
{
	Fixed tmp(*this);
	tmp.value = (value * other.value) >> fractionalBits;
	return tmp;
}

Fixed Fixed:: operator/(const Fixed& other) const
{
	Fixed tmp(*this);
	tmp.value = (value << fractionalBits) / other.value;
	return tmp;
}

Fixed& Fixed:: operator++()
{
	value = value + 1;
	return *this;
}

Fixed Fixed:: operator++(int)
{
	Fixed tmp(*this);
	++(*this);
	return tmp;
}

Fixed& Fixed:: operator--()
{
	value = value - 1;
	return *this;
}

Fixed Fixed:: operator--(int)
{
	Fixed tmp(*this);
	--(*this);
	return tmp;
}

const Fixed& Fixed:: min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return a;
	else
		return b;
}

const Fixed& Fixed:: max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	else
		return b;
}

float Fixed:: toFloat() const
{
	return (float)value / (1 << fractionalBits);
}

int Fixed:: toInt() const
{
	return value >> fractionalBits;
}

Fixed& Fixed:: min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	else
		return b;
}

Fixed& Fixed:: max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	else
		return b;
}


std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}