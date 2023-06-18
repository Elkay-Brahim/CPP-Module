/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 01:19:33 by bchifour          #+#    #+#             */
/*   Updated: 2023/06/13 01:27:22 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl harl;
    if (ac != 2)
    {
        std::cout << "Usage: ./ex06.out [DEBUG, INFO, WARNING, ERROR]" << std::endl;
        return 1;
    }
    harl.complain(av[1]);
	return 0;
}