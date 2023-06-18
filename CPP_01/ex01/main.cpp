/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 23:01:53 by bchifour          #+#    #+#             */
/*   Updated: 2023/06/16 13:23:19 by bchifour         ###   ########.fr       */
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
		prince[i].annonce();
		i++;
	}
	delete []prince;
	return 0;
}