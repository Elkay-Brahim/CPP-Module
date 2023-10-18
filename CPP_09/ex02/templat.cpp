/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templat.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:53:32 by bchifour          #+#    #+#             */
/*   Updated: 2023/10/05 18:50:55 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <sstream>
#include <unistd.h>

int count = 0;
int size;
int co;
int fo = 0;

bool vectorCompare(const std::list<int>& a, const std::list<int>& b) {
    count++;
    return a.back() < b.back();
}


void split_each_peers(std::list<std::list<int> > &peers)
{
    std::list<std::list<int> >::iterator it = peers.begin();
    std::list<std::list<int> > splits;
    std::list<int>::iterator begin;
    std::list<int>::iterator end;
    for(it = peers.begin(); it != peers.end(); it++)
    {
        int j = it->size();
        int i = j / 2;
        begin = std::next(it->begin(), 0);
        end = std::next(it->begin(), i);
        std::list<int> tmp(begin, end);
        splits.push_back(tmp);
        tmp.clear();
        begin = std::next(it->begin(), i);
        end = std::next(it->begin(), j);
        std::list<int> tmp1(begin, end);
        splits.push_back(tmp1);
        tmp1.clear();
    }
    peers.clear();
    peers = splits;
    
}

bool isSortedAscending(std::list<int>& vec) {
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


void print_doublevector(std::list<std::list<int> > doubleVector)
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

int jacobsthal(int index)
{
    if (index == 0)
        return 0;
    if (index == 1)
        return 1;
    return jacobsthal(index - 1) + 2 * jacobsthal(index - 2);
}

template<typename T>
std::vector<int> build_jacob_insertion_sequence(T pand)
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
std::list<std::list<std::list<int> >::iterator>  shift_iterator(std::list<std::list<std::list<int> >::iterator> iteratorList, std::list<std::list<int> > &numbers,int shift)
{
    std::list<std::list<std::list<int> >::iterator> new_iteratorList;
    int startIndex = shift;
    if (startIndex > 0) {
        
        for(auto it = iteratorList.begin(); it != iteratorList.end(); it++) 
        {
            new_iteratorList.push_back(*it);
            startIndex--;
            if (startIndex == 0)
                break;
        }
    }
    auto it = iteratorList.begin();
    it = std::next(it, shift);
    for (; it != iteratorList.end();) 
    {
        std::list<std::list<int> >::iterator shiftedIterator = std::next(*it, 0);
        if (shiftedIterator != numbers.end())
            new_iteratorList.push_back(shiftedIterator);
        else
            break;
        it++;
    }
    return new_iteratorList;
}

void merge_insertion(std::list<std::list<int> > &peers)
{
    std::list<std::list<int> >::iterator it = peers.begin();
    std::list<int>::iterator tmp;
    std::list<int>::iterator tmp1;
    std::list<std::list<int> >::iterator it_peers = peers.begin();
    std::list<int>::iterator __it;
    it = peers.begin();
    int len = peers.size() % 2 != 0;
    std::list<int> rest;
    std::list<std::list<int> > rest_peers;
    if (len)
    {
        it = std::next(peers.begin(), peers.size() -1);
        rest_peers.push_back(*it);
        
        peers.pop_back();
    }
    if (peers.size()  >= 2)
    {
        for(it = peers.begin(); it != peers.end(); it++)
        {
            it_peers = it;
            it_peers++;
            __it = std::next(it->begin(), it->size() -1);
            
            if (it_peers != peers.end())
            {
                count++;
                tmp = std::next(it->begin(), it->size()-1);
                tmp1 =  std::next(it_peers->begin(), it_peers->size() -1);
                if (*tmp > *tmp1)
                {
                it->insert(it->begin(), (it_peers)->begin(), (it_peers)->end());
                    
                }
                else
                {
                    it->insert(it->end(), (it_peers)->begin(), (it_peers)->end());
                }
                (it_peers)->erase((it_peers)->begin(), (it_peers)->end());
                peers.erase(it_peers);
            }
        }
        if (peers.size() >= 2)
        {
            merge_insertion(peers);
        }
    }
    split_each_peers(peers);
    std::list<std::list<std::list<int> >::iterator> iteratorList;
    if (peers.size() > 2)
    {
        std::list<std::list<int> > pand;
        std::list<std::list<int> > main_chain;
        std::list<std::list<int> >::iterator it = peers.begin();
        for(it = peers.begin(); it != peers.end();it++)
        {
            it_peers = it;
            pand.push_back(*it);
            it++;
            if(it == peers.end())
            {  
                it--;
                main_chain.push_back(*it);
                break;
            }
            main_chain.push_back(*it);
        }
        peers = main_chain;
        if(rest_peers.size() > 0)
        {
            it = rest_peers.begin();
            pand.push_back(*it);
        }
    for (auto it = peers.begin(); it != peers.end(); ++it) {
        iteratorList.push_back(it);
    }
        std::list<std::list<std::list<int> >::iterator>::iterator iter;
        it = pand.begin();
        peers.insert(peers.begin(), *(it));
        it++;
        iteratorList =  shift_iterator(iteratorList, peers, 0);
        it_peers = std::next(peers.begin(), 2);
        std::list<std::list<int> >::iterator  customUpperBound = std::upper_bound(peers.begin(), it_peers, *(it), vectorCompare);
        peers.insert(customUpperBound, *(it));
        it++;
        int dectance = std::distance(peers.begin(), customUpperBound);
        iteratorList =  shift_iterator(iteratorList, peers, dectance);
        std::vector<int>  jacob = build_jacob_insertion_sequence(pand);
        std::vector<int>::iterator __it = jacob.begin();
        if(jacob.size() ==  0 && it != pand.end())
        {
            customUpperBound = std::upper_bound(peers.begin(), peers.end(), *(it), vectorCompare);
            peers.insert(customUpperBound, *(it));
            dectance = std::distance(peers.begin(), customUpperBound);
            iteratorList =  shift_iterator(iteratorList, peers, dectance);
        }
        if (jacob.size() > 0 )
        {
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
                    fo = *__it;
                    if (fo == iteratorList.size())
                    {
                        iter = std::next(iteratorList.begin(), iteratorList.size()-1);
                        it = std::next(pand.begin(), i);
                        it_peers = std::next(peers.begin(), peers.size()-1);
                        std::list<std::list<int> >::iterator customUpperBound = std::upper_bound(peers.begin(), it_peers, *(it), vectorCompare);
                        peers.insert(customUpperBound, *(it));
                    }
                    else
                    {
                        iter = std::next(iteratorList.begin(), fo);
                        it = std::next(pand.begin(), i);
                        std::list<std::list<int> >::iterator customUpperBound = std::upper_bound(peers.begin(), *(iter), *(it), vectorCompare);
                        peers.insert(customUpperBound, *(it));
                        dectance = std::distance(peers.begin(), customUpperBound);
                        iteratorList =  shift_iterator(iteratorList, peers, dectance);
                    }
                    i--;
                }
            }
            if (*(jacob.end() -1) < pand.size())
            {
                int i = pand.size() - 1;
                int j = *(jacob.end() -1);
                int index = iteratorList.size() - 1;
                        
                while(i > j)
                {
                    if (i == pand.size() - 1)
                    {
                        it = std::next(pand.begin(), i);
                        std::list<std::list<int> >::iterator customUpperBound = std::upper_bound(peers.begin(), peers.end(), *(it), vectorCompare);
                        peers.insert(customUpperBound, *(it));
                        dectance = std::distance(peers.begin(), customUpperBound);
                        iteratorList =  shift_iterator(iteratorList, peers, dectance);
                    }
                    else
                    {
                        iter = std::next(iteratorList.begin(), index);
                        it = std::next(pand.begin(), i);
                        std::list<std::list<int> >::iterator customUpperBound = std::upper_bound(peers.begin() , *(iter), *(it), vectorCompare);
                        peers.insert(customUpperBound, *(it));
                        dectance = std::distance(peers.begin(), customUpperBound);
                        iteratorList =  shift_iterator(iteratorList, peers, dectance);
                    }
                    i--;
                }
            }
        } 
    }
    else if(rest_peers.size() > 0)
        {
            std::cout << *(it->begin()) << std::endl;
            std::list<std::list<int> >::iterator customUpperBound = std::upper_bound(peers.begin() , peers.end(), *(it), vectorCompare);
            std::list<std::list<int> >::iterator it = rest_peers.begin();
            peers.insert(customUpperBound, *(it));
        }    
}

int main (int ac, char **av)
{
    std::vector<std::vector<int> > doubleVector;
    std::list<std::list<int> > doubleList;
    std::deque<std::deque<int> > doubleDeque;
    doubleVector.reserve(doubleVector.size()+1);
    std::vector<int> vc;
    std::list<int> vL;
    std::deque<int> vd;
    std::vector<int>::iterator it = vc.begin();
    std::vector<std::vector<int> >::iterator __it = doubleVector.begin(); 
    std::string str = av[1];
    std::istringstream ss(str);
    std::string token;
    while (std::getline(ss, token, ' '))
    {
        int i = strtod(token.c_str(), NULL);
        vc.push_back(i);
        vL.push_back(i);
        vd.push_back(i);
        doubleVector.push_back(vc);
        doubleList.push_back(vL);
        doubleDeque.push_back(vd);
        vc.clear();
        vL.clear();
        vd.clear();
    }
    // std::cout<< doubleVector.size() << std::endl;
    // merge_insertion(doubleVector, vc);
    // print_doublevector(doubleVector, vc);
    std::cout << "comparition " << count << std::endl;
    count = 0;
    merge_insertion(doubleList);
    print_doublevector(doubleList);
    
    std::cout << "comparition " << count << std::endl;
}

