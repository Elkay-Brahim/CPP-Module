/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:37:27 by bchifour          #+#    #+#             */
/*   Updated: 2023/08/18 13:39:14 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Constructor WrongAnimal called. \n";
	this->type = "WrongAnimal";
}

WrongAnimal:: WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "Copy Constructor WrongAnimal Called. \n";
	this->type = copy.type;
}

WrongAnimal &WrongAnimal:: operator = (const WrongAnimal &assigment)
{
	std::cout << "Copy WrongAnimal Assignment operator called. \n";
	this->type = assigment.type;
	return *this;
}

WrongAnimal:: ~WrongAnimal()
{
	std::cout << "Destructor WrongAnimal called. \n";
}

void WrongAnimal:: makeSound() const
{
	std::cout << "I don't have specific sound. \n";
}

std::string WrongAnimal:: getType() const
{
	return this->type;
}