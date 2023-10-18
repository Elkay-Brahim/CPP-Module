/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_iterator.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:47:21 by bchifour          #+#    #+#             */
/*   Updated: 2023/10/06 18:00:44 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "merge_insertion.hpp"

std::list<std::list<std::list<int> >::iterator>  shift_iterator_list(std::list<std::list<std::list<int> >::iterator> iteratorList, std::list<std::list<int> > &numbers,int shift)
{
    std::list<std::list<std::list<int> >::iterator> new_iteratorList;
    int startIndex = shift;
    if (startIndex > 0) {
        
        for(std::list<std::list<std::list<int> >::iterator>::iterator it = iteratorList.begin(); it != iteratorList.end(); it++) 
        {
            new_iteratorList.push_back(*it);
            startIndex--;
            if (startIndex == 0)
                break;
        }
    }
    std::list<std::list<std::list<int> >::iterator>::iterator it = iteratorList.begin();
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

std::list<std::vector<std::vector<int> >::iterator>  shift_iterator_vector(std::list<std::vector<std::vector<int> >::iterator> iteratorList, std::vector<std::vector<int> > &numbers,int shift)
{
    std::list<std::vector<std::vector<int> >::iterator> new_iteratorList;
    int startIndex = shift;
    if (startIndex > 0) {
        
        for(std::list<std::vector<std::vector<int> >::iterator>::iterator it = iteratorList.begin(); it != iteratorList.end(); ++it) {
        new_iteratorList.push_back(*it);
        startIndex--;
        if (startIndex == 0) {
            break;
            }
        }
    }
    std::list<std::vector<std::vector<int> >::iterator>::iterator it = iteratorList.begin();
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
    return new_iteratorList;
}