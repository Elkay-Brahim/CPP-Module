/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:32:03 by bchifour          #+#    #+#             */
/*   Updated: 2023/05/31 20:03:16 by bchifour         ###   ########.fr       */
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
		std::ifstream inputFile(fileName);
		std::string line;
		size_t foundPosition;
		std::ofstream outputFile("out.txt", std::ios::out | std::ios::trunc);
		if (inputFile.is_open())
		{
			while (std::getline(inputFile, line))
			{
				while(1)
				{
					foundPosition = line.find(s1);
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