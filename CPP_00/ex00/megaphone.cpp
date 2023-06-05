/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:27:18 by bchifour          #+#    #+#             */
/*   Updated: 2023/05/23 15:30:28 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	int i = 0;
	int j = 1;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while(j < ac)
	{
		while(av[j][i])
		{
			if (av[j][i] && av[j][i] >= 97 && av[j][i] <= 122)
				av[j][i] -= 32;
			i++;
		}
		i = 0;
		j++;
	}
	j = 0;
	while(++j < ac)
		std::cout << av[j];
	std::cout << "" << std::endl;
	return(0);
}