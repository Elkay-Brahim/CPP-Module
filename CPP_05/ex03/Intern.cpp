/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:20:46 by bchifour          #+#    #+#             */
/*   Updated: 2023/09/21 12:28:12 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	return ;
}

Intern::Intern(Intern const &copy)
{
	*this = copy;
	return ;
}

Intern::~Intern()
{
	return ;
}

Intern &Intern::operator=(Intern const &assign)
{
	(void)assign;
	return (*this);
}

Form *Intern::makeForm(std::string const form, std::string const target)
{
	Form *f[] = {createShrubberyCreationForm(target), createPresidentialPardonForm(target), createRobotomyRequestForm(target)};
	std::string forms[3] = {"ShrubberyCreationForm", "PresidentialPardonForm", "RobotomyRequestForm"};
	for (int i = 0; i < 3; i++)
	{
		if (form == forms[i])
		{
			std::cout << "Intern creates " << *f[i] << std::endl;
			for (int j = 0; j < 3; j++)
			{
				if (j != i)
					delete f[j];
			}
			return (f[i]);
		}
	}
	for(int i = 0; i < 3; i++)
		delete f[i];
	throw Intern::UnknownFormException();
}

Form *Intern::createShrubberyCreationForm(std::string const target)
{
	return (new ShrubberyCreationForm(target));
}

Form *Intern::createPresidentialPardonForm(std::string const target)
{
	return (new PresidentialPardonForm(target));
}

Form *Intern::createRobotomyRequestForm(std::string const target)
{
	return (new RobotomyRequestForm(target));
}

const char *Intern::UnknownFormException::what() const throw()
{
	return ("Unknown form");
}

