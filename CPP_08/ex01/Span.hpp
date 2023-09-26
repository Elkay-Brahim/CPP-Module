/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:14:47 by bchifour          #+#    #+#             */
/*   Updated: 2023/09/18 12:56:51 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Span
{
	private:
		unsigned int _n;
		unsigned int _size;
		int *_tab;
	public:
		Span();
		Span(unsigned int n);
		Span(Span const &rhs);
		~Span();
		Span &operator=(Span const &rhs);
		void addNumber(int n);
		void addrange(int start, int end);
		int shortestSpan();
		int longestSpan();
		class FullException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};