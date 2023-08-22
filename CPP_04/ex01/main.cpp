/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:06:33 by bchifour          #+#    #+#             */
/*   Updated: 2023/08/21 12:23:57 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();

std::cout << "\n";
const WrongAnimal* wrong_meta = new WrongAnimal();
const WrongAnimal* wrong_i = new WrongCat();
std::cout << wrong_i->getType() << " " << std::endl;
wrong_i->makeSound(); //will output the cat sound!
wrong_meta->makeSound();

std::cout << "\n";

delete meta;
delete j;
delete i;
delete wrong_i;
delete wrong_meta;

Animal *prince = new Animal[6];
int k = 0;
while (k++ < 6)
{
	if (k < 3)
		prince[k] = Cat();
	else 
		prince[k] = Dog();
}
delete[] prince;
return 0;
}