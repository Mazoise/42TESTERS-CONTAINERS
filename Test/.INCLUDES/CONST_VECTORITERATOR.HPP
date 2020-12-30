/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_VectorIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 16:30:45 by hbaudet           #+#    #+#             */
/*   Updated: 2020/12/11 11:28:55 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../utils.hpp"
#include "VectorIterator.hpp"
#include <limits>
#include <iostream>

#ifdef DEBUG
# define PRINT 1
#else
# define PRINT 0
#endif

namespace ft
{
	template < class T>
		class VectorIterator;

	template < class T>
		class const_VectorIterator
		{
			public:
				typedef const T			value_type;
				typedef	value_type*		pointer;
				typedef value_type&		reference;
				typedef	std::ptrdiff_t	difference_type;

				static const bool			input_iter;
				
				const_VectorIterator(): _ptr(NULL) {}
				const_VectorIterator(pointer ptr) : _ptr(ptr)
				{
					if (PRINT)
						std::cout << "const_VectorIterator ptr ctor : " << this->_ptr << '\n';
				}
				const_VectorIterator(const const_VectorIterator& vec): _ptr(vec.getPointer())
				{
					if (PRINT)
						std::cout << "const_VectorIterator copy ctor : " << this->_ptr << '\n';
				}
				const_VectorIterator(const VectorIterator<T>& vec): _ptr(vec.getPointer())
				{
					if (PRINT)
						std::cout << "const_VectorIterator copy ctor : " << this->_ptr << '\n';
				}
				~const_VectorIterator() {}
				const_VectorIterator& operator=(const const_VectorIterator& vec)
				{
					this->_ptr = vec.getPointer();
					return *this;
				}

				pointer			getPointer() const
				{
					return this->_ptr;
				}

				reference		operator*()
				{
					if (PRINT)
						std::cout << "Operator*\n";
					return (*(this->_ptr));
				}

				pointer			operator->()
				{
					return (this->_ptr);
				}

				const_VectorIterator	operator++()
				{
					++(this->_ptr);
					return this;
				}

				const_VectorIterator	operator++(int)
				{
					const_VectorIterator	tmp = *this;

					++(this->_ptr);
					return tmp;
				}

				const_VectorIterator	operator--()
				{
					--(this->_ptr);
					return *this;
				}

				const_VectorIterator	operator--(int)
				{
					const_VectorIterator	tmp = *this;

					--(this->_ptr);
					return tmp;
				}

				const_VectorIterator	operator+(difference_type i) const
				{
					const_VectorIterator	tmp(*this);

					tmp += i;
					return tmp;
				}

				const_VectorIterator	operator-(difference_type i) const
				{
					const_VectorIterator	tmp(*this);

					tmp -= i;
					return tmp;
				}

				const_VectorIterator	operator+=(difference_type i)
				{
					this->_ptr += i;
					return *this;
				}

				const_VectorIterator	operator-=(difference_type i)
				{
					this->_ptr -= i;
					return *this;
				}

				difference_type	operator-(const const_VectorIterator& vec) const
				{

					return (this->_ptr - vec.getPointer());
				}

				reference		operator[](difference_type i)
				{
					return *(this->_ptr + i);
				}

				bool operator==(const const_VectorIterator& right) const 
				{
					return (this->_ptr == right.getPointer());
				}

				bool operator!=(const const_VectorIterator& right) const 
				{
					return (!(*this == right));
				}

				bool operator<(const const_VectorIterator& right) const
				{
					return (&(*(this->_ptr)) < &(*right));
				}

				bool operator>(const const_VectorIterator& right) const
				{
					return right < *this;
				}

				bool operator<=(const const_VectorIterator& right) const
				{
					return !(*this > right);
				}

				bool operator>=(const const_VectorIterator& right) const
				{
					return !(*this < right);
				}

			protected:
				pointer		_ptr;
		};

	template<class T>
		bool operator!=(const const_VectorIterator<T>& lhs, const const_VectorIterator<T>& rhs)
		{
			return !(lhs == rhs);
		}
	

	template < class T>
	const bool const_VectorIterator<T>::input_iter = true;
}
