/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:10:44 by bchifour          #+#    #+#             */
/*   Updated: 2023/06/16 00:59:08 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class  ClapTrap
{
	private:
		std::string name;
		int Hit_points;
		int Energy_points;
		int Attack_damage;
	protected:
		void SetHit_points(int new_Value);
		void SetEnergy_points(int new_Value);
		void SetAttack_damage(int new_Value);
	public:
		ClapTrap(std::string name);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	SetHit_points(10);
	SetEnergy_points(10);
	SetAttack_damage(0);
	std::cout << "ClapTrap constructor called of  " << this->name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called of  " << name << std::endl;
	
}

void ClapTrap:: attack(const std::string& target)
{
	if (Energy_points > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
		Energy_points--;
	}
	else
		std::cout << "ClapTrap " << name << " has no energy left to attack!" << std::endl;
}

void ClapTrap:: takeDamage(unsigned int amount)
{
	if (Hit_points > 0)
	{
		std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
		Hit_points -= amount;
	}
	else
		std::cout << "ClapTrap " << name << " has no hit points left!" << std::endl;
}

void ClapTrap:: beRepaired(unsigned int amount)
{
	if (Hit_points > 0)
	{
		std::cout << "ClapTrap " << name << " is being repaired and gains " << amount << " hit points!" << std::endl;
		Hit_points += amount;
	}
	else
		std::cout << "ClapTrap " << name << " cannot be repaired as it has no hit points left!" << std::endl;
}

int main()
{
    ClapTrap clapTrap("Clappy");

    clapTrap.attack("Enemy");
    clapTrap.takeDamage(3);
    clapTrap.beRepaired(2);
    clapTrap.attack("Enemy");
    clapTrap.takeDamage(12);
    clapTrap.beRepaired(5);
    clapTrap.attack("Enemy");

    return 0;
}