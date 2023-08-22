/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:08:14 by bchifour          #+#    #+#             */
/*   Updated: 2023/08/21 10:50:38 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Constructor Cat called. \n";
	this->type = "Cat";
	this->brain = new Brain();
}

Cat:: Cat(const Cat &copy)
{
	std::cout << "Copy Constructor Cat Called. \n";
	this->type = copy.type;
}

Cat &Cat:: operator = (const Cat &assigment)
{
	std::cout << "Copy Cat Assignment operator called. \n";
	this->type = assigment.type;
	return *this;
}

Cat:: ~Cat()
{
	std::cout << "Destructor Cat called. \n";
	delete brain;
}

void Cat:: makeSound() const
{
	std::cout << "Meoooow... \n";
}

std::string Cat:: getType() const
{
	return this->type;
}