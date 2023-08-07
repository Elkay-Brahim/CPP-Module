/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:11:00 by bchifour          #+#    #+#             */
/*   Updated: 2023/08/07 15:28:29 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

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
		~Fixed();
		float toFloat() const;
		int toInt() const;
};
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
