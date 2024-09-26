/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:12:25 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/26 13:08:06 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T = int>
class Array
{
	private:
		T* 				_elements;
		unsigned int	_size;
		bool			_is_new;
	public:
		Array() 
		{ 
			_elements = new T[0];
			_size = 0;
			_is_new = 1;
		}
		Array(const Array& other)
		{
			_is_new = 0;
			*this = other;
		}
		Array& operator=(const Array& other)
		{
			unsigned int i = 0;

			if (&other == this)
				return (*this);
			if (_is_new == 1)
				delete [] _elements;
			_size = other._size;
			_elements = new T[_size];
			_is_new = 1;
			while (i < _size)
			{
				_elements[i] = other._elements[i];
				i++;
			}
			return (*this);
		}
		T&	operator[](unsigned int n)
		{
			if (n >= _size)
				throw std::exception();
			return (_elements[n]);
		}
		~Array()
		{
			delete [] _elements;
		}
	public:
		Array(unsigned int n)
		{
			_elements = new T[n];
			_size = n;			
			_is_new = 1;
		}
		unsigned int size(void) const
		{
			return (_size);
		}
		
};

#endif
