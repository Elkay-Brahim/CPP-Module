/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:59:44 by bchifour          #+#    #+#             */
/*   Updated: 2023/08/18 13:42:55 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public :
		WrongCat();
		WrongCat(const WrongCat &copy);
		WrongCat &operator = (const WrongCat &assigment);
		~WrongCat();
		void makeSound() const;
		std::string getType() const;
};