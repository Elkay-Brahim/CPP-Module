/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   • RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:45:56 by bchifour          #+#    #+#             */
/*   Updated: 2023/09/09 12:26:37 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45), target("default")
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : Form("RobotomyRequestForm", 72, 45), target(target)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : Form(copy), target(copy.target)
{
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &assign)
{
	this->Form::operator=(assign);
	return (*this);
}

std::string const RobotomyRequestForm::getTarget() const
{
	return (this->target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getSign() == false)
		throw Form::FormNotSignedException();
	else if (executor.getGrade() > this->getGradeExec())
		throw Form::GradeTooLowException();
	else
	{
		static int i = 0;
		if (i % 2 == 0)
			std::cout << "Bzz" << std::endl << this->getTarget() << " has been robotomized successfully 50\'%\' of the time." << std::endl;
		else
			std::cout << "Bzz" << std::endl << this->getTarget() << " has not been robotomized successfully 50\'%\' of the time." << std::endl;
		i++;
	}
}