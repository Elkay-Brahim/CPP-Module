/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:10:44 by bchifour          #+#    #+#             */
/*   Updated: 2023/08/14 19:06:47 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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