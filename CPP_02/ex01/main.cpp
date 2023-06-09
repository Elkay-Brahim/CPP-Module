/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:10:57 by bchifour          #+#    #+#             */
/*   Updated: 2023/06/06 22:02:09 by bchifour         ###   ########.fr       */
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
		Fixed(const int value_int);
		Fixed(const float value_float);
		Fixed& operator=(const Fixed& _new);
		// std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
		~Fixed();
		float toFloat() const;
		int toInt() const;
		// int getRawBits( void ) const;
		// void setRawBits( int const _new );
};

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed:: Fixed(const Fixed& _new)
{
	std::cout << "Copy constructor called" << std::endl;
	// std:: cout << "getRawBits member function called\n";
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
		// std:: cout << "getRawBits member function called\n";
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
	value = static_cast<int>(value_float * (1 << fractional));
}

Fixed:: ~Fixed()
{
	std::cout << "Destructor called" << std:: endl;
}

int Fixed:: toInt() const
{
	return value >> fractional;
}

float Fixed:: toFloat() const
{
	return static_cast<float>(value) / (1 << fractional);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}
// int Fixed:: getRawBits() const
// {
// 	std:: cout << "getRawBits member function called\n";
// 	return this->value;
// }
// void Fixed:: setRawBits(int const _new )
// {
// 	this->value = _new;
// }

int main( void ) 
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}




// #include <iostream>

// class Fixed {
// private:
//     int value;
//     static const int fractional = 8;

// public:
//     Fixed();
//     Fixed(const Fixed& other);
//     Fixed(const int value_int);
//     Fixed(const float value_float);
//     Fixed& operator=(const Fixed& other);
//     ~Fixed();
//     float toFloat() const;
//     int toInt() const;
// };

// Fixed::Fixed() {
//     std::cout << "Default constructor called" << std::endl;
//     value = 0;
// }

// Fixed::Fixed(const Fixed& other) {
//     std::cout << "Copy constructor called" << std::endl;
//     value = other.value;
// }

// Fixed& Fixed::operator=(const Fixed& other) {
//     std::cout << "Copy assignment operator called" << std::endl;
//     if (this != &other) {
//         value = other.value;
//     }
//     return *this;
// }

// Fixed::Fixed(const int value_int) {
//     value = value_int << fractional;
// }

// Fixed::Fixed(const float value_float) {
//     value = static_cast<int>(value_float * (1 << fractional));
// }

// Fixed::~Fixed() {
//     std::cout << "Destructor called" << std::endl;
// }

// float Fixed::toFloat() const {
//     return static_cast<float>(value) / (1 << fractional);
// }

// int Fixed::toInt() const {
//     return value >> fractional;
// }

// std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
//     os << fixed.toFloat();
//     return os;
// }

// int main() {
//     Fixed a;
//     Fixed const b(10);
//     Fixed const c(42.42f);
//     Fixed const d(b);
//     a = Fixed(1234.4321f);
//     std::cout << "a is " << a << std::endl;
//     std::cout << "b is " << b << std::endl;
//     std::cout << "c is " << c << std::endl;
//     std::cout << "d is " << d << std::endl;
//     std::cout << "a is " << a.toInt() << " as integer" << std::endl;
//     std::cout << "b is " << b.toInt() << " as integer" << std::endl;
//     std::cout << "c is " << c.toInt() << " as integer" << std::endl;
//     std::cout << "d is " << d.toInt() << " as integer" << std::endl;
//     return 0;
// }