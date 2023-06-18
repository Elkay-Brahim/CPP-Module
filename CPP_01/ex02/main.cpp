/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:52:29 by bchifour          #+#    #+#             */
/*   Updated: 2023/06/17 16:50:28 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string& stringREF = str;

	std:: cout << &str <<  std:: endl;
	std:: cout << &*stringPTR << std:: endl;
	std:: cout << &stringREF << std:: endl;
	
	std:: cout << str << std:: endl;
	std:: cout << *stringPTR << std:: endl;
	std:: cout << stringREF << std:: endl;

	return 0;
}