/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:59:44 by bchifour          #+#    #+#             */
/*   Updated: 2023/08/21 11:02:53 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private :
		Brain *brain;
	public :
		Cat();
		Cat(const Cat &copy);
		Cat &operator = (const Cat &assigment);
		~Cat();
		void makeSound() const;
		std::string getType() const;
};