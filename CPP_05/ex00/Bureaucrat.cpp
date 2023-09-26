/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:54:44 by bchifour          #+#    #+#             */
/*   Updated: 2023/09/18 19:55:03 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
	return ;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : name(copy.name), grade(copy.grade)
{
	return ;
}

Bureaucrat::~Bureaucrat()
{
	return ;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &assign)
{
	this->grade = assign.grade;
	return (*this);
}

std::string const	Bureaucrat::getName() const
{
	return (this->name);
}

int					Bureaucrat::getGrade() const
{
	return (this->grade);
}

void				Bureaucrat::incrementGrade()
{
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
	return ;
}

void				Bureaucrat::decrementGrade()
{
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
	return ;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	throw Bureaucrat::GradeTooLowException();
	return ("Grade too low");
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return (o);
}


