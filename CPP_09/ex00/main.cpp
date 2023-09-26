/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:59:57 by bchifour          #+#    #+#             */
/*   Updated: 2023/09/24 10:32:26 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
std::map<std::string, std::string> parse (std::string file)
{
	std::map<std::string, std::string> map;
	std::ifstream inputFile(file);
	std::ifstream dataFile("data.csv");
	std::string line;
    std::string *token = new std::string[2];
	int i = 1;

	if (inputFile.is_open() && dataFile.is_open())
	{
		while (std::getline(dataFile, line))
		{
			std::istringstream iss(line);
			int j = 0;
			while (std::getline(iss, token[j], ','))
				j++;
			map[token[0]]= token[1];
		}
		while(std::getline(inputFile, line) && i++)
		{
			line =_rplace(line, " ");
			line =_rplace(line, "\t");
			if (line != "date|value" && i == 2)
				exit(1);
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
					throw "Error: mzl ma kayn btc \n";
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
	return (map);
	
}

int main(int argc, char **argv)
{
	std::map<std::string, double> map;
	if (argc != 2)
	{
		std::cout << "Usage: ./bitcoin [currency]" << std::endl;
		return 1;
	}
	try
	{
		parse(argv[1]);
		
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}