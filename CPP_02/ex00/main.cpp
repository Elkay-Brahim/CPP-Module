/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 00:05:48 by bchifour          #+#    #+#             */
/*   Updated: 2023/06/05 22:39:16 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
	private:
		int value;
		static const int fractional = 8;
	public:
		Fixed();
		Fixed(const Fixed& _new);
		Fixed& operator=(const Fixed& _new);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const _new );
};

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed:: Fixed(const Fixed& _new)
{
	std::cout << "Copy constructor called" << std::endl;
	std:: cout << "getRawBits member function called\n";
	// this->setRawBits(_new.getRawBits());
	value = _new.value;
}

Fixed& Fixed:: operator=(const Fixed& _new)
{
	std::cout << "Copy assignment operator called" << std:: endl;
	if (this != &_new)
	{
		// this->value = _new.getRawBits();
		value = _new.value;
		std:: cout << "getRawBits member function called\n";
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

int main( void ) 
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}