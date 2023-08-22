/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:26:03 by bchifour          #+#    #+#             */
/*   Updated: 2023/08/22 16:56:24 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	this->type = "default";
}

AMateria::AMateria(std::string const & type)
{
	this->type = type;
}

AMateria::~AMateria()
{
}

AMateria::AMateria(AMateria const & copy)
{
	this->type = copy.type;
}

AMateria & AMateria::operator=(AMateria const & assign)
{
	this->type = assign.type;
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}
