/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:08:43 by bchifour          #+#    #+#             */
/*   Updated: 2023/08/18 13:33:38 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Constructor Animal called. \n";
	this->type = "Animal";
}

Animal:: Animal(const Animal &copy)
{
	std::cout << "Copy Constructor Animal Called. \n";
	this->type = copy.type;
}

Animal &Animal:: operator = (const Animal &assigment)
{
	std::cout << "Copy Animal Assignment operator called. \n";
	this->type = assigment.type;
	return *this;
}

Animal:: ~Animal()
{
	std::cout << "Destructor Animal called. \n";
}

void Animal:: makeSound() const
{
	std::cout << "I don't have specific sound. \n";
}

std::string Animal:: getType() const
{
	return this->type;
}
