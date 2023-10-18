/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_insertion.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:55:33 by bchifour          #+#    #+#             */
/*   Updated: 2023/10/09 10:43:15 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "merge_insertion.hpp"

bool vectorCompare_l(const std::list<int>& a, const std::list<int>& b) {
    return a.back() < b.back();
}

bool vectorCompare_v(const std::vector<int>& a, const std::vector<int>& b) {
    std::cout << "--------" << std::endl;
    for(size_t i=0; i<a.size(); i++)
        std::cout << a.at(i) <<std::endl;
    return a.back() < b.back();
}

void merge_insertion_l(std::list<std::list<int> > &peers)
{
    std::list<std::list<int> >::iterator it = peers.begin();
    std::list<int>::iterator tmp;
    std::list<int>::iterator tmp1;
    std::list<std::list<int> >::iterator it_peers = peers.begin();
    std::list<int>::iterator __it;
    it = peers.begin();
    int len = peers.size() % 2 != 0;
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
                tmp = std::next(it->begin(), it->size()-1);
                tmp1 =  std::next(it_peers->begin(), it_peers->size() -1);
                if (*tmp > *tmp1)
                    it->insert(it->begin(), (it_peers)->begin(), (it_peers)->end());
                else
                    it->insert(it->end(), (it_peers)->begin(), (it_peers)->end());
                (it_peers)->erase((it_peers)->begin(), (it_peers)->end());
                peers.erase(it_peers);
            }
        }
        if (peers.size() >= 2)
            merge_insertion_l(peers);
    }
    split_each_peers_l(peers);
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
    for (std::list<std::list<int> >::iterator it = peers.begin(); it != peers.end(); ++it) {
        iteratorList.push_back(it);
    }
        std::list<std::list<std::list<int> >::iterator>::iterator iter;
        it = pand.begin();
        peers.insert(peers.begin(), *(it));
        it++;
        iteratorList =  shift_iterator_list(iteratorList, peers, 0);
        it_peers = std::next(peers.begin(), 2);
        std::list<std::list<int> >::iterator  customUpperBound = std::upper_bound(peers.begin(), it_peers, *(it), vectorCompare_l);
        peers.insert(customUpperBound, *(it));
        it++;
        int dectance = std::distance(peers.begin(), customUpperBound);
        iteratorList =  shift_iterator_list(iteratorList, peers, dectance);
        std::vector<int>  jacob = build_jacob_insertion_sequence(pand.size());
        std::vector<int>::iterator __it = jacob.begin();
        if(jacob.size() ==  0 && it != pand.end())
        {
            customUpperBound = std::upper_bound(peers.begin(), peers.end(), *(it), vectorCompare_l);
            peers.insert(customUpperBound, *(it));
            dectance = std::distance(peers.begin(), customUpperBound);
            iteratorList =  shift_iterator_list(iteratorList, peers, dectance);
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
                    int fo = *__it;
                    int _size = iteratorList.size();
                    if (fo == _size)
                    {
                        iter = std::next(iteratorList.begin(), iteratorList.size()-1);
                        it = std::next(pand.begin(), i);
                        it_peers = std::next(peers.begin(), peers.size()-1);
                        std::list<std::list<int> >::iterator customUpperBound = std::upper_bound(peers.begin(), peers.end(), *(it), vectorCompare_l);
                        peers.insert(customUpperBound, *(it));
                        dectance = std::distance(peers.begin(), customUpperBound);
                        iteratorList =  shift_iterator_list(iteratorList, peers, dectance);
                    }
                    else
                    {
                        iter = std::next(iteratorList.begin(), fo);
                        it = std::next(pand.begin(), i);
                        std::list<std::list<int> >::iterator customUpperBound = std::upper_bound(peers.begin(), peers.end(), *(it), vectorCompare_l);
                        peers.insert(customUpperBound, *(it));
                        dectance = std::distance(peers.begin(), customUpperBound);
                        iteratorList =  shift_iterator_list(iteratorList, peers, dectance);
                    }
                    i--;
                }
            }
            int _pand = pand.size();
            if (*(jacob.end() -1) < _pand)
            {
                int i = pand.size() - 1;
                int j = *(jacob.end() -1);
                int index = iteratorList.size() - 1;
                        
                while(i > j)
                {
                    _pand = pand.size() - 1;
                    if (i == _pand)
                    {
                        it = std::next(pand.begin(), i);
                        std::list<std::list<int> >::iterator customUpperBound = std::upper_bound(peers.begin(), peers.end(), *(it), vectorCompare_l);
                        peers.insert(customUpperBound, *(it));
                        dectance = std::distance(peers.begin(), customUpperBound);
                        iteratorList =  shift_iterator_list(iteratorList, peers, dectance);
                    }
                    else
                    {
                        iter = std::next(iteratorList.begin(), index);
                        it = std::next(pand.begin(), i);
                        std::list<std::list<int> >::iterator customUpperBound = std::upper_bound(peers.begin() , *(iter), *(it), vectorCompare_l);
                        peers.insert(customUpperBound, *(it));
                        dectance = std::distance(peers.begin(), customUpperBound);
                        iteratorList =  shift_iterator_list(iteratorList, peers, dectance);
                    }
                    i--;
                }
            }
        } 
    }
    else if(rest_peers.size() > 0)
        {
            
            std::list<std::list<int> >::iterator it = rest_peers.begin();
            std::list<std::list<int> >::iterator customUpperBound = std::upper_bound(peers.begin() , peers.end(), *(it), vectorCompare_l);
            peers.insert(customUpperBound, *(it));
        }    
}

void merge_insertion_v(std::vector<std::vector<int> > &peers)
{
    peers.reserve(peers.size()+2);
    std::vector<std::vector<int> >::iterator it = peers.begin();
    std::vector<int>::iterator __it;
    it = peers.begin();
    int len = peers.size() % 2 != 0;
    std::vector<int> rest;
    std::vector<std::vector<int> > rest_peers;
    if (len)
    {
        rest = peers.at(peers.size() - 1);
        rest_peers.push_back(peers.at(peers.size() - 1));
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
                if (*(it->end() - 1) > *((it + 1)->end() - 1))
                    it->insert(it->begin(), (it+1)->begin(), (it+1)->end());
                else
                    it->insert(it->end(), (it+1)->begin(), (it+1)->end());
                (it+1)->erase((it+1)->begin(), (it+1)->end());
                peers.erase(it+1);
            }
        
        }
        if (peers.size() >= 2)
            merge_insertion_v(peers);
    }
    
    split_each_peers_v(peers);
    std::list<std::vector<std::vector<int> >::iterator> iteratorList;
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
        if(rest_peers.size() > 0)
            pand.push_back(rest_peers.at(0));
    for (std::vector<std::vector<int> >::iterator it = peers.begin(); it != peers.end(); ++it) {
        iteratorList.push_back(it);
    }
        std::list<std::vector<std::vector<int> >::iterator>::iterator iter;
        it = pand.begin();
        peers.insert(peers.begin(), *(it));
        iteratorList =  shift_iterator_vector(iteratorList, peers, 0);
        std::vector<std::vector<int> >::iterator  customUpperBound = std::upper_bound(peers.begin(), peers.begin()+2, *(it+1), vectorCompare_v);
        peers.insert(customUpperBound, *(it+1));
        int dectance = std::distance(peers.begin(), customUpperBound);
        iteratorList =  shift_iterator_vector(iteratorList, peers, dectance);
        std::vector<int> jacob = build_jacob_insertion_sequence(pand.size());
        std::vector<int>::iterator __it = jacob.begin();
        if(jacob.size() ==  0 && it+2 != pand.end())
        {
            
            customUpperBound = std::upper_bound(peers.begin(), peers.end(), *(it+2), vectorCompare_v);
            peers.insert(customUpperBound, *(it+2));
            dectance = std::distance(peers.begin(), customUpperBound);
            iteratorList =  shift_iterator_vector(iteratorList, peers, dectance);
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
                    int fo = *__it;
                    int _size = iteratorList.size();
                    if (fo == _size)
                    {
                        iter = std::next(iteratorList.begin(), iteratorList.size()-1);
                        std::vector<std::vector<int> >::iterator customUpperBound = std::upper_bound(peers.begin(), peers.end(), *(it+i), vectorCompare_v);
                        peers.insert(customUpperBound, *(it+i));
                    }
                    else
                    {
                        iter = std::next(iteratorList.begin(), fo);
                        std::vector<std::vector<int> >::iterator customUpperBound = std::upper_bound(peers.begin(), *(iter), *(it+i), vectorCompare_v);
                        peers.insert(customUpperBound, *(it+i));
                        dectance = std::distance(peers.begin(), customUpperBound);
                        iteratorList =  shift_iterator_vector(iteratorList, peers, dectance);
                        
                    }
                    i--;
                }
            }
            int _pand = pand.size();
            if (*(jacob.end() -1) < _pand)
            {
                int i = pand.size() - 1;
                int j = *(jacob.end() -1);
                int index = iteratorList.size() - 1;
                        
                while(i > j)
                {
                    _pand = pand.size() - 1;
                    if (i == _pand || i == _pand - 1)
                    {
                        std::vector<std::vector<int> >::iterator customUpperBound = std::upper_bound(peers.begin(), peers.end(), *(it + i), vectorCompare_v);
                        peers.insert(customUpperBound, *(it + i));
                        dectance = std::distance(peers.begin(), customUpperBound);
                        iteratorList =  shift_iterator_vector(iteratorList, peers, dectance);
                    }
                    else
                    {
                        iter = std::next(iteratorList.begin(), index);
                        std::vector<std::vector<int> >::iterator customUpperBound = std::upper_bound(peers.begin() , *(iter), *(it + i), vectorCompare_v);
                        peers.insert(customUpperBound, *(it + i));
                        dectance = std::distance(peers.begin(), customUpperBound);
                        iteratorList =  shift_iterator_vector(iteratorList, peers, dectance);
                        
                    }
                    i--;
                }
            }
        } 
    }
    else if(rest_peers.size() > 0)
        {
            std::vector<std::vector<int> >::iterator it = rest_peers.begin();
            std::vector<std::vector<int> >::iterator customUpperBound = std::upper_bound(peers.begin() , peers.end(), *(it), vectorCompare_v);
            peers.insert(customUpperBound, *(it));
        }
}