/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:42:09 by bchifour          #+#    #+#             */
/*   Updated: 2023/06/16 01:19:53 by bchifour         ###   ########.fr       */
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

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(std::string name);
		void guardGate();
};

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	SetHit_points(100);
	SetEnergy_points(50);
	SetAttack_damage(20);
	std::cout << "ScavTrap constructor called of  " << name << std::endl;
}

void ScavTrap:: guardGate()
{
	std::cout << "g that ScavTrap is now in Gate keeper mode" << std::endl;
}


ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	SetHit_points(10);
	SetEnergy_points(10);
	SetAttack_damage(0);
	std::cout << "ClapTrap constructor called of  " << this->name << std::endl;
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

	std:: cout << "\n";

	ScavTrap scavTrap("Prance");
	
	scavTrap.attack("Enemy...");
	scavTrap.takeDamage(3);
    scavTrap.beRepaired(2);
    scavTrap.attack("Enemy");
    scavTrap.takeDamage(12);
    scavTrap.beRepaired(5);
    scavTrap.attack("Enemy");

    return 0;
}