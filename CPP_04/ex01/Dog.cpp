/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:12:07 by bchifour          #+#    #+#             */
/*   Updated: 2023/08/21 10:50:12 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Constructor Dog called. \n";
	this->type = "Dog";
	this->brain = new Brain();
}

Dog:: Dog(const Dog &copy)
{
	std::cout << "Copy Constructor Dog Called. \n";
	this->type = copy.type;
}

Dog &Dog:: operator = (const Dog &assigment)
{
	std::cout << "Copy Dog Assignment operator called. \n";
	this->type = assigment.type;
	return *this;
}

Dog:: ~Dog()
{
	std::cout << "Destructor Dog called. \n";
	delete brain;
}

void Dog:: makeSound() const
{
	std::cout << "Hu Hu... \n";
}
std::string Dog:: getType() const
{
	return this->type;
}