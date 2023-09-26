/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:24:57 by bchifour          #+#    #+#             */
/*   Updated: 2023/09/19 17:20:58 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	
	std::cout << "---------------------" << std::endl;

	
	std::list<int> mstackk;
	mstackk.push_back(5);
	mstackk.push_back(17);
	std::cout << mstackk.back() << std::endl;
	mstackk.pop_back();
	std::cout << mstackk.size() << std::endl;
	mstackk.push_back(3);
	mstackk.push_back(5);
	mstackk.push_back(737);
	mstackk.push_back(0);
	std::list<int>::iterator itt = mstackk.begin();
	std::list<int>::iterator itte = mstackk.end();
	++itt;
	--itt;
	while (itt != itte)
	{
		std::cout << *itt << std::endl;
		++itt;
	}
	std::list<int> ss(mstackk);
	return (0);
}