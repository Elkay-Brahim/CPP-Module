/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:39:49 by bchifour          #+#    #+#             */
/*   Updated: 2023/08/22 16:40:08 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* _materia[4];
		int _nb;
	public:
		MateriaSource();
		MateriaSource(MateriaSource const & copy);
		MateriaSource & operator=(MateriaSource const & assign);
		~MateriaSource();
		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
};