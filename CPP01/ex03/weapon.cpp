/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:24:39 by bchifour          #+#    #+#             */
/*   Updated: 2023/05/31 18:49:27 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Weapon
{
	private:
		std::string type_weapon;
	public:
		Weapon(const std::string& weapon_type) : type_weapon(weapon_type) {}
		const std::string& gettype() const;
		void setType(std::string type);
};

class HumanA
{
	private:
		std::string name;
		Weapon weapon;
	public:
		HumanA(const std::string& human_name, const Weapon& weapon_type) : name(human_name), weapon(weapon_type) {}
		void attack() const;
};

class HumanB
{
	private:
		std::string name;
		Weapon *weapon;
	public:
		HumanB(const std::string& human_name) : name(human_name), weapon(nullptr) {}
		void setWeapon(Weapon& weapon_type);
		void attack() const;
};


const std::string& Weapon:: gettype() const
{
	return type_weapon;
}

void  Weapon:: setType(std::string type)
{
	type_weapon = type;
}
void HumanB:: setWeapon(Weapon& type)
{
	weapon = &type;
}
void HumanA:: attack() const
{
	std:: cout << name << " attacks with their " << weapon.gettype() << std::endl;
}

void HumanB::attack() const
{
	if (weapon != nullptr)
	{
		std:: cout << name << " attacks with their " << weapon->gettype() << std::endl;
	}
	else
	{
		std:: cout  << name << " is unarmed and cannot attack " << std::endl;
	}
}


int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}