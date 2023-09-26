/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:17:22 by bchifour          #+#    #+#             */
/*   Updated: 2023/09/19 17:30:57 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
	_n = 0;
	_size = 0;
	_tab = NULL;
}

Span::Span(unsigned int n)
{
	_n = n;
	std::cout << "n = " << n << std::endl;
	_size = 0;
	_tab = new int[n];
}

Span::Span(Span const &rhs)
{
	*this = rhs;
}

Span::~Span()
{
	delete [] _tab;
}

Span &Span::operator=(Span const &rhs)
{
	_n = rhs._n;
	_size = rhs._size;
	_tab = new int[_n];
	for (unsigned int i = 0; i < _size; i++)
		_tab[i] = rhs._tab[i];
	return (*this);
}

const char *Span::FullException::what() const throw()
{
	return ("Span is full");
}

void Span::addNumber(int n)
{
	if (_size >= _n)
		throw Span::FullException();
	_tab[_size] = n;
	_size++;
}

void Span::addrange(int start, int end)
{
	if (_size + (end - start) >= _n)
		throw Span::FullException();
	for (int i = start; i <= end; i++)
	{
		_tab[_size] = i;
		_size++;
	}
}

int Span::shortestSpan()
{
	if (_size <= 1)
		throw Span::FullException();
	int check = 2147483647;
	for (unsigned int i = 0; i < _size; i++)
	{
		for (unsigned int j = i + 1; j < _size; j++)
		{
			if (abs(_tab[i] - _tab[j]) < check)
				check = abs(_tab[i] - _tab[j]);
		}
	}
	return (check);
}

int Span::longestSpan()
{
	if (_size <= 1)
		throw Span::FullException();
	int min = _tab[0];
	int max = _tab[0];
	for (unsigned int i = 0; i < _size; i++)
	{
		if (_tab[i] < min)
			min = _tab[i];
		if (_tab[i] > max)
			max = _tab[i];
	}
	return (max - min);
}