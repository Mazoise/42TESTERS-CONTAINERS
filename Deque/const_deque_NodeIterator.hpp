/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_deque_NodeIterator.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:54:49 by hbaudet           #+#    #+#             */
/*   Updated: 2021/02/02 13:13:57 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_DEQUE_NODEITERATOR_HPP
# define CONST_DEQUE_NODEITERATOR_HPP
# include "deque_NodeIterator.hpp"
# include <iostream>

# ifdef DEBUG
#  define PRINT 1
# else
#  define PRINT 0
# endif

namespace ft
{
	template<class T>
		class deque_node;

	template<class T>
		class deque_NodeIterator;

	template<class T>
		class const_deque_NodeIterator
		{
			public:
				typedef const T							value_type;
				typedef	const deque_node<value_type>	node_type;
				typedef	const deque_node<T>*			pointer;
				typedef	const node_type*				const_pointer;
				typedef value_type&						reference;
				typedef	::std::ptrdiff_t				difference_type;

				static const bool			input_iter;
				
				const_deque_NodeIterator(): _ptr(NULL) {}
				const_deque_NodeIterator(const pointer ptr) : _ptr(ptr) {}
				const_deque_NodeIterator(const const_pointer ptr) : _ptr(ptr) {}
				const_deque_NodeIterator(const const_deque_NodeIterator& vec): _ptr(vec.getPointer())
				{
					if (PRINT)
						std::cout << "const_NodeIter copy ctor\n";
				}
				const_deque_NodeIterator(const deque_NodeIterator<T>& vec):
					_ptr(vec.getPointer())
				{
					if (PRINT)
						std::cout << "const_NodeIter copy ctor\n";
				}
				~const_deque_NodeIterator() {}

				const_deque_NodeIterator& operator=(const const_deque_NodeIterator& vec)
				{
					if (PRINT)
						std::cout << "const_NodeIter operator =\n";
					this->_ptr = vec.getPointer();
					return *this;
				}

				pointer			getPointer() const
				{
					if (PRINT)
						std::cout << "const_NodeIter getPointer()\n";
					return this->_ptr;
				}

				reference		operator*()
				{
					if (PRINT)
						std::cout << "const_NodeIter operator *\n";
					return this->_ptr->getMember();
				}

				value_type*		operator->()
				{
					if (PRINT)
						std::cout << "const_NodeIter operator ->\n";
					return (&this->_ptr->getMember());
				}

				const_deque_NodeIterator	operator++()
				{
					this->_ptr = this->_ptr->next;
					return *this;
				}

				const_deque_NodeIterator	operator++(int)
				{
					const_deque_NodeIterator	tmp(*this);

					this->_ptr = this->_ptr->next;
					return tmp;
				}

				const_deque_NodeIterator	operator--()
				{
					this->_ptr = this->_ptr->prev;
					return *this;
				}

				const_deque_NodeIterator	operator--(int)
				{
					const_deque_NodeIterator	tmp(*this);

					this->_ptr = this->_ptr->prev;
					return tmp;
				}

				const_deque_NodeIterator	operator+(size_t i)
				{
					while(i--)
						this->_ptr = this->_ptr->next;
					return *this;
				}

				const_deque_NodeIterator	operator-(size_t i)
				{
					while(i--)
						this->_ptr = this->_ptr->prev;
					return *this;
				}

				bool 			operator==(const const_deque_NodeIterator& right) const 
				{
					return (this->_ptr == right.getPointer());
				}

				bool 			operator!=(const const_deque_NodeIterator& right) const 
				{
					bool ret = (*this == right);

					return (!ret);
				}

			private:
				pointer			_ptr;
		};

	template<class T>
		bool operator!=(const const_deque_NodeIterator<T>& lhs,
			const const_deque_NodeIterator<T>& rhs)
		{
			if (PRINT)
				std::cout << "Operator != (const_NodeIter, const_NodeIter)\n";
			return !(lhs == rhs);
		}
	

	template <class T>
		const bool const_deque_NodeIterator<T>::input_iter = true;
}

#endif