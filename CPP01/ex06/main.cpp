/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:18:13 by bchifour          #+#    #+#             */
/*   Updated: 2023/06/01 22:33:36 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Harl
{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	public:
		Harl(){};
		~Harl(){};
		void complain( std::string level);
	
};

typedef void (Harl::*functionPtr)(void);
void Harl:: debug()
{
	std::cout << "DEBUG : I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std:: endl;
}

void Harl:: info()
{
	std::cout << "INFO : I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std:: endl;
}

void Harl:: warning()
{
	std::cout << "WARNING : I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std:: endl;
}

void Harl:: error()
{
	std::cout << "ERROR : This is unacceptable! I want to speak to the manager now." << std:: endl;
}

void Harl:: complain(std::string level)
{
	functionPtr ptr[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string message[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	while(i < 4 && message[i].compare(level))
		i++;
	while (i < 4)
	{
		(this->*ptr[i])();
		i++;
	}
}

int main(int ac, char **av)
{
	Harl harl;
	
	// harl.complain("DEBUG");
    harl.complain(av[1]);
    // harl.complain("WARNING");
    // harl.complain("ERROR");
    // harl.complain("UNKNOWN");
	return 0;
}