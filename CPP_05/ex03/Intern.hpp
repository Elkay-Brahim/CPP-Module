/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:18:46 by bchifour          #+#    #+#             */
/*   Updated: 2023/09/09 13:47:09 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
	private:
		Form *createShrubberyCreationForm(std::string const target);
		Form *createPresidentialPardonForm(std::string const target);
		Form *createRobotomyRequestForm(std::string const target);
	public:
		Intern();
		Intern(Intern const &copy);
		~Intern();
		Intern &operator=(Intern const &assign);
		Form *makeForm(std::string const form, std::string const target);
		class UnknownFormException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};