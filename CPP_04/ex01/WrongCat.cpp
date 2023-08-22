/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:08:14 by bchifour          #+#    #+#             */
/*   Updated: 2023/08/18 13:41:39 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "Constructor WrongCat called. \n";
	this->type = "WrongCat";
}

WrongCat:: WrongCat(const WrongCat &copy)
{
	std::cout << "Copy Constructor WrongCat Called. \n";
	this->type = copy.type;
}

WrongCat &WrongCat:: operator = (const WrongCat &assigment)
{
	std::cout << "Copy WrongCat Assignment operator called. \n";
	this->type = assigment.type;
	return *this;
}

WrongCat:: ~WrongCat()
{
	std::cout << "Destructor WrongCat called. \n";
}

void WrongCat:: makeSound() const
{
	std::cout << "Meoooow... \n";
}

std::string WrongCat:: getType() const
{
	return this->type;
}