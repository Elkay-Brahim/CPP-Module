/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:40:40 by bchifour          #+#    #+#             */
/*   Updated: 2023/09/09 19:35:28 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	std::cout << "---------------------" << std::endl;
	std::cout << "-----EX02--ROBOTOMY--" << std::endl;
	std::cout << "---------------------" << std::endl;
	try
	{
		Bureaucrat b1("b1", 1);
		RobotomyRequestForm r1("r1");
		std::cout << r1 << std::endl;
		r1.beSigned(b1);
		std::cout << r1 << std::endl;
		b1.executeForm(r1);
		b1.executeForm(r1);
		b1.executeForm(r1);
		b1.executeForm(r1);
		b1.executeForm(r1);	
		b1.executeForm(r1);
		b1.executeForm(r1);
		b1.executeForm(r1);
		b1.executeForm(r1);
		b1.executeForm(r1);
		b1.executeForm(r1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "---------------------" << std::endl;
	std::cout << "-----EX02--PRESIDENT-" << std::endl;
	std::cout << "---------------------" << std::endl;
	try
	{
		Bureaucrat b1("b1", 1);
		PresidentialPardonForm p1("p1");
		std::cout << p1 << std::endl;
		p1.beSigned(b1);
		std::cout << p1 << std::endl;
		b1.executeForm(p1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "---------------------" << std::endl;
	std::cout << "-----EX02--SHRUBBERY-" << std::endl;
	std::cout << "---------------------" << std::endl;
	try
	{
		Bureaucrat b1("b1", 1);
		ShrubberyCreationForm s1("s1");
		std::cout << s1 << std::endl;
		s1.beSigned(b1);
		std::cout << s1 << std::endl;
		b1.executeForm(s1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}

