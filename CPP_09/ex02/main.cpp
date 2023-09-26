/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:53:32 by bchifour          #+#    #+#             */
/*   Updated: 2023/09/26 18:39:24 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include <sstream>
#include <unistd.h>


// bool vectorCompare(const std::vector<int>& a, const std::vector<int>& b) {
//     // You can define your custom comparison logic here.
//     // For example, you may want to compare the sum of elements in the vectors.
//     return a.end()-1 < b.end()-1;
// }

bool vectorCompare(const std::vector<int>& a, const std::vector<int>& b) {
    // You can define your custom comparison logic here.
    // For example, you may want to compare the sum of elements in the vectors.
    std::cout << (a.back()) << " "  <<  (b.back()) << std::endl;
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
        // it->insert(it->begin(), tmp.begin(), tmp.end());
         std::cout << tmp.size() << std::endl;
        tmp.clear();
    }
    
}

void print_doublevector(std::vector<std::vector<int> > doubleVector)
{
    std::cout << "print double vector" << std::endl;
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
        std::cout <<  std::endl;
    }
}

void merge_insertion(std::vector<std::vector<int> > &peers)
{
    std::vector<std::vector<int> >::iterator it = peers.begin();
    std::vector<int>::iterator __it;
    // __it--;
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
    std::cout << "-----------------------" << std::endl;
    if (peers.size()  >= 2)
    {
        for(it = peers.begin(); it != peers.end(); it++)
        {
            __it = it->end() - 1;
            
            if (it+1 != peers.end())
            {
                 std::cout << "----------- " << *(it->end() - 1)  << " " <<*((it + 1)->end() - 1) << std::endl;
                if (*(it->end() - 1) > *((it + 1)->end() - 1))
                {
                //     it->p(it->begin(), ((it + 1));
                it->insert(it->begin(), (it+1)->begin(), (it+1)->end());
                // it->erase(it->begin(), it->begin() + (it+1)->size());
                    
                }
                else
                {
                    it->insert(it->end(), (it+1)->begin(), (it+1)->end());
                    // it->erase((it+1)->begin(), (it+1)->end()-1);
                }
                // it++;
                (it+1)->erase((it+1)->begin(), (it+1)->end());
                peers.erase(it+1);
                // (*(it + 1)).pop_back();
                // std::cout << *((it + 1)->end() - 1) << std::endl;
            }
            // if (*__it > *(__it + 1))
            // {
                
            // }
            // __it++;
        
        }
        // std::cout << peers.size() << std::endl;
        print_doublevector(peers);
        // pause();
        if (peers.size() >= 2)
            merge_insertion(peers);
    }
    // std::cout << "------------pause-----------" << std::endl;
    // std::cout << peers.size() << std::endl;
    // std::cout << "-----------------------" << std::endl;
    // int size = peers.size() / 2;
    // std::vector<int> tmp;
    // for( int size = __it->size() / 2; size < peers.size(); size++)
    // {
    //     tmp.push_back(*((peers.at(size)).begin()));
    // }
    // peers.push_back(tmp);
    std::cout << "-----------split_each_peers------------" << std::endl;
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
            // it++;
            // main_chain.push_back(*it);
        }
        if (rest.at(0) != -1)
            pand.push_back(rest);
        
        
        for(it = pand.begin(); it != pand.end(); it++)
        {
            std::vector<int>::iterator _it = it->begin();
            while(_it != it->end())
            {
                std::cout << *_it << " - ";
                _it++;
            }
            std::cout <<  std::endl;
        std::vector<std::vector<int> >::iterator customUpperBound = std::upper_bound(peers.begin(), peers.end(), *it, vectorCompare);
        // std::cout << "-------------*----------" << *customUpperBound << std::endl;
    //    while(_it != it->end())
    //     {
    //         std::cout << *_it  << std::endl;
    //         _it++;
    //     }
        print_doublevector(peers);
        peers.insert(customUpperBound, *(it));
        print_doublevector(peers);
        }
        
    }
    
    
    // pause();
    
    // insertion_sort
   
    
}

std::vector<std::vector<int> > creat_peers(std::vector<int> vc)
{
    std::vector<std::vector<int> > doubleVector;
    std::vector<int>::iterator it = vc.begin();
    std::vector<std::vector<int> >::iterator iit = doubleVector.begin();
    std::vector<int> peers;
    int i = 0;
    int len = vc.size() % 2 != 0;
    int rest;
    if (len)
    {
        rest = vc.at(vc.size() - 1);
        vc.pop_back();
    }
    else
        rest = -1;
    while(it != vc.end())
    {
        std::vector<int> tmp;
        i = 0;
        while(i < 1 && it != vc.end())
        {
            tmp.push_back(*it);
            it++;
            if (it != vc.end())
            {
                tmp.push_back(*it);
                it++;
            }
            i++;
        }
        doubleVector.push_back(tmp);
        tmp.clear();
    }
    return doubleVector;
}
void sort_each_peer(std::vector<std::vector<int> > &peers)
{
    std::vector<std::vector<int> >::iterator it = peers.begin();
    std::vector<int>::iterator _it = it->begin();
    for(it = peers.begin(); it != peers.end(); it++)
    {
        _it = it->begin();
        while(_it != it->end())
        {
            if (*_it > *(_it + 1))
            {
                int tmp = *_it;
                *_it = *(_it + 1);
                *(_it + 1) = tmp;
            }
            _it++;
            _it++;
        }
    }

}
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
    }
    for(it = vc.begin(); it != vc.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n" << std::endl;
    
    doubleVector = creat_peers(vc);
    // std::cout << doubleVector.size() << "\n";
    sort_each_peer(doubleVector);
    for(__it = doubleVector.begin(); __it != doubleVector.end(); __it++)
    {
        it = __it->begin();
        while(it != __it->end())
        {
            std::cout << *it << " ";
            it++;
        }
        std::cout << "    ";
    }
    std::cout << std::endl;
    merge_insertion(doubleVector);
    // pause();
}