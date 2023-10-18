/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_each_peers.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:53:08 by bchifour          #+#    #+#             */
/*   Updated: 2023/10/05 15:14:45 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "merge_insertion.hpp"

void split_each_peers_l(std::list<std::list<int> > &peers)
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

void split_each_peers_v(std::vector<std::vector<int> > &peers)
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