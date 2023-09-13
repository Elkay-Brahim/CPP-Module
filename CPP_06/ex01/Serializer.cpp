/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:48:26 by bchifour          #+#    #+#             */
/*   Updated: 2023/09/12 19:52:23 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(Serializer const &rhs)
{
	*this = rhs;
}

Serializer::~Serializer()
{
}

Serializer &Serializer::operator=(Serializer const &rhs)
{
	(void)rhs;
	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
	uintptr_t raw;

	raw = reinterpret_cast<uintptr_t>(ptr);
	return (raw);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	Data *data;

	data = reinterpret_cast<Data *>(raw);
	return (data);
}
