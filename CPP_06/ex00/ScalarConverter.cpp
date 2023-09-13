/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:08:06 by bchifour          #+#    #+#             */
/*   Updated: 2023/09/12 20:09:03 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(std::string str) : _str(str)
{
	this->check = false;
}

ScalarConverter::ScalarConverter(ScalarConverter const &rhs)
{
	*this = rhs;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
	if (this != &rhs)
	{
		this->check = rhs.check;
		this->_str = rhs._str;
	}
	return (*this);
}

void ScalarConverter::convert()
{
	std::cout << "float: ";
	try
	{
		this->toFloat();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "char: ";
	try
	{
		this->toChar();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "int: ";
	try
	{
		this->toInt();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "double: ";
	try
	{
		this->toDouble();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void ScalarConverter::toChar()
{
	long long i;
	char *end;
	if(this->check == false)
		throw ScalarConverter::ImpossibleException();
	i = strtol(this->_str.c_str(), &end, 10);
	if (this->_str.length() > 11)
		throw ScalarConverter::ImpossibleException();
	if (this->_str.length() == 1 && !isdigit(this->_str[0]))
		i = static_cast<int>(this->_str[0]);
	if (i > 127 || i < -128)
		throw ScalarConverter::ImpossibleException();
	if (i < 32 || i > 126)
		throw ScalarConverter::NonDisplayableException();
	std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
}

void ScalarConverter::toInt()
{
	long long i;
	char *end;
	if(this->check == false)
		throw ScalarConverter::ImpossibleException();
	i = strtol(this->_str.c_str(), &end, 10);
	if (this->_str.length() > 11)
		throw ScalarConverter::ImpossibleException();
	if (this->_str.length() == 1 && !isdigit(this->_str[0]))
	{
		std::cout << static_cast<int>(this->_str[0]) << std::endl;
		return;
	}
	if (i > 2147483647 || i < -2147483648)
		throw ScalarConverter::ImpossibleException();
	std::cout << i << std::endl;
}

void ScalarConverter::toFloat()
{
	float f;
	char *end;
	f = strtof(this->_str.c_str(), &end);
	if (this->_str.length() > 11)
		throw ScalarConverter::ImpossibleException();
	if (this->_str.length() == 1 && !isdigit(this->_str[0]))
	{
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(this->_str[0]) << "f" << std::endl;
		this->check = true;
		return;
	}
	if (*end != '\0')
	{
		if(*end != 'f' && end[1] == '\0')
			throw ScalarConverter::ImpossibleException();
		if (*end == 'f' && end[1] != '\0')
			throw ScalarConverter::ImpossibleException();
		if( *end != 'f' && end[1] != '\0')
			throw ScalarConverter::ImpossibleException();
		this->check = true;
	}
	if (f > std::numeric_limits<float>::max() || f < std::numeric_limits<float>::min())
		throw ScalarConverter::ImpossibleException();
	this->check = true;
	std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	
}

void ScalarConverter::toDouble()
{
	double d;
	char *end;
	d = strtod(this->_str.c_str(), &end);
	if(this->check == false)
		throw ScalarConverter::ImpossibleException();
	if (this->_str.length() > 11)
		throw ScalarConverter::ImpossibleException();
	if (this->_str.length() == 1 && !isdigit(this->_str[0]))
	{
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(this->_str[0]) << std::endl;
		return;
	}
	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		throw ScalarConverter::ImpossibleException();
	std::cout << std::fixed << std::setprecision(1) << d << std::endl;
	
	
}

const char *ScalarConverter::ImpossibleException::what() const throw()
{
	return ("impossible");
}

const char *ScalarConverter::NonDisplayableException::what() const throw()
{
	return ("Non displayable");
}
