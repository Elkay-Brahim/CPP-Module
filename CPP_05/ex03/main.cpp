/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:40:40 by bchifour          #+#    #+#             */
/*   Updated: 2023/09/09 14:14:20 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int mainn()
{
	// std::cout << "---------------------" << std::endl;
	// std::cout << "-----EX00--BUREAUCRAT" << std::endl;
	// std::cout << "---------------------" << std::endl;
	// try
	// {
	// 	Bureaucrat b1("b1", 1);
	// 	std::cout << b1 << std::endl;
	// 	b1.incrementGrade();
	// 	std::cout << b1 << std::endl;
	// 	b1.incrementGrade();
	// 	std::cout << b1 << std::endl;
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	// try
	// {
	// 	Bureaucrat b2("b2", 150);
	// 	std::cout << b2 << std::endl;
	// 	b2.decrementGrade();
	// 	std::cout << b2 << std::endl;
	// 	b2.decrementGrade();
	// 	std::cout << b2 << std::endl;
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	// try
	// {
	// 	Bureaucrat b3("b3", 0);
	// 	std::cout << b3 << std::endl;
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	// try
	// {
	// 	Bureaucrat b4("b4", 151);
	// 	std::cout << b4 << std::endl;
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }

	// std::cout << "---------------------" << std::endl;
	// std::cout << "-----EX01-----FORM---" << std::endl;
	// std::cout << "---------------------" << std::endl;
	// try
	// {
	// 	Form f1("f1", 1, 1);
	// 	std::cout << f1 << std::endl;
	// 	f1.beSigned(b1);
	// 	std::cout << f1 << std::endl;
	// 	f1.beSigned(b1);
	// 	std::cout << f1 << std::endl;
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	// try
	// {
	// 	Form f2("f2", 150, 150);
	// 	std::cout << f2 << std::endl;
	// 	f2.beSigned(b2);
	// 	std::cout << f2 << std::endl;
	// 	f2.beSigned(b2);
	// 	std::cout << f2 << std::endl;
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	// try
	// {
	// 	Form f3("f3", 0, 0);
	// 	std::cout << f3 << std::endl;
	// 	f3.beSigned(b3);
	// 	std::cout << f3 << std::endl;
	// 	f3.beSigned(b3);
	// 	std::cout << f3 << std::endl;
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	// try
	// {
	// 	Form f4("f4", 151, 151);
	// 	std::cout << f4 << std::endl;
	// 	f4.beSigned(b4);
	// 	std::cout << f4 << std::endl;
	// 	f4.beSigned(b4);
	// 	std::cout << f4 << std::endl;
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	
	// std::cout << "---------------------" << std::endl;
	// std::cout << "-----EX02--ROBOTOMY--" << std::endl;
	// std::cout << "---------------------" << std::endl;
	// try
	// {
	// 	Bureaucrat b1("b1", 1);
	// 	RobotomyRequestForm r1("r1");
	// 	std::cout << r1 << std::endl;
	// 	r1.beSigned(b1);
	// 	std::cout << r1 << std::endl;
	// 	b1.executeForm(r1);
	// 	b1.executeForm(r1);
	// 	b1.executeForm(r1);
	// 	b1.executeForm(r1);
	// 	b1.executeForm(r1);	
	// 	b1.executeForm(r1);
	// 	b1.executeForm(r1);
	// 	b1.executeForm(r1);
	// 	b1.executeForm(r1);
	// 	b1.executeForm(r1);
	// 	b1.executeForm(r1);
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	
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

	std::cout << "---------------------" << std::endl;
	std::cout << "-----EX03--INTERN----" << std::endl;
	std::cout << "---------------------" << std::endl;
	try
	{
		Intern i1;
		Form *f1 = i1.makeForm("ShrubberyCreationForm", "f1");
		std::cout << *f1 << std::endl;
		delete f1;
		Form *f2 = i1.makeForm("PresidentialPardonForm", "f2");
		std::cout << *f2 << std::endl;
		delete f2;
		Form *f3 = i1.makeForm("RobotomyRequestForm", "f3");
		std::cout << *f3 << std::endl;
		delete f3;
		Form *f4 = i1.makeForm("UnknownForm", "f4");
		std::cout << *f4 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}

int main()
{
	mainn();
	system("leaks ex03");
	return (0);
}

