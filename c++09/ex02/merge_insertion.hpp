/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_insertion.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:57:43 by bchifour          #+#    #+#             */
/*   Updated: 2023/10/06 19:13:54 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <sstream>
#include <unistd.h>
#include <ctime>

void merge_insertion_l(std::list<std::list<int> > &peers);
void merge_insertion_v(std::vector<std::vector<int> > &peers);
void split_each_peers_l(std::list<std::list<int> > &peers);
void split_each_peers_v(std::vector<std::vector<int> > &peers);
std::list<std::list<std::list<int> >::iterator>  shift_iterator_list(std::list<std::list<std::list<int> >::iterator> iteratorList, std::list<std::list<int> > &numbers,int shift);
std::list<std::vector<std::vector<int> >::iterator>  shift_iterator_vector(std::list<std::vector<std::vector<int> >::iterator> iteratorList, std::vector<std::vector<int> > &numbers,int shift);
std::vector<int> build_jacob_insertion_sequence(int len);
void print_doublevector(std::vector<std::vector<int> > doubleVector);