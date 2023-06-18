/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 22:56:58 by bchifour          #+#    #+#             */
/*   Updated: 2023/06/17 17:09:01 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie:: annonce(void)
{
	std:: cout << name << ": BraiiiiiiinnnzzzZ..." << std:: endl;
}

void Zombie:: setName(std::string name)
{
	this->name = name;
}
Zombie:: ~Zombie()
{
	std:: cout << "Destroy: " << name << std :: endl;
}

Zombie:: Zombie(){};

