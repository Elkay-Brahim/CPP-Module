/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:36:37 by bchifour          #+#    #+#             */
/*   Updated: 2023/08/21 11:28:45 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal
{
	protected :
		std::string type;
	public :
		Animal();
		Animal(const Animal &copy);
		Animal &operator = (const Animal &assigment);
		virtual ~Animal();
		virtual void makeSound() const;
		std::string getType() const;
};