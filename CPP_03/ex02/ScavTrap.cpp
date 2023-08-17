/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:12:08 by bchifour          #+#    #+#             */
/*   Updated: 2023/08/17 10:54:35 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	SetHit_points(100);
	SetEnergy_points(50);
	SetAttack_damage(20);
	std::cout << "ScavTrap constructor called of  " << this->name << std::endl;
}

void ScavTrap:: guardGate()
{
	std::cout << "g that ScavTrap is now in Gate keeper mode" << std::endl;
}

void ScavTrap:: attack(const std::string& target)
{
	if (Energy_points > 0 && Hit_points > 0)
	{
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
		Energy_points--;
	}
	else if (this->Energy_points == 0)
		std::cout << this->name  << " ScavTrap can't attack to " << target << " because out of energy! \n";
	else
		std::cout << this->name  << " ScavTrap can't attack because is dead! \n";
}

ScavTrap::ScavTrap()
{
	this->name = "default";
	SetHit_points(100);
	SetEnergy_points(50);
	SetAttack_damage(20);
	std::cout << "ScavTrap created " << this->name << std::endl;
}

ScavTrap:: ScavTrap(const ScavTrap &trap) : ClapTrap()
{
	this->name = trap.name;
	this->Energy_points = trap.Energy_points;
	this->Hit_points = trap.Hit_points;
	this->Attack_damage = trap.Attack_damage;
	std::cout << this->name << "ScavTrap copy created" << std::endl;
}

ScavTrap &ScavTrap:: operator = (const ScavTrap &trap)
{
	std::cout << "Copy assignment operator called of ScavTrap " << std:: endl;
	this->name = trap.name;
	this->Attack_damage = trap.Attack_damage;
	this->Energy_points = trap.Energy_points;
	this->Hit_points = trap.Hit_points;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called of  " << name << std::endl;
	
}