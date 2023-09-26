/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchifour <bchifour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:06:15 by bchifour          #+#    #+#             */
/*   Updated: 2023/09/13 17:26:24 by bchifour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T>
class Array
{
private:
	T *_array;
	unsigned int _size;
public:
	Array<T>(void) : _array(NULL), _size(0) {}
	Array<T>(unsigned int n) : _array(new T[n]), _size(n) {}
	Array<T>(Array<T> const &src) { *this = src; }
	~Array<T>(void) { delete [] _array; }
	Array<T> &operator=(Array<T> const &rhs)
	{
		if (this != &rhs)
		{
			delete [] _array;
			_size = rhs._size;
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = rhs._array[i];
		}
		return (*this);
	}
	T &operator[](unsigned int n) const
	{
		if (n >= _size)
			throw std::exception();
		return (_array[n]);
	}
	unsigned int size(void) const { return (_size); }
};

template <typename T>
std::ostream &operator<<(std::ostream &o, Array<T> const &rhs)
{
	for (unsigned int i = 0; i < rhs.size(); i++)
		o << rhs[i] << " ";
	return (o);
}

#endif