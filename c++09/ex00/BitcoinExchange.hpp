/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:35:00 by bchifour          #+#    #+#             */
/*   Updated: 2023/10/06 17:12:45 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

void parse (std::string file);

template <typename T>
typename T::iterator easyfind(T &container, std::string key)
{
	typename T::iterator it = container.begin();
	typename T::iterator it_tmp = container.begin();

	while(it != container.end())
	{
		if (it->first == key)
			return(it);
		if (it->first > key && it_tmp->first < key)
			return(it_tmp);
		it_tmp = it;
		it++;
	}
	throw std::exception();
	return (container.end());
}