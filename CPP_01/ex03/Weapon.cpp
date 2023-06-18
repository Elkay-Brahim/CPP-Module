/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:24:39 by bchifour          #+#    #+#             */
/*   Updated: 2023/06/17 16:53:06 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Weapon.hpp"

const std::string& Weapon:: getType() const
{
	return type;
}

void  Weapon:: setType(std::string type)
{
	this->type = type;
}
