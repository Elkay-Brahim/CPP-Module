/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:41:31 by bchifour          #+#    #+#             */
/*   Updated: 2023/08/22 16:42:42 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	this->_nb = 0;
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & copy)
{
	*this = copy;
}

MateriaSource & MateriaSource::operator=(MateriaSource const & assign)
{
	if (this != &assign)
	{
		for (int i = 0; i < 4; i++)
			this->_materia[i] = assign._materia[i];
		this->_nb = assign._nb;
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete this->_materia[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (this->_nb < 4)
	{
		this->_materia[this->_nb] = m;
		this->_nb++;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < this->_nb; i++)
	{
		if (this->_materia[i]->getType() == type)
			return (this->_materia[i]->clone());
	}
	return (NULL);
}