/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:53:32 by bchifour          #+#    #+#             */
/*   Updated: 2023/09/28 12:05:02 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include <sstream>
#include <unistd.h>

int count = 0;

bool vectorCompare(const std::vector<int>& a, const std::vector<int>& b) {
    count++;
    return a.back() < b.back();
}



void split_each_peers(std::vector<std::vector<int> > &peers)
{
    std::vector<std::vector<int> >::iterator it = peers.begin();
    std::vector<int>::iterator _it;
    for(it = peers.begin(); it != peers.end(); it++)
    {
        _it = it->begin();
        int j = it->size();
        int i = j / 2;
        std::vector<int> tmp(_it+i, _it + j);
        it->erase(_it + i, _it + j);
        peers.insert(it+1, tmp);
        it++;
        tmp.clear();
    }
    
}

void print_doublevector(std::vector<std::vector<int> > doubleVector)
{
    // std::cout << "print double vector" << std::endl;
    std::vector<std::vector<int> >::iterator it = doubleVector.begin();
    std::vector<int>::iterator _it = it->begin();
    for(it = doubleVector.begin(); it != doubleVector.end(); it++)
    {
        _it = it->begin();
        while(_it != it->end())
        {
            std::cout << *_it << " ";
            _it++;
        }
        std::cout << "   ";
    }
    std::cout << std::endl;
}

int jacobsthal(int index)
{
    if (index == 0)
        return 0;
    if (index == 1)
        return 1;
    return jacobsthal(index - 1) + 2 * jacobsthal(index - 2);
}
std::vector<int> build_jacob_insertion_sequence(std::vector<std::vector<int> > pand)
{
    int len = pand.size();
    std::vector<int> jacob;
    int jacob_len = 3;
    while(jacobsthal(jacob_len) < len)
    {
        jacob.push_back(jacobsthal(jacob_len));
        jacob_len++;
    }
    return jacob;
    
}

void merge_insertion(std::vector<std::vector<int> > &peers)
{
    std::vector<std::vector<int> >::iterator it = peers.begin();
    std::vector<int>::iterator __it;
    int len = peers.size() % 2 != 0;
    std::vector<int> rest;
    if (len)
    {
        rest = peers.at(peers.size() - 1);
        peers.pop_back();
    }
    else
    {
        rest.push_back(-1);
        
    }
    if (peers.size()  >= 2)
    {
        for(it = peers.begin(); it != peers.end(); it++)
        {
            __it = it->end() - 1;
            
            if (it+1 != peers.end())
            {
                count++;
                if (*(it->end() - 1) > *((it + 1)->end() - 1))
                {
                it->insert(it->begin(), (it+1)->begin(), (it+1)->end());
                    
                }
                else
                {
                    it->insert(it->end(), (it+1)->begin(), (it+1)->end());
                }
                (it+1)->erase((it+1)->begin(), (it+1)->end());
                peers.erase(it+1);
            }
        
        }
        if (peers.size() >= 2)
            merge_insertion(peers);
    }
    split_each_peers(peers);
    if (peers.size() > 2)
    {
        std::vector<std::vector<int> > pand;
        std::vector<std::vector<int> > main_chain;
        std::vector<std::vector<int> >::iterator it = peers.begin();
        for(it = peers.begin(); it != peers.end(); it++)
        {
            
            pand.push_back(*it);
            peers.erase(it);
        }
        if (rest.at(0) != -1)
            pand.push_back(rest);
        
        it = pand.begin();
        // for(it = pand.begin(); it != pand.end(); it++)
        // {
        //     std::vector<int>::iterator _it = it->begin();
        //     std::vector<int> jacob = build_jacob_insertion_sequence(pand);
        //     std::vector<int>::iterator __it = jacob.begin();
        //     std::vector<std::vector<int> >::iterator customUpperBound = std::upper_bound(peers.begin(), peers.end(), *(it), vectorCompare);
        //     peers.insert(customUpperBound, *(it));
        // }
        // std::vector<std::vector<int> >::iterator customUpperBound = std::upper_bound(peers.begin(), peers.begin()+1, *(it), vectorCompare);
        peers.insert(peers.begin(), *(it));
        std::vector<std::vector<int> >::iterator  customUpperBound = std::upper_bound(peers.begin(), peers.begin()+2, *(it+1), vectorCompare);
        peers.insert(customUpperBound, *(it+1));
        std::vector<int> jacob = build_jacob_insertion_sequence(pand);
        std::vector<int>::iterator __it = jacob.begin();
        if(jacob.size() ==  0)
        {
            customUpperBound = std::upper_bound(peers.begin(), peers.begin()+4, *(it+2), vectorCompare);
            peers.insert(customUpperBound, *(it+2));
        }
    
        
        if (jacob.size() > 0 )
        {
            int index = 8;
            int zip = 0;
            for(__it = jacob.begin(); __it != jacob.end(); __it++)
            {
                int i = *__it;
                int j;
                if (__it == jacob.begin())
                    j = 1;
                else
                    j = *(__it - 1);
                while(i > j)
                {
                    std::vector<std::vector<int> >::iterator customUpperBound = std::upper_bound(peers.begin(), peers.begin() + index-1, *(it + i), vectorCompare);
                    peers.insert(customUpperBound, *(it + i));
                    index += 2;
                    // zip+=2;
                    i--;
                }
            }
            if (*(jacob.end() -1) < pand.size())
            {
                int i = pand.size() - 1;
                int j = *(jacob.end() -1);
                // int index = ;
                while(i > j)
                {
                    if (i == pand.size() - 1)
                    {
                        std::vector<std::vector<int> >::iterator customUpperBound = std::upper_bound(peers.begin(), peers.end(), *(it + i), vectorCompare);
                        peers.insert(customUpperBound, *(it + i));
                    }
                    else
                    {
                        // std::vector<std::vector<int> >::iterator customUpperBound = std::upper_bound(peers.begin() + (index - 10), peers.begin() + index -1, *(it + i), vectorCompare);
                        std::vector<std::vector<int> >::iterator customUpperBound = std::upper_bound(peers.begin() , peers.begin() + (index), *(it + i), vectorCompare);

                        peers.insert(customUpperBound, *(it + i));
                        if (i % 2 != 0)
                            index -= 1;
                    }
                    i--;
                }
            }
        } 
    }
}

// std::vector<std::vector<int> > creat_peers(std::vector<int> vc)
// {
//     std::vector<std::vector<int> > doubleVector;
//     std::vector<int>::iterator it = vc.begin();
//     std::vector<std::vector<int> >::iterator iit = doubleVector.begin();
//     std::vector<int> peers;
//     int i = 0;
//     int len = vc.size() % 2 != 0;
//     int rest;
//     if (len)
//     {
//         rest = vc.at(vc.size() - 1);
//         vc.pop_back();
//     }
//     else
//         rest = -1;
//     while(it != vc.end())
//     {
//         std::vector<int> tmp;
//         i = 0;
//         while(i < 1 && it != vc.end())
//         {
//             tmp.push_back(*it);
//             it++;
//             if (it != vc.end())
//             {
//                 tmp.push_back(*it);
//                 it++;
//             }
//             i++;
//         }
//         doubleVector.push_back(tmp);
//         tmp.clear();
//     }
//     return doubleVector;
// }
// void sort_each_peer(std::vector<std::vector<int> > &peers)
// {
//     std::vector<std::vector<int> >::iterator it = peers.begin();
//     std::vector<int>::iterator _it = it->begin();
//     for(it = peers.begin(); it != peers.end(); it++)
//     {
//         _it = it->begin();
//         while(_it != it->end())
//         {
//             if (*_it > *(_it + 1))
//             {
//                 int tmp = *_it;
//                 *_it = *(_it + 1);
//                 *(_it + 1) = tmp;
//             }
//             _it++;
//             _it++;
//         }
//     }

// }
int main (int ac, char **av)
{
    std::vector<std::vector<int> > doubleVector;
    std::vector<int> vc;
    std::vector<int>::iterator it = vc.begin();
    std::vector<std::vector<int> >::iterator __it = doubleVector.begin(); 
    std::string str = av[1];
    std::istringstream ss(str);
    std::string token;
    while (std::getline(ss, token, ' '))
    {
        int i = strtod(token.c_str(), NULL);
        vc.push_back(i);
        doubleVector.push_back(vc);
        vc.clear();
    }
    merge_insertion(doubleVector);
    print_doublevector(doubleVector);
    
    std::cout << "comparition " << count << std::endl;
}