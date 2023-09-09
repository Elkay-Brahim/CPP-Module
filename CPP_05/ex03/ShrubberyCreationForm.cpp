/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:05:49 by bchifour          #+#    #+#             */
/*   Updated: 2023/09/09 19:32:18 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), target("default")
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : Form("ShrubberyCreationForm", 145, 137), target(target)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : Form(copy), target(copy.target)
{
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &assign)
{
	this->Form::operator=(assign);
	return (*this);
}

std::string const ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getSign() == false)
		throw Form::FormNotSignedException();
	if (executor.getGrade() > this->getGradeExec())
		throw Form::GradeTooLowException();
	std::ofstream file;
	file.open(this->getTarget() + "_shrubbery");
	file << "                                              . " << std::endl;
	file << "                                   .         ; " << std::endl;
	file << "      .              .              ;%     ;; " << std::endl;
	file << "        ,           ,                :;%  %; " << std::endl;
	file << "         :         ;                   :;%;'     ., " << std::endl;
	file << ",.        %;     %;            ;        %;'    ,; " << std::endl;
	file << "  ;       ;%;  %%;        ,     %;    ;%;    ,%' " << std::endl;
	file << "   %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
	file << "    ;%;      %;        ;%;        % ;%;  ,%;' " << std::endl;
	file << "     `%;.     ;%;     %;'         `;%%;.%;' " << std::endl;
	file << "      `:;%.    ;%%. %@;        %; ;@%;%' " << std::endl;
	file << "         `:%;.  :;bd%;          %;@%;' " << std::endl;
	file << "           `@%:.  :;%.         ;@@%;' " << std::endl;
	file << "             `@%.  `;@%.      ;@@%; " << std::endl;
	file << "               `@%%. `@%%    ;@@%; " << std::endl;
	file << "                 ;@%. :@%%  %@@%; " << std::endl;
	file << "                   %@bd%%%bd%%:; " << std::endl;
	file << "                     #@%%%%%:;; " << std::endl;
	file << "                     %@@%%%::; " << std::endl;
	file << "                     %@@@%(o);  . ' " << std::endl;
	file << "                     %@@@o%;:(.,' " << std::endl;
	file << "                 `.. %@@@o%::; " << std::endl;
	file << "                    `)@@@o%::; " << std::endl;
	file << "                     %@@(o)::; " << std::endl;
	file << "                    .%@@@@%::; " << std::endl;
	file << "                    ;%@@@@%::;. " << std::endl;
	file << "                   ;%@@@@%%:;;;. " << std::endl;
	file << "               ...;%@@@@@%%:;;;;,..   " << std::endl;
	file.close();
	return ;
}

