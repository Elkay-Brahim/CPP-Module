/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:22:11 by bchifour          #+#    #+#             */
/*   Updated: 2023/09/18 19:48:16 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <deque>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(MutantStack const &rhs);
		~MutantStack();
		MutantStack &operator=(MutantStack const &rhs);
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;
		reverse_iterator rbegin();
		reverse_iterator rend();
};

template <typename T>
MutantStack<T>::MutantStack()
{
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &rhs)
{
	*this = rhs;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &rhs)
{
	(void)rhs;
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (std::stack<T>::c.begin());
}
template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
	return (std::stack<T>::c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return (std::stack<T>::c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
	return (std::stack<T>::c.rend());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return (std::stack<T>::c.rend());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return (std::stack<T>::c.end());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (std::stack<T>::c.end());
}