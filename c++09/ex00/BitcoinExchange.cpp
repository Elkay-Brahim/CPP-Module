/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:21:43 by bchifour          #+#    #+#             */
/*   Updated: 2023/10/06 19:28:17 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool is_valid_date(std::string date)
{
	int year, month, day;
	std::istringstream iss(date);
	iss >> year;
	iss.ignore(1);
	iss >> month;
	iss.ignore(1);
	iss >> day;
	if (year < 1000 || year > 3000 || month < 1 || month > 12) {
        return false;
    }

    int monthLength = 31;
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        monthLength = 30;
    } else if (month == 2) {
        monthLength = 28;
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            monthLength = 29;
        }
    }
	return day > 0 && day <= monthLength;
}
std::string _rplace(std::string line, std::string part)
{
	while(1)
	{
		size_t Position = line.find(part);		
		if (Position != std::string::npos)
			line.erase(Position, part.length());
		else
			break;
	}
	return(line);
}
void parse (std::string file)
{
	std::map<std::string, std::string> map;
	std::ifstream inputFile(file);
	std::ifstream dataFile("data.csv");
	std::string line;
    std::string *token = new std::string[2];
	int i = 1;

	if (inputFile.is_open() && dataFile.is_open())
	{
		std::getline(dataFile, line);
		line =_rplace(line, " ");
		line =_rplace(line, "\t");
		try{
			if (line != "date,exchange_rate" || line.empty())
				throw "There's a problem in the header of the csv file.\n";
		}
		catch(const char *e){
			std::cout << e << std::endl;
		}
		while (std::getline(dataFile, line))
		{
			line =_rplace(line, " ");
			line =_rplace(line, "\t");
			std::istringstream iss(line);
			int j = 0;
			while (std::getline(iss, token[j], ','))
				j++;
			if (j == 1)
				token[1] = "";
			try{
					if (is_valid_date(token[0]) == false)
						throw "Error: bad input => " + token[0] + "\n";
					
					if (token[0] < "2009-01-02")
						throw "Error: there's no btc .\n";
					if (token[1].empty())
						throw "Error: bad input => " + token[0] + "\n";
					if (strtod(token[1].c_str(), NULL) < 0)
						throw "Error: not a positive number.\n";
					if(strtod(token[1].c_str(), NULL) > 2147483647)
						throw "Error: too large a number.\n";
				}
			catch(const char *e)
			{
				std::cout << e;
			}
			catch(std::string e)
			{
				std::cout << e;
			}
			catch(...)
			{
				std::cout << "not fond \n";
			}
			map[token[0]]= token[1];
		}
		std::getline(inputFile, line);
		line =_rplace(line, " ");
		line =_rplace(line, "\t");
		try{
			if (line != "date|value" || line.empty())
				throw "There's a problem in the header of the input file.\n";
		}
		catch(const char *e){
			std::cout << e << std::endl;
		}
		while(std::getline(inputFile, line) && i++)
		{
			line =_rplace(line, " ");
			line =_rplace(line, "\t");
			std::istringstream is(line);
			int j = 0;
			while (std::getline(is, token[j], '|'))
				j++;
			if (j == 1)
				token[1] = "";
				
			try{
				if (is_valid_date(token[0]) == false)
					throw "Error: bad input => " + token[0] + "\n";
				
				if (token[0] < "2009-01-02")
					throw "Error: there's no btc \n";
				if (token[1].empty())
					throw "Error: bad input => " + token[0] + "\n";
				if (strtod(token[1].c_str(), NULL) < 0)
					throw "Error: not a positive number\n";
				if(strtod(token[1].c_str(), NULL) > 2147483647)
					throw "Error: too large a number.\n";
				std::cout <<  token[0] << " => " << easyfind(map, token[0])->second << " = ";
				std::cout << strtod(token[1].c_str(), NULL) * strtod(easyfind(map, token[0])->second.c_str(), NULL) << std::endl;
				
			}
			catch(const char *e)
			{
				std::cout << e;
			}
			catch(std::string e)
			{
				std::cout << e;
			}
			catch(...)
			{
				std::cout << "not fond \n";
			}
		}
	}
	delete[] token;
	return;
}