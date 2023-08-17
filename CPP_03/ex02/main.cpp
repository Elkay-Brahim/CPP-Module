/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:10:44 by bchifour          #+#    #+#             */
/*   Updated: 2023/08/17 11:07:43 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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


    std:: cout << "\n";

    FragTrap fragTrap("Prance");
	
	fragTrap.attack("Enemy...");
	fragTrap.takeDamage(3);
    fragTrap.beRepaired(2);
    fragTrap.attack("Enemy");
    fragTrap.takeDamage(12);
    fragTrap.beRepaired(5);
    fragTrap.attack("Enemy");

    return 0;
}