/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:38:23 by bchifour          #+#    #+#             */
/*   Updated: 2023/06/09 18:16:11 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <iostream>

// class Fixed
// {
// 	private:
// 		int value;
// 		static const int fractional = 8;
// 	public:
// 		Fixed();
// 		Fixed(const Fixed& _new);
// 		Fixed(const int value_int);
// 		Fixed(const float value_float);
// 		Fixed& operator=(const Fixed& _new);
// 		~Fixed();
// 		float toFloat() const;
// 		int toInt() const;

// 		bool operator>(const Fixed& _new) const;
// 		bool operator<(const Fixed& _new) const;
// 		bool operator>=(const Fixed& _new) const;
// 		bool operator<=(const Fixed& _new) const;
// 		bool operator==(const Fixed& _new) const;
// 		bool operator!=(const Fixed& _new) const;

// 		Fixed operator+(const Fixed& _new) const;
// 		Fixed operator*(const Fixed& _new) const;
// 		Fixed operator-(const Fixed& _new) const;
// 		Fixed operator/(const Fixed& _new) const;

// 		Fixed operator++(int); // Post increment
// 		Fixed& operator++();    // per increment
// 		Fixed operator--(int);
// 		Fixed& operator--();

// 		static Fixed& min(Fixed& a, Fixed& b);
// 		static const Fixed& min(const Fixed& a, const Fixed& b);
// 		static Fixed& max(Fixed& a, Fixed& b);
// 		static const Fixed& max(const Fixed& a, const Fixed& b);
// };

// Fixed::Fixed()
// {
// 	// std::cout << "Default constructor called" << std::endl;
// 	value = 0;
// }

// int Fixed:: toInt() const
// {
// 	return value >> fractional;
// }

// Fixed:: Fixed(const Fixed& _new)
// {
// 	// std::cout << "Copy constructor called" << std::endl;
// 	// std:: cout << "getRawBits member function called\n";
// 	// this->setRawBits(_new.getRawBits());
// 	value = _new.value;
// }

// Fixed& Fixed:: operator=(const Fixed& _new)
// {
// 	// std::cout << "Copy assignment operator called" << std:: endl;
// 	if (this != &_new)
// 	{
// 		// this->value = _new.getRawBits();
// 		value = _new.value;
// 		// std:: cout << "getRawBits member function called\n";
// 	}
// 	return *this;
// }

// float Fixed:: toFloat() const
// {
// 	return static_cast<float>(value) / (1 << fractional);
// }

// Fixed::Fixed(const float value_float)
// {
// 	// std:: cout << "Float constructor called\n";
// 	value = static_cast<int>(value_float * (1 << fractional));
// }

// Fixed::Fixed(const int value_int)
// {
// 	// std:: cout << "Int constructor called\n";
// 	value = value_int << fractional;
// }

// Fixed:: ~Fixed()
// {
// 	// std::cout << "Destructor called" << std:: endl;
// }

// // comparison operators

// bool Fixed:: operator>(const Fixed& _new) const
// {
// 	return value > _new.value;
// }

// bool Fixed:: operator<(const Fixed& _new) const
// {
// 	return value < _new.value;
// }

// bool Fixed:: operator>=(const Fixed& _new) const
// {
// 	return value >= _new.value;
// }

// bool Fixed:: operator<=(const Fixed& _new) const
// {
// 	return value <= _new.value;
// }

// bool Fixed:: operator==(const Fixed& _new) const
// {
// 	return value == _new.value;
// }

// bool Fixed:: operator!=(const Fixed& _new) const
// {
// 	return value != _new.value;
// }

// // arithmetic operators:

// Fixed Fixed:: operator+(const Fixed& _new) const
// {
// 	Fixed tmp(*this);
// 	tmp.value = value + _new.value;
// 	return tmp;
// }

// Fixed Fixed:: operator-(const Fixed& _new) const
// {
// 	Fixed tmp(*this);
// 	tmp.value = value - _new.value;
// 	return tmp;
// }

// Fixed Fixed:: operator*(const Fixed& _new) const
// {
// 	Fixed tmp(*this);
// 	tmp.value = (value * _new.value) >> fractional;
// 	return tmp;
// }

// Fixed Fixed:: operator/(const Fixed& _new) const
// {
// 	Fixed tmp(*this);
// 	tmp.value = (value << fractional) / _new.value;
// 	return tmp;
// }

// // increment function

// Fixed& Fixed:: operator++()
// {
// 	value = value + 1;
// 	return *this;
// }

// Fixed& Fixed:: operator--()
// {
// 	value = value - 1;
// 	return *this;
// }

// Fixed Fixed:: operator++(int)
// {
// 	Fixed tmp(*this);
// 	++(*this);
// 	return tmp;
// }

// Fixed Fixed:: operator--(int)
// {
// 	Fixed tmp(*this);
// 	--(*this);
// 	return tmp;
// }

// // overloaded member functions

// Fixed& Fixed:: min(Fixed& a, Fixed& b)
// {
// 	if (a < b)
// 		return a;
// 	else
// 		return b;
// }


// const Fixed& Fixed:: min(const Fixed& a, const Fixed& b)
// {
// 	if (a < b)
// 		return a;
// 	else
// 		return b;
// }

// Fixed& Fixed:: max(Fixed& a, Fixed& b)
// {
// 	if (a > b)
// 		return a;
// 	else
// 		return b;
// }

// const Fixed& Fixed:: max(const Fixed& a, const Fixed& b)
// {
// 	if (a > b)
// 		return a;
// 	else
// 		return b;
// }
// std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
// {
//     os << fixed.toFloat();
//     return os;
// }
// int main( void ) 
// {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }






#include <iostream>

class Fixed {
private:
    int value;
    static const int fractionalBits = 8;

public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed(const int value_int);
    Fixed(const float value_float);
    ~Fixed();

    Fixed& operator=(const Fixed& other);
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);

    static const Fixed& min(const Fixed& a, const Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
	static Fixed& min(Fixed& a, Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);

    float toFloat() const;
    int toInt() const;
};

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	value = 0;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called\n";
	value = other.value;
}

Fixed::Fixed(const int value_int)
{
	std::cout << "Int constructor called\n";
	value = value_int << fractionalBits;
}

Fixed::Fixed(const float value_float)
{
	std:: cout << "Float constructor called\n";
	value = static_cast<int>(value_float * (1 << fractionalBits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed& Fixed:: operator=(const Fixed& other)
{
	std::cout << "Assignation operator called\n";
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
	// tmp.value = (value << fractionalBits) * other.value;
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



int main() {
    Fixed a;
    Fixed const b(Fixed(5.052f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    return 0;
}
