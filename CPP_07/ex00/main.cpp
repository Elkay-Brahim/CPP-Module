/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:53:57 by bchifour          #+#    #+#             */
/*   Updated: 2023/09/15 17:11:24 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc.hpp"

int main()
{
	int a = 2;
	int b = 3;
	std::cout << "a = " << a << " b = " << b << std::endl;
	swap(a, b);
	std::cout << "a = " << a << " b = " << b << std::endl;
	std::cout << "min(a, b) = " << min(a, b) << std::endl;
	std::cout << "max(a, b) = " << max(a, b) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "c = " << c << " d = " << d << std::endl;
	swap(c, d);
	std::cout << "c = " << c << " d = " << d << std::endl;
	std::cout << "min(c, d) = " << min(c, d) << std::endl;
	std::cout << "max(c, d) = " << max(c, d) << std::endl;
	return (0);
	
}