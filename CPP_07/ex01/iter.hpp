/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:39:26 by bchifour          #+#    #+#             */
/*   Updated: 2023/09/15 17:22:32 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void print(T const &x)
{
	std::cout << x << std::endl;
}

template <typename T>

void iter(T *tab, int const &size, void (*f)(T const &))
{
	for (int i = 0; i < size; i++)
		f(tab[i]);
}