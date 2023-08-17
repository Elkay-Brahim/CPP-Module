/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:15:29 by bchifour          #+#    #+#             */
/*   Updated: 2023/08/15 18:22:32 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	std::cout << "ClapTrap constructor called of  " << this->name << std::endl;
	SetHit_points(10);
	SetEnergy_points(10);
	SetAttack_damage(0);
}
ClapTrap::ClapTrap()
{
	this->name = "default";
	std::cout << "ClapTrap created " << this->name << std::endl;
	SetHit_points(10);
	SetEnergy_points(10);
	SetAttack_damage(0);
}

ClapTrap:: ClapTrap(const ClapTrap &trap)
{
	std::cout << this->name << "ClapTrap copy created" << std::endl;
	this->name = trap.name;  //check;
	SetHit_points(trap.Hit_points);
	SetEnergy_points(trap.Energy_points);
	SetAttack_damage(trap.Attack_damage);
}
ClapTrap &ClapTrap:: operator = (const ClapTrap &trap)
{
	std::cout << "Copy assignment operator called" << std:: endl;
	this->name = trap.name;
	this->Attack_damage = trap.Attack_damage;
	this->Energy_points = trap.Energy_points;
	this->Hit_points = trap.Hit_points;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called of  " << name << std::endl;
	
}
void ClapTrap::SetHit_points(int new_Value)
{
	Hit_points = new_Value;
}

void ClapTrap::SetAttack_damage(int new_Value)
{
	Attack_damage = new_Value;
}

void ClapTrap::SetEnergy_points(int new_Value)
{
	Energy_points = new_Value;
}

void ClapTrap:: attack(const std::string& target)
{
	if (Energy_points > 0 && Hit_points > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
		Energy_points--;
	}
	else if (this->Energy_points == 0)
		std::cout << this->name  << " ClapTrap can't attack to " << target << " because out of energy! \n";
	else
		std::cout << this->name  << " ClapTrap can't attack because is dead! \n";
}

void ClapTrap:: takeDamage(unsigned int amount)
{
	if (this->Hit_points == 0)
	{
		std::cout << this->name << " ClapTrap can't take damage because is dead!\n";
		return ;
	}
	if (amount > this->Hit_points)
		amount = this->Hit_points;
	this->Hit_points -= amount;
	if (this->Hit_points > 0)
		std::cout << this->name << " ClapTrap hase taken " << amount << " damage \n";
	else
		std::cout << this->name << " ClapTrap hase taken " << amount << " damage and died! \n";
}

void ClapTrap:: beRepaired(unsigned int amount)
{
	if (Hit_points > 0 && Energy_points > 0)
	{
		std::cout << "ClapTrap " << name << " is being repaired and gains " << amount << " hit points!" << std::endl;
		Hit_points += amount;
		this->Energy_points -= 1;
	}
	else if (this->Energy_points == 0)
		std::cout << this->name  << " attemps to repair itself but no energy left \n";
	else
		std::cout << this->name  << " ClapTrap can't repaired because is dead! \n";
}