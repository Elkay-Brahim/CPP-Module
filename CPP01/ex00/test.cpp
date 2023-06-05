/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:17:17 by bchifour          #+#    #+#             */
/*   Updated: 2023/05/28 00:06:21 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
	private:
		std::string name_zombie;
	public:
		Zombie(std::string name_zombie) : name_zombie(name_zombie) {}
	
		~Zombie()
		{
			std:: cout << "Destroy: " << name_zombie << std :: endl;
		}
		void annonce();
};

void Zombie:: annonce()
{
	std:: cout << name_zombie << ": briiiiiiiiiinze....." << std:: endl;
}

Zombie *newZombie(std::string name_zombie)
{
	Zombie *prince = new Zombie(name_zombie);
	return prince;
}

void randomChomp(std::string name_zombie)
{
	Zombie raff(name_zombie);
	raff.annonce();
}

int main()
{
	Zombie *prince = newZombie("prince");
	prince->annonce();
	randomChomp("raff");
	delete prince;
	return 0;
}