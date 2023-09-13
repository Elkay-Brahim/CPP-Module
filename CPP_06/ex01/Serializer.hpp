/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:46:25 by bchifour          #+#    #+#             */
/*   Updated: 2023/09/11 12:09:21 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <cmath>
#include <iomanip>
#include "Data.hpp"

class Serializer
{
	public:
		Serializer();
		Serializer(Serializer const &rhs);
		~Serializer();
		Serializer &operator=(Serializer const &rhs);
		uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);
};