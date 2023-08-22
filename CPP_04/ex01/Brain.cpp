/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:44:11 by bchifour          #+#    #+#             */
/*   Updated: 2023/08/21 11:08:21 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Constructor Brain called. \n";
}

Brain:: Brain(const Brain &copy)
{
	int i = 0;
	std::cout << "Copy Constructor Brain Called. \n";
	while (i++ < 100)
		this->ideas[i] = copy.ideas[i];
	
}

Brain &Brain:: operator = (const Brain &assigment)
{
	int i = 0;
	std::cout << "Copy Brain Assignment operator called. \n";
	while (i++ < 100)
		this->ideas[i] = assigment.ideas[i];
	return *this;
}

Brain:: ~Brain()
{
	std::cout << "Destructor Brain called. \n";
}