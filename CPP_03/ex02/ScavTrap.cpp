/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:12:08 by bchifour          #+#    #+#             */
/*   Updated: 2023/08/17 17:13:04 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
{
	SetName(name);
	SetHit_points(100);
	SetEnergy_points(50);
	SetAttack_damage(20);
	std::cout << "ScavTrap constructor called of  " << GetName() << std::endl;
}

void ScavTrap:: guardGate()
{
	std::cout << "g that ScavTrap is now in Gate keeper mode" << std::endl;
}

void ScavTrap:: attack(const std::string& target)
{
	unsigned int i;
	i = 0;
	if (GetEnergy_points() > 0 && GetHit_points() > 0)
	{
		std::cout << "ScavTrap " << GetName() << " attacks " << target << ", causing " << GetAttack_damage() << " points of damage!" << std::endl;
		i = GetEnergy_points();
		i--;
		SetEnergy_points(i);
	}
	else if (GetEnergy_points() == 0)
		std::cout << GetName()  << " ScavTrap can't attack to " << target << " because out of energy! \n";
	else
		std::cout << GetName()  << " ScavTrap can't attack because is dead! \n";
}

ScavTrap::ScavTrap()
{
	SetName("default");
	SetHit_points(100);
	SetEnergy_points(50);
	SetAttack_damage(20);
	std::cout << "ScavTrap created " << GetName() << std::endl;
}

ScavTrap:: ScavTrap(const ScavTrap &trap)
{
	SetName(trap.GetName());
	SetHit_points(trap.GetHit_points());
	SetEnergy_points(trap.GetEnergy_points());
	SetAttack_damage(trap.GetAttack_damage());
	std::cout << GetName() << "ScavTrap copy created" << std::endl;
}

ScavTrap &ScavTrap:: operator = (const ScavTrap &trap)
{
	std::cout << "Copy assignment operator called of ScavTrap " << std:: endl;
	SetName(trap.GetName());
	SetHit_points(trap.GetHit_points());
	SetEnergy_points(trap.GetEnergy_points());
	SetAttack_damage(trap.GetAttack_damage());
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called of  " << GetName() << std::endl;
}