/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:52:29 by bchifour          #+#    #+#             */
/*   Updated: 2023/05/29 17:07:01 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string ptr = str;
	std::string& ref = str;

	std:: cout << &str <<  std:: endl;
	std:: cout << &ptr << std:: endl;
	std:: cout << &ref << std:: endl;
	
	std:: cout << str << std:: endl;
	std:: cout << ptr << std:: endl;
	std:: cout << ref << std:: endl;

	return 0;
}