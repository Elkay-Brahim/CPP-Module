/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:40:40 by bchifour          #+#    #+#             */
/*   Updated: 2023/09/08 18:32:08 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		std::cout << "---------------------" << std::endl;
		Bureaucrat b1("b1", 1);
		std::cout << b1;
		b1.incrementGrade();
		std::cout << b1;
		b1.incrementGrade();
		std::cout << b1;
		
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "---------------------" << std::endl;
		Bureaucrat b2("b2", 150);
		std::cout << b2;
		b2.decrementGrade();
		std::cout << b2;
		b2.decrementGrade();
		std::cout << b2;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "---------------------" << std::endl;
		Bureaucrat b3("b3", 0);
		std::cout << b3;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "---------------------" << std::endl;
		Bureaucrat b4("b4", 151);
		std::cout << b4;
	}
	catch (std::exception &e)
	{	
		std::cout << e.what() << std::endl;
	}

	std::cout << "---------------------" << std::endl;
	std::cout << "---------------------" << std::endl;

	try
	{
		Form f1("f1", 1, 1);
		Bureaucrat b1("b1", 1);
		b1.signForm(f1);
		std::cout << f1;
		f1.beSigned(b1);
		std::cout << f1;
		b1.signForm(f1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "---------------------" << std::endl;
		Form f2("f2", 150, 150);
		Bureaucrat b2("b2", 150);
		std::cout << f2;
		f2.beSigned(b2);
		std::cout << f2;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "---------------------" << std::endl;
		Form f3("f3", 1, 1);
		Bureaucrat b3("b3", 20);
		b3.signForm(f3);
		std::cout << f3;
		f3.beSigned(b3);
		std::cout << f3;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "---------------------" << std::endl;
		Form f4("f4", 151, 151);
		Bureaucrat b4("b4", 151);
		std::cout << f4;
		f4.beSigned(b4);
		std::cout << f4;
	}
	catch (std::exception &e)
	{	
		std::cout << e.what() << std::endl;
	}
	return (0);
}