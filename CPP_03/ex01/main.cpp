/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:10:44 by bchifour          #+#    #+#             */
/*   Updated: 2023/08/16 11:58:39 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

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