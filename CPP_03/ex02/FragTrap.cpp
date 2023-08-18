/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:43:19 by bchifour          #+#    #+#             */
/*   Updated: 2023/08/17 17:15:26 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
{
	SetName(name);
	SetHit_points(100);
	SetEnergy_points(100);
	SetAttack_damage(30);
	std::cout << "FragTrap constructor called of  " << GetName() << std::endl;
}

FragTrap::FragTrap()
{
	SetName("default");
	SetHit_points(100);
	SetEnergy_points(100);
	SetAttack_damage(30);
	std::cout << "FragTrap created " << GetName() << std::endl;
}

FragTrap:: FragTrap(const FragTrap &trap) : ClapTrap()
{
	SetName(trap.GetName());
	SetHit_points(trap.GetHit_points());
	SetEnergy_points(trap.GetEnergy_points());
	SetAttack_damage(trap.GetAttack_damage());
	std::cout << GetName() << "FragTrap copy created" << std::endl;
}

FragTrap &FragTrap:: operator = (const FragTrap &trap)
{
	std::cout << "Copy assignment operator called of FragTrap " << std:: endl;
	SetName(trap.GetName());
	SetHit_points(trap.GetHit_points());
	SetEnergy_points(trap.GetEnergy_points());
	SetAttack_damage(trap.GetAttack_damage());
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called of  " << GetName() << std::endl;
	
}

void FragTrap:: highFivesGuys(void)
{
	std::cout << "FragTrap : high fives " << GetName() << std::endl;
}