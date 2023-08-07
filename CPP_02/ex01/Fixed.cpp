/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:11:30 by bchifour          #+#    #+#             */
/*   Updated: 2023/08/07 15:25:14 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed:: Fixed(const Fixed& _new)
{
	std::cout << "Copy constructor called" << std::endl;
	value = _new.value;
}

Fixed& Fixed:: operator=(const Fixed& _new)
{
	std::cout << "Copy assignment operator called" << std:: endl;
	if (this != &_new)
	{
		value = _new.value;
	}
	return *this;
}


Fixed::Fixed(const int value_int)
{
	std:: cout << "Int constructor called\n";
	value = value_int << fractional;
}

Fixed::Fixed(const float value_float)
{
	std:: cout << "Float constructor called\n";
	value = roundf(value_float * (1 << fractional));
}

Fixed:: ~Fixed()
{
	std::cout << "Destructor called" << std:: endl;
}

int Fixed:: toInt() const
{
	return (int)(value >> fractional);
}

float Fixed:: toFloat() const
{
	return ((float)(value) / (1 << fractional));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}