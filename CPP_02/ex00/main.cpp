/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 00:05:48 by bchifour          #+#    #+#             */
/*   Updated: 2023/06/05 00:19:10 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostram>

class FixedPoint
{
	private:
		int value;
		static const int fractional = 8;
	public:
		FixedPoint();
		FixedPoint(const FixedPoint& new);
		FixedPoint& operator=(const FixedPoint& new);
		~FixedPoint() {}
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

FixedPoint::FixedPoint()
{
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

FixedPoint:: FixedPoint(const FixedPoint& new)
{
	
}