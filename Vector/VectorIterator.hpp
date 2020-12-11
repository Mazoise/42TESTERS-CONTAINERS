/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 16:30:45 by hbaudet           #+#    #+#             */
/*   Updated: 2020/12/11 11:28:34 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../utils.hpp"
#include "const_VectorIterator.hpp"
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
		class VectorIterator
		{
			public:
				typedef T					value_type;
				typedef	value_type*			pointer;
				typedef value_type&			reference;
				typedef	std::ptrdiff_t		difference_type;

				static const bool			input_iter;
				
				VectorIterator(): _ptr(NULL) {}
				VectorIterator(pointer ptr) : _ptr(ptr)
				{
					if (PRINT)
						std::cout << "VectorIterator ptr ctor : " << this->_ptr << '\n';
				}
				VectorIterator(const VectorIterator& vec): _ptr(vec.getPointer())
				{
					if (PRINT)
						std::cout << "VectorIterator copy ctor : " << this->_ptr << '\n';
				}
				~VectorIterator() {}
				VectorIterator& operator=(const VectorIterator& vec)
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

				VectorIterator	operator++()
				{
					++(this->_ptr);
					return this;
				}

				VectorIterator	operator++(int)
				{
					VectorIterator	tmp = *this;

					++(this->_ptr);
					return tmp;
				}

				VectorIterator	operator--()
				{
					--(this->_ptr);
					return *this;
				}

				VectorIterator	operator--(int)
				{
					VectorIterator	tmp = *this;

					--(this->_ptr);
					return tmp;
				}

				VectorIterator	operator+(difference_type i) const
				{
					VectorIterator	tmp(*this);

					tmp += i;
					return tmp;
				}

				VectorIterator	operator-(difference_type i) const
				{
					VectorIterator	tmp(*this);

					tmp -= i;
					return tmp;
				}

				VectorIterator	operator+=(difference_type i)
				{
					this->_ptr += i;
					return *this;
				}

				VectorIterator	operator-=(difference_type i)
				{
					this->_ptr -= i;
					return *this;
				}

				difference_type	operator-(const VectorIterator& vec) const
				{
					return (this->_ptr - vec.getPointer());
				}

				difference_type	operator-(const const_VectorIterator<T>& vec) const
				{
					return (this->_ptr - vec.getPointer());
				}

				reference		operator[](difference_type i)
				{
					return *(this->_ptr + i);
				}

				bool operator==(const VectorIterator& right) const 
				{
					return (this->_ptr == right.getPointer());
				}

				bool operator==(const const_VectorIterator<T>& right) const 
				{
					return (this->_ptr == right.getPointer());
				}

				bool operator!=(const VectorIterator& right) const 
				{
					return (!(*this == right));
				}

				bool operator!=(const const_VectorIterator<T>& right) const 
				{
					return (!(*this == right));
				}
				
				bool operator<(const VectorIterator& right) const
				{
					return this->_ptr < right.getPointer();
				}

				bool operator<(const const_VectorIterator<T>& right) const
				{
					return this->_ptr < right.getPointer();
				}

				bool operator>(const VectorIterator& right) const
				{
					return right < *this;
				}

				bool operator>(const const_VectorIterator<T>& right) const
				{
					return right < *this;
				}

				bool operator<=(const VectorIterator& right) const
				{
					return !(*this > right);
				}

				bool operator<=(const const_VectorIterator<T>& right) const
				{
					return !(*this > right);
				}

				bool operator>=(const VectorIterator& right) const
				{
					return !(*this < right);
				}

				bool operator>=(const const_VectorIterator<T>& right) const
				{
					return !(*this < right);
				}

			protected:
				pointer		_ptr;
		};

	template<class T>
		bool operator!=(const VectorIterator<T>& lhs, const VectorIterator<T>& rhs)
		{
			return !(lhs == rhs);
		}
	

	template < class T>
	const bool VectorIterator<T>::input_iter = true;
}
