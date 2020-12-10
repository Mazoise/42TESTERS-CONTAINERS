/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NodeIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:54:49 by hbaudet           #+#    #+#             */
/*   Updated: 2020/12/10 14:53:32 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

#ifdef DEBUG
# define PRINT 1
#else
# define PRINT 0
#endif

namespace ft
{
	template<class Node, class T>
		class NodeIterator
		{
			public:
				typedef T					value_type;
				typedef	Node				node_type;
				typedef	node_type*			pointer;
				typedef	const node_type*	const_pointer;
				typedef value_type&			reference;
				typedef const value_type&	const_reference;
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

				virtual reference		operator*()
				{
					if (PRINT)
						std::cout << "NodeIter operator *\n";
					return this->_ptr->getMember();
				}

				virtual const_reference	operator*() const
				{
					if (PRINT)
						std::cout << "NodeIter const operator *\n";
					return this->_ptr->getMember();
				}

				pointer			operator->()
				{
					if (PRINT)
						std::cout << "NodeIter operator ->\n";
					return (this->_ptr);
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

	template<class Node, class T>
		bool operator!=(const NodeIterator<Node, T>& lhs, const NodeIterator<Node, T>& rhs)
		{
			if (PRINT)
				std::cout << "Operator != (NodeIter, NodeIter)\n";
			std::cout << "Wutwut\n";
			return !(lhs == rhs);
		}
	

	template < class Node, class T>
		const bool NodeIterator<Node, T>::input_iter = true;


	template < class Node, class T>
		class const_NodeIterator : public NodeIterator<Node, T>
		{
			private:
				const Node*	_ptr;
			
			public:
				const_NodeIterator(): _ptr(NULL) {}
				const_NodeIterator(const NodeIterator<Node, T>& vec):
					_ptr(vec.getPointer())
				{
					if (PRINT)
						std::cout << "const_NodeIter(const NodeIter) ctor\n";
				}
				const_NodeIterator(const_NodeIterator& vec): _ptr(vec.getPointer())
				{
					if (PRINT)
						std::cout << "const_NodeIter(const_NodeIter) ctor\n";
				}
				const T&	operator*() const
				{
					return this->_ptr->getMember();
				}
		};
}
