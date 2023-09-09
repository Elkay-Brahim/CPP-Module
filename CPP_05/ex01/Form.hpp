/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:53:52 by bchifour          #+#    #+#             */
/*   Updated: 2023/09/08 18:23:32 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	name;
		bool				sign;
		int const			gradeSign;
		int const			gradeExec;
	public:
		Form();
		Form(std::string const name, int gradeSign, int gradeExec);
		Form(Form const &copy);
		~Form();
		Form &operator=(Form const &assign);
		std::string const	getName() const;
		bool				getSign() const;
		int					getGradeSign() const;
		int					getGradeExec() const;
		void				beSigned(Bureaucrat const &b);
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		
};

std::ostream &operator<<(std::ostream &o, Form const &rhs);