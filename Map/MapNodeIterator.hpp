/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapNodeIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:54:49 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/04 13:06:49 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPNODEITERATOR_HPP
# define MAPNODEITERATOR_HPP
# include "const_MapNodeIterator.hpp"
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
		class const_MapNodeIterator;

	template<class K, class V>
		class MapNodeIterator
		{
			public:
				typedef ft::pair<K, V>				value_type;
				typedef	node_pair<K, V>				node_type;
				typedef	value_type*					pointer;
				typedef value_type&					reference;
				// typedef typename choose<is_const, const T &, T &>::type reference;
				// typedef typename choose<is_const, const T *, T *>::type pointer;
				typedef	::std::ptrdiff_t			difference_type;
				// typedef	const_MapNodeIterator<K, V>	const_iterator;

				static const bool			input_iter;
				static const bool			is_not_const;
				
				MapNodeIterator(): _ptr(NULL) {}
				MapNodeIterator(node_type* ptr) : _ptr(ptr) {}
				MapNodeIterator(const MapNodeIterator& vec): _ptr(vec.getPointer())
				{
					if (PRINT)
						std::cout << "NodeIter copy ctor\n";
				}
				~MapNodeIterator() {}

				MapNodeIterator& operator=(const MapNodeIterator& vec)
				{
					if (PRINT)
						std::cout << "NodeIter operator =\n";
					this->_ptr = vec.getPointer();
					return *this;
				}

				node_type*			getPointer() const
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
					return &(this->operator*());
				}

				MapNodeIterator	operator++()
				{
					this->_ptr = this->_ptr->getNext();
					return *this;
				}

				MapNodeIterator	operator++(int)
				{
					MapNodeIterator	tmp(*this);

					this->_ptr = this->_ptr->getNext();
					return tmp;
				}

				MapNodeIterator	operator--()
				{
					this->_ptr = this->_ptr->getPrev();
					return *this;
				}

				MapNodeIterator	operator--(int)
				{
					MapNodeIterator	tmp(*this);

					this->_ptr = this->_ptr->getPrev();
					return tmp;
				}

				bool 			operator==(const MapNodeIterator& right) const 
				{
					return (this->_ptr == right.getPointer());
				}

				bool 			operator!=(const MapNodeIterator& right) const 
				{
					bool ret = (*this == right);

					return (!ret);
				}

			private:
				node_type*			_ptr;
		};

	template<class K, class V>
		bool operator!=(const MapNodeIterator<K, V>& lhs, const MapNodeIterator<K, V>& rhs)
		{
			if (PRINT)
				std::cout << "Operator != (NodeIter, NodeIter)\n";
			return !(lhs == rhs);
		}
	

	template <class K, class V>
		const bool MapNodeIterator<K, V>::input_iter = true;

	template <class K, class V>
		const bool MapNodeIterator<K, V>::is_not_const = true;
}

#endif
