/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NodeIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:54:49 by hbaudet           #+#    #+#             */
/*   Updated: 2020/12/21 12:48:07 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODEITERATOR_HPP
# define NODEITERATOR_HPP
# include "const_NodeIterator.hpp"
# include "Node.hpp"
# include <iostream>

# ifdef DEBUG
#  define PRINT 1
# else
#  define PRINT 0
# endif

namespace ft
{
	template<class T>
		class node;

	template<class T>
		class NodeIterator
		{
			public:
				typedef T					value_type;
				typedef	node<T>				node_type;
				typedef	node_type*			pointer;
				typedef value_type&			reference;
				typedef	::std::ptrdiff_t	difference_type;

				static const bool			input_iter;
				
				NodeIterator(): _ptr(NULL) {}
				NodeIterator(pointer ptr) : _ptr(ptr) {}
				NodeIterator(const NodeIterator& vec): _ptr(vec.getPointer())
				{
					if (PRINT)
						std::cout << "NodeIter copy ctor\n";
				}
				~NodeIterator() {}

				NodeIterator& operator=(const NodeIterator& vec)
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

				NodeIterator	operator++()
				{
					this->_ptr = this->_ptr->next;
					return *this;
				}

				NodeIterator	operator++(int)
				{
					NodeIterator	tmp(*this);

					this->_ptr = this->_ptr->next;
					return tmp;
				}

				NodeIterator	operator--()
				{
					this->_ptr = this->_ptr->prev;
					return *this;
				}

				NodeIterator	operator--(int)
				{
					NodeIterator	tmp(*this);

					this->_ptr = this->_ptr->prev;
					return tmp;
				}

				bool 			operator==(const NodeIterator& right) const 
				{
					return (this->_ptr == right.getPointer());
				}

				bool 			operator!=(const NodeIterator& right) const 
				{
					bool ret = (*this == right);

					return (!ret);
				}

			private:
				pointer			_ptr;
		};

	template<class T>
		bool operator!=(const NodeIterator<T>& lhs, const NodeIterator<T>& rhs)
		{
			if (PRINT)
				std::cout << "Operator != (NodeIter, NodeIter)\n";
			return !(lhs == rhs);
		}
	

	template < class T>
		const bool NodeIterator<T>::input_iter = true;
}

#endif
