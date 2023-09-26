/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:50:17 by bchifour          #+#    #+#             */
/*   Updated: 2023/09/15 17:11:09 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}
template <typename T>
T min(T &a, T &b)
{
	if (a < b)
		return (a);
	return (b);
}

template <typename T>
T max(T &a, T &b)
{
	if (a > b)
		return (a);
	return (b);
}