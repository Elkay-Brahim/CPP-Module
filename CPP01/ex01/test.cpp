/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 00:07:02 by bchifour          #+#    #+#             */
/*   Updated: 2023/05/28 20:03:52 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
	private:
		std::string name_zombie;
	public:
		Zombie(){}
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

Zombie* zombieHorde( int N, std::string name )
{
	int i = 0;
	Zombie *prince = new Zombie[N];
	while(i < N)
	{
		prince[i] = Zombie(name);
		i++;
	}
	return prince;
}

int main()
{
	int i = 0;
	int N = 4;
	std::string name = "prince";
	Zombie *prince = zombieHorde(N ,name);
	while(i < 4)
	{
		prince[i].annonce();
		i++;
	}
	delete []prince;
	return 0;
}

