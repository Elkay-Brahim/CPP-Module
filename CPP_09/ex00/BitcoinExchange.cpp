/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:21:43 by bchifour          #+#    #+#             */
/*   Updated: 2023/09/23 10:35:08 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <map>
#include <iostream>
#include <algorithm>
#include <curlpp/cURLpp.hpp>



BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::getRates(std::string currency)
{
	std::string url = "https://api.coindesk.com/v1/bpi/currentprice/";
	url += currency;
	url += ".json";
	std::string response = curlpp::options::Url(url).perform();
	std::string error = response.substr(0, 6);
	if (error == "{\"time")
	{
		std::cout << "Error: Invalid currency" << std::endl;
		return ;
	}
	std::string base = response.substr(9, 3);
	std::string date = response.substr(23, 10);
	std::string rate = response.substr(56, 6);
	_rates[base] = std::stod(rate);
	_base = base;
	_date = date;
}

void BitcoinExchange::printRates()
{
	std::cout << "Base: " << _base << std::endl;
	std::cout << "Date: " << _date << std::endl;
	std::cout << "Rates: " << std::endl;
	for (auto it = _rates.begin(); it != _rates.end(); it++)
		std::cout << it->first << ": " << it->second << std::endl;
}

