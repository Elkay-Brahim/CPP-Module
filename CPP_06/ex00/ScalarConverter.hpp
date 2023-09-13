/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:05:53 by bchifour          #+#    #+#             */
/*   Updated: 2023/09/11 17:59:36 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <limits>
#include <sstream>

class ScalarConverter
{
	private:
		std::string _str;
		bool check;
	public:
		ScalarConverter(std::string str);
		ScalarConverter(ScalarConverter const &rhs);
		~ScalarConverter();
		ScalarConverter &operator=(ScalarConverter const &rhs);
		void convert();
		void toChar();
		void toInt();
		void toFloat();
		void toDouble();
		class ImpossibleException : public std::exception
		{
			virtual const char *what() const throw();
		};
		class NonDisplayableException : public std::exception
		{
			virtual const char *what() const throw();
		};
};