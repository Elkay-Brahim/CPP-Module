/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:51:00 by bchifour          #+#    #+#             */
/*   Updated: 2023/10/06 13:24:55 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "merge_insertion.hpp"

bool isSortedAscending(std::list<int>& vec) 
{
    std::list<int>::iterator tmp = vec.begin();
    for(std::list<int>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        tmp = it;
        tmp++;
        if (tmp == vec.end())
            break;
        if(*it > *tmp)
        return false;
    }
    return true;
}


void print_doubleList(std::list<std::list<int> > doubleVector)
{
    std::list<std::list<int> >::iterator it = doubleVector.begin();
    std::list<int>::iterator _it = it->begin();
    std::list<int> sort;
    for(it = doubleVector.begin(); it != doubleVector.end(); it++)
    {
        _it = it->begin();
        while(_it != it->end())
        {
            std::cout << *_it << " ";
            sort.push_back(*_it);
            _it++;
        }
        std::cout << "   ";
    }
    std::cout <<" size => "<< doubleVector.size() << " sorted => "<<isSortedAscending(sort) <<std::endl;
    std::cout << std::endl;
}


bool _isSortedAscending(const std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        if (vec[i] > vec[i + 1]) {
            return false;
        }
    }
    return true;
}

void print_doublevector(std::vector<std::vector<int> > doubleVector)
{
    std::vector<std::vector<int> >::iterator it = doubleVector.begin();
    std::vector<int>::iterator _it = it->begin();
    std::vector<int> sort;
    std::cout << "\n\033[94mAfter  : \033[39m";
    for(it = doubleVector.begin(); it != doubleVector.end(); it++)
    {
        _it = it->begin();
        while(_it != it->end())
        {
            std::cout << *_it << " ";
            sort.push_back(*_it);
            _it++;
        }
    }
    if (_isSortedAscending(sort))
        std::cout << " \033[92m sorted \033[39m" << std::endl;
    else
        std::cout << "\033[91m unsorted \033[39m" << std::endl;
}