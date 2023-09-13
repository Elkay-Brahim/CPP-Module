/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:07:14 by bchifour          #+#    #+#             */
/*   Updated: 2023/09/12 19:54:07 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Serializer s;
	Data *data;
	uintptr_t raw;

	data = new Data;
	data->str = "Hello";
	raw = s.serialize(data);
	std::cout << "raw: " << raw << std::endl;
	data = s.deserialize(raw);
	std::cout << "data->s1: " << data->str << std::endl;
	delete data;
	return (0);
}