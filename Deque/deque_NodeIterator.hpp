/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_NodeIterator.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:54:49 by hbaudet           #+#    #+#             */
/*   Updated: 2021/02/02 13:08:28 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_NODEITERATOR_HPP
# define DEQUE_NODEITERATOR_HPP
# include "deque_Node.hpp"
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
		class deque_NodeIterator
		{
			public:
				typedef T					value_type;
				typedef	deque_node<T>		node_type;
				typedef	node_type*			pointer;
				typedef value_type&			reference;
				typedef	::std::ptrdiff_t	difference_type;

				static const bool			input_iter;
				
				deque_NodeIterator(): _ptr(NULL) {}
				deque_NodeIterator(pointer ptr) : _ptr(ptr) {}
				deque_NodeIterator(const deque_NodeIterator& vec): _ptr(vec.getPointer())
				{
					if (PRINT)
						std::cout << "NodeIter copy ctor\n";
				}
				~deque_NodeIterator() {}

				deque_NodeIterator& operator=(const deque_NodeIterator& vec)
				{
					if (PRINT)
						std::cout << "NodeIter operator =\n";
					this->_ptr = vec.getPointer();
					return *this;
				}

				pointer			getPointer() const
				{
					if (PRINT)
						std::cout << "NodeIter getPointer()\n";
					return this->_ptr;
				}

				reference		operator*()
				{
					if (PRINT)
						std::cout << "NodeIter operator *\n";
					return this->_ptr->getMember();
				}

				value_type*		operator->()
				{
					if (PRINT)
						std::cout << "NodeIter operator ->\n";
					return (&this->_ptr->getMember());
				}

				deque_NodeIterator	operator++()
				{
					this->_ptr = this->_ptr->next;
					return *this;
				}

				deque_NodeIterator	operator++(int)
				{
					deque_NodeIterator	tmp(*this);

					this->_ptr = this->_ptr->next;
					return tmp;
				}

				deque_NodeIterator	operator+(size_t i)
				{
					while(i--)
						this->_ptr = this->_ptr->next;
					return *this;
				}

				deque_NodeIterator	operator-(size_t i)
				{
					while(i--)
						this->_ptr = this->_ptr->prev;
					return *this;
				}

				deque_NodeIterator	operator--()
				{
					this->_ptr = this->_ptr->prev;
					return *this;
				}

				deque_NodeIterator	operator--(int)
				{
					deque_NodeIterator	tmp(*this);

					this->_ptr = this->_ptr->prev;
					return tmp;
				}

				bool 			operator==(const deque_NodeIterator& right) const 
				{
					return (this->_ptr == right.getPointer());
				}

				bool 			operator!=(const deque_NodeIterator& right) const 
				{
					bool ret = (*this == right);

					return (!ret);
				}

			private:
				pointer			_ptr;
		};

	template<class T>
		bool operator!=(const deque_NodeIterator<T>& lhs, const deque_NodeIterator<T>& rhs)
		{
			if (PRINT)
				std::cout << "Operator != (NodeIter, NodeIter)\n";
			return !(lhs == rhs);
		}
	

	template < class T>
		const bool deque_NodeIterator<T>::input_iter = true;
}

#endif