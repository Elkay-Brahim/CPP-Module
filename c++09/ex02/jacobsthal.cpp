/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jacobsthal.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:49:24 by bchifour          #+#    #+#             */
/*   Updated: 2023/10/05 15:16:01 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "merge_insertion.hpp"

int jacobsthal(int index)
{
    if (index == 0)
        return 0;
    if (index == 1)
        return 1;
    return jacobsthal(index - 1) + 2 * jacobsthal(index - 2);
}


std::vector<int> build_jacob_insertion_sequence(int len)
{
    std::vector<int> jacob;
    int jacob_len = 3;
    while(jacobsthal(jacob_len) < len)
    {
        jacob.push_back(jacobsthal(jacob_len));
        jacob_len++;
    }
    return jacob;
    
}