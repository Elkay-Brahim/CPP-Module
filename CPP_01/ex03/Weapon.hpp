/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 00:49:54 by bchifour          #+#    #+#             */
/*   Updated: 2023/06/17 16:52:26 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon(const std::string& weapon_type) : type(weapon_type) {}
		const std::string& getType() const;
		void setType(std::string type);
};