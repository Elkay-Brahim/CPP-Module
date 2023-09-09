/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:32:03 by bchifour          #+#    #+#             */
/*   Updated: 2023/09/06 15:59:22 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int main(int ac, char **av)
{
	if (ac == 4)
	{
		std::string fileName = av[1];
		std::string s1 = av[2];
		std::string s2 = av[3];
		std::string fill = av[1];
		fill = fill.substr(0, fill.length())+".replace";
		std::ifstream inputFile(fileName);
		std::string line;
		size_t foundPosition;
		std::ofstream outputFile(fill, std::ios::out | std::ios::trunc);
		if (inputFile.is_open())
		{
			while (std::getline(inputFile, line))
			{
				while(1)
				{
					foundPosition = line.find(s1, foundPosition);
					if (foundPosition != std::string::npos)
					{
						line.erase(foundPosition, s1.length());
						line.insert(foundPosition, av[3]);
						
					}
					else
						break ;
				}
				outputFile << line << std::endl;
			}
		}
		else
			std:: cout << "Error" << std :: endl;
		inputFile.close();
	}
	else 
		std::cout<< "Error" << std::endl;
}