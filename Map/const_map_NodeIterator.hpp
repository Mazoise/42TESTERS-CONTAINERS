/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_MapNodeIterator.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:54:49 by hbaudet           #+#    #+#             */
/*   Updated: 2020/12/16 17:30:41 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_MAP_NODEITERATOR_HPP
# define CONST_MAP_NODEITERATOR_HPP
# include "map_NodeIterator.hpp"
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
		class MapNodeIterator;

	template<class K, class V>
		class const_MapNodeIterator
		{
			public:
				typedef	MapNodeIterator<K, V>	iterator_not_const;
				typedef const pair<K, V>		value_type;
				typedef	const node_pair<K, V>	node_type;
				typedef	value_type*				pointer;
				typedef value_type&				reference;
				typedef	::std::ptrdiff_t		difference_type;
				// typedef	const_MapNodeIterator	const_iterator;

				static const bool			input_iter;
				static const bool			is_not_const;
				
				const_MapNodeIterator(): _ptr(NULL) {}
				const_MapNodeIterator(const node_type* ptr) : _ptr(ptr) {}
				const_MapNodeIterator(const const_MapNodeIterator& vec): _ptr(vec.getPointer())
				{
					if (PRINT)
						std::cout << "const const_MapNodeIter copy ctor\n";
				}
				const_MapNodeIterator(const MapNodeIterator<K, V>& vec): _ptr(vec.getPointer())
				{
					if (PRINT)
						std::cout << "const_MapNodeIter copy ctor\n";
				}
				~const_MapNodeIterator() {}


				const_MapNodeIterator& operator=(const const_MapNodeIterator& vec)
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

				const_MapNodeIterator	operator++()
				{
					this->_ptr = this->_ptr->getNext();
					return *this;
				}

				const_MapNodeIterator	operator++(int)
				{
					const_MapNodeIterator	tmp(*this);

					this->_ptr = this->_ptr->getNext();
					return tmp;
				}

				const_MapNodeIterator	operator--()
				{
					this->_ptr = this->_ptr->getPrev();
					return *this;
				}

				const_MapNodeIterator	operator--(int)
				{
					const_MapNodeIterator	tmp(*this);

					this->_ptr = this->_ptr->getPrev();
					return tmp;
				}

				bool 			operator==(const const_MapNodeIterator& right) const 
				{
					return (this->_ptr == right.getPointer());
				}

				bool 			operator!=(const const_MapNodeIterator& right) const 
				{
					bool ret = (*this == right);

					return (!ret);
				}

			private:
				node_type*			_ptr;
		};

	template<class K, class V>
		bool operator!=(const const_MapNodeIterator<K, V>& lhs, const const_MapNodeIterator<K, V>& rhs)
		{
			if (PRINT)
				std::cout << "Operator != (NodeIter, NodeIter)\n";
			return !(lhs == rhs);
		}
	

	template <class K, class V>
		const bool const_MapNodeIterator<K, V>::input_iter = true;

	template <class K, class V>
		const bool const_MapNodeIterator<K, V>::is_not_const = false;
}

#endif
