/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:53:32 by bchifour          #+#    #+#             */
/*   Updated: 2023/10/05 15:19:33 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include <sstream>
#include <unistd.h>

int count = 0;
int size;
int co;
int fo = 0;

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
bool isSortedAscending(const std::vector<int>& vec) {
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
std::list<std::vector<std::vector<int> >::iterator>  shift_iterator(std::list<std::vector<std::vector<int> >::iterator> iteratorList, std::vector<std::vector<int> > &numbers,int shift)
{
    std::list<std::vector<std::vector<int> >::iterator> new_iteratorList;
    int startIndex = shift; // For example, start shifting from the third element (index 2)
    if (startIndex > 0) {
        
        for(auto it = iteratorList.begin(); it != iteratorList.end(); ++it) {
        new_iteratorList.push_back(*it);
        startIndex--;
        if (startIndex == 0) {
            break;
            }
        }
    }
    // std::cout << std::endl;
    auto it = iteratorList.begin();
    it = std::next(it, shift);
    for (; it != iteratorList.end(); ++it) {
        // Advance the iterator by shiftAmount positions
        std::vector<std::vector<int> >::iterator shiftedIterator = std::next(*it, 1);



        // Check if the shifted iterator is still within the vector
        if (shiftedIterator != numbers.end()) {
            new_iteratorList.push_back(shiftedIterator);
        }
        else
            break;
    }
    // for(auto it = new_iteratorList.begin(); it != new_iteratorList.end(); ++it) {
    //     std::cout << *((*it)->end()-1) << "-";
    // }
    // std::cout << std::endl;

    return new_iteratorList;
}

void merge_insertion(std::vector<std::vector<int> > &peers)
{
    peers.reserve(peers.size()+1);
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
        {
            pand.push_back(rest_peers.at(0));
        }
    // std::cout << "peers " << std::endl;
    for (auto it = peers.begin(); it != peers.end(); ++it) {
        iteratorList.push_back(it);
        // std::cout << *((it)->end()-1) << "-";
    }
        // std::cout << std::endl;

        std::list<std::vector<std::vector<int> >::iterator>::iterator iter;
        
        it = pand.begin();
        peers.insert(peers.begin(), *(it));
        iteratorList =  shift_iterator(iteratorList, peers, 0);
        std::vector<std::vector<int> >::iterator  customUpperBound = std::upper_bound(peers.begin(), peers.begin()+2, *(it+1), vectorCompare);
        peers.insert(customUpperBound, *(it+1));
        int dectance = std::distance(peers.begin(), customUpperBound);
        iteratorList =  shift_iterator(iteratorList, peers, dectance);
        std::vector<int> jacob = build_jacob_insertion_sequence(pand);
        std::vector<int>::iterator __it = jacob.begin();
        std::vector<int> next_jacob = build_jacob_insertion_sequence(peers);
        std::vector<int>::iterator it_next = next_jacob.begin();
        if(jacob.size() ==  0 && it+2 != pand.end())
        {
            
            customUpperBound = std::upper_bound(peers.begin(), peers.end(), *(it+2), vectorCompare);
            peers.insert(customUpperBound, *(it+2));
            dectance = std::distance(peers.begin(), customUpperBound);
            iteratorList =  shift_iterator(iteratorList, peers, dectance);
        }
    
        
        if (jacob.size() > 0 )
        {
            int index = 8;
            int zip = 0;
            for(__it = jacob.begin(); __it != jacob.end(); __it++)
            {
                if(it_next != next_jacob.end())
                    it_next++;
                int i = *__it;
                int ja;
                int j;
                if (__it == jacob.begin())
                    j = 1;
                else
                    j = *(__it - 1);
                while(i > j)
                {
                    if (__it != jacob.end()-1 && jacob.size() > 1)
                        ja = *(__it + 1);
                    else
                        ja = *__it;
                    fo = *__it;
                    if (fo == iteratorList.size())
                    {
                        iter = std::next(iteratorList.begin(), iteratorList.size()-1);
                        std::vector<std::vector<int> >::iterator customUpperBound = std::upper_bound(peers.begin(), peers.end()-1, *(it+i), vectorCompare);
                        peers.insert(customUpperBound, *(it+i));
                        std::cout << "hi\n";
                        // dectance = std::distance(peers.begin(), customUpperBound);
                        // iteratorList =  shift_iterator(iteratorList, peers, dectance);
                    }
                    else
                    {
                        iter = std::next(iteratorList.begin(), fo);
                        // std::cout << "******************* "<< *((*iter)->end()-1) <<" "<< *((it+i)->end()-1) << std::endl;
                        std::vector<std::vector<int> >::iterator customUpperBound = std::upper_bound(peers.begin(), *(iter), *(it+i), vectorCompare);
                        peers.insert(customUpperBound, *(it+i));
                        dectance = std::distance(peers.begin(), customUpperBound);
                        iteratorList =  shift_iterator(iteratorList, peers, dectance);
                        
                    }

                    it = pand.begin();
                    if (it+i != pand.end())
                    {
                    }
                    index += 2;
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
                        std::vector<std::vector<int> >::iterator customUpperBound = std::upper_bound(peers.begin(), peers.end(), *(it + i), vectorCompare);
                        peers.insert(customUpperBound, *(it + i));
                        dectance = std::distance(peers.begin(), customUpperBound);
                        iteratorList =  shift_iterator(iteratorList, peers, dectance);
                    }
                    else
                    {
                        iter = std::next(iteratorList.begin(), index);
                        std::vector<std::vector<int> >::iterator customUpperBound = std::upper_bound(peers.begin() , *(iter), *(it + i), vectorCompare);
                        peers.insert(customUpperBound, *(it + i));
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
            // std::cout << " tak rest " << std::endl;
            // print_doublevector(rest_peers);
            std::vector<std::vector<int> >::iterator it = rest_peers.begin();
            std::vector<std::vector<int> >::iterator customUpperBound = std::upper_bound(peers.begin() , peers.end(), *(it), vectorCompare);
            peers.insert(customUpperBound, *(it));
            // int dectance = std::distance(peers.begin(), customUpperBound);
            // iteratorList =  shift_iterator(iteratorList, peers, dectance);
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
    std::list<std::list<int> > doubleList;
    doubleVector.reserve(21);
    std::vector<int> vc;
    std::list<int> vL;
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
        doubleVector.push_back(vc);
        doubleList.push_back(vL);
        vc.clear();
        vL.clear();
    }
    // std::cout<< doubleVector.size() << std::endl;
    merge_insertion(doubleVector);
    print_doublevector(doubleVector);
    
    std::cout << "comparition " << count << std::endl;
}