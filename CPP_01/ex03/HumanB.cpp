/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:25:22 by bchifour          #+#    #+#             */
/*   Updated: 2023/06/17 16:56:35 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

 HumanB::HumanB(const std::string& human_name)
{
	name = human_name;
	weapon = nullptr;
} 
void HumanB::attack() const
{
	if (weapon != nullptr)
	{
		std:: cout << name << " attacks with their " << weapon->getType() << std::endl;
	}
	else
	{
		std:: cout  << name << " is unarmed and cannot attack " << std::endl;
	}
}

void HumanB:: setWeapon(Weapon& type)
{
	weapon = &type;
}