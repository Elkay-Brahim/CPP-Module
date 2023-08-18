/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:13:58 by bchifour          #+#    #+#             */
/*   Updated: 2023/08/17 15:50:47 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <iostream>

class  ClapTrap
{
	private:
		std::string name;
		unsigned int Hit_points;
		unsigned int Energy_points;
		unsigned int Attack_damage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &trap);
		ClapTrap &operator = (const ClapTrap &trap);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void SetHit_points(int new_Value);
		void SetEnergy_points(int new_Value);
		void SetAttack_damage(int new_Value);
		void SetName(std::string name);
		std::string GetName(void) const;
		unsigned int GetEnergy_points(void)const;
		unsigned int GetAttack_damage(void)const;
		unsigned int GetHit_points(void)const;
};