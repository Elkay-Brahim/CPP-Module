/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:25:06 by bchifour          #+#    #+#             */
/*   Updated: 2023/06/17 16:56:22 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

void HumanA:: attack() const
{
	std:: cout << name << " attacks with their " << weapon.getType() << std::endl;
}

HumanA:: HumanA(const std::string& human_name, const Weapon& weapon_type) : name(human_name), weapon(weapon_type)
{
}
