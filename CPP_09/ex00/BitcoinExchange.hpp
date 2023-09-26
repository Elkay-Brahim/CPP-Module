/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:35:00 by bchifour          #+#    #+#             */
/*   Updated: 2023/09/23 10:34:09 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>



class BitcoinExchange 
{
	private:
		std::map<std::string, double> _rates;
		std::string _base;
		std::string _date;
	public:
		BitcoinExchange();
		~BitcoinExchange();
		void getRates(std::string currency);
		void printRates();
};