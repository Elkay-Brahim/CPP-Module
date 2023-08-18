/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:59:44 by bchifour          #+#    #+#             */
/*   Updated: 2023/08/18 13:33:05 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
	public :
		Cat();
		Cat(const Cat &copy);
		Cat &operator = (const Cat &assigment);
		~Cat();
		void makeSound() const;
		std::string getType() const;
};