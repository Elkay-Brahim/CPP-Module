/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:43:19 by bchifour          #+#    #+#             */
/*   Updated: 2023/08/17 11:04:07 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
{
	this->name = name;
	SetHit_points(100);
	SetEnergy_points(100);
	SetAttack_damage(30);
	std::cout << "FragTrap constructor called of  " << name << std::endl;
}

FragTrap::FragTrap()
{
	this->name = "default";
	SetHit_points(100);
	SetEnergy_points(100);
	SetAttack_damage(30);
	std::cout << "FragTrap created " << this->name << std::endl;
}

FragTrap:: FragTrap(const FragTrap &trap) : ClapTrap()
{
	this->name = trap.name;
	this->Energy_points = trap.Energy_points;
	this->Hit_points = trap.Hit_points;
	this->Attack_damage = trap.Attack_damage;
	std::cout << this->name << "FragTrap copy created" << std::endl;
}

FragTrap &FragTrap:: operator = (const FragTrap &trap)
{
	std::cout << "Copy assignment operator called of FragTrap " << std:: endl;
	this->name = trap.name;
	this->Attack_damage = trap.Attack_damage;
	this->Energy_points = trap.Energy_points;
	this->Hit_points = trap.Hit_points;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called of  " << name << std::endl;
	
}

void FragTrap:: highFivesGuys(void)
{
	std::cout << "FragTrap : high fives " << name << std::endl;
}