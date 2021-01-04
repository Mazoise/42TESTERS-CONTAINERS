/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NodeIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:54:49 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/04 13:06:49 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODEITERATOR_HPP
# define NODEITERATOR_HPP
// # include "const_NodeIterator.hpp"
# include "Node_pair.hpp"
# include <iostream>

# ifdef DEBUG
#  define PRINT 1
# else
#  define PRINT 0
# endif

namespace ft
{
	template<class K, class V>
		class node_pair;

	template<class K, class V>
	class	pair;

	template<class K, class V>
		class NodeIterator
		{
			public:
				typedef pair<K, V>			value_type;
				typedef	node_pair<K, V>		node_type;
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
					this->_ptr = this->_ptr->getNext();
					return *this;
				}

				NodeIterator	operator++(int)
				{
					NodeIterator	tmp(*this);

					this->_ptr = this->_ptr->getNext();
					return tmp;
				}

				NodeIterator	operator--()
				{
					this->_ptr = this->_ptr->getPrev();
					return *this;
				}

				NodeIterator	operator--(int)
				{
					NodeIterator	tmp(*this);

					this->_ptr = this->_ptr->getPrev();
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

	template<class K, class V>
		bool operator!=(const NodeIterator<K, V>& lhs, const NodeIterator<K, V>& rhs)
		{
			if (PRINT)
				std::cout << "Operator != (NodeIter, NodeIter)\n";
			return !(lhs == rhs);
		}
	

	template <class K, class V>
		const bool NodeIterator<K, V>::input_iter = true;
}

#endif
