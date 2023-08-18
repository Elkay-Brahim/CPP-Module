/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:57:57 by bchifour          #+#    #+#             */
/*   Updated: 2023/08/18 13:33:16 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
	public :
		Dog();
		Dog(const Dog &copy);
		Dog &operator = (const Dog &assigment);
		~Dog();
		void makeSound() const;
		std::string getType() const;
};