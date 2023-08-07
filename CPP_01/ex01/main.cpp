/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 23:01:53 by bchifour          #+#    #+#             */
/*   Updated: 2023/06/18 15:22:42 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int i = 0;
	int N = 4;
	std::string name = "prince";
	Zombie *prince = zombieHorde(N ,name);
	
	while(i < 4)
	{
		prince[i].annonce();3
		
		i++;
	}
	delete []prince;
	return 0;
}