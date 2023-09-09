/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   • RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:44:48 by bchifour          #+#    #+#             */
/*   Updated: 2023/09/09 12:30:21 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Form.hpp"


class RobotomyRequestForm : public Form
{
	private:
		std::string const	target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const target);
		RobotomyRequestForm(RobotomyRequestForm const &copy);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(RobotomyRequestForm const &assign);
		std::string const	getTarget() const;
		void				execute(Bureaucrat const &executor) const;
};