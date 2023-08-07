/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:46:12 by bchifour          #+#    #+#             */
/*   Updated: 2023/08/07 15:00:07 by bchifour         ###   ########.fr       */
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
	this->setRawBits(_new.getRawBits());
}

Fixed& Fixed:: operator=(const Fixed& _new)
{
	std::cout << "Copy assignment operator called" << std:: endl;
	if (this != &_new)
	{
		this->value = _new.getRawBits();
	}
	return *this;
}
Fixed:: ~Fixed()
{
	std::cout << "Destructor called" << std:: endl;
}

int Fixed:: getRawBits() const
{
	std:: cout << "getRawBits member function called\n";
	return this->value;
}
void Fixed:: setRawBits(int const _new )
{
	this->value = _new;
}