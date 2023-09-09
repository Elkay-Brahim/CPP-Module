/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:49:40 by bchifour          #+#    #+#             */
/*   Updated: 2023/09/09 14:10:39 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("default"), sign(false), gradeSign(150), gradeExec(150)
{
	return ;
}

Form::Form(std::string const name, int gradeSign, int gradeExec) : name(name), sign(false), gradeSign(gradeSign), gradeExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw Form::GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw Form::GradeTooLowException();
	return ;
}

Form::Form(Form const &copy) : name(copy.name), sign(copy.sign), gradeSign(copy.gradeSign), gradeExec(copy.gradeExec)
{
	return ;
}

Form::~Form()
{
	return ;
}

Form &Form::operator=(Form const &assign)
{
	this->sign = assign.sign;
	return (*this);
}

std::string const Form::getName() const
{
	return (this->name);
}

bool Form::getSign() const
{
	return (this->sign);
}

int Form::getGradeSign() const
{
	return (this->gradeSign);
}

int Form::getGradeExec() const
{
	return (this->gradeExec);
}

void Form::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() > this->gradeSign)
		throw Form::GradeTooLowException();
	if (this->sign)
		throw Form::FormAlreadySignedException();
	this->sign = true;
	return ;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char* Form::FormAlreadySignedException::what() const throw()
{
	return ("Form already signed");
}

const char* Form::FormNotSignedException::what() const throw()
{
	return ("Form not signed");
}

std::ostream &operator<<(std::ostream &o, Form const &rhs)
{
	o << rhs.getName() << " is ";
	if (rhs.getSign())
		o << "signed";
	else
		o << "not signed";
	o << " and require grade " << rhs.getGradeSign() << " to be signed and grade " << rhs.getGradeExec() << " to be executed" << std::endl;
	return (o);
}
