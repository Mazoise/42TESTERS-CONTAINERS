/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_NodeIterator.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:54:49 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/04 11:45:50 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_NODEITERATOR_HPP
# define CONST_NODEITERATOR_HPP
# include "NodeIterator.hpp"
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
		class NodeIterator;

	template<class T>
		class const_NodeIterator
		{
			public:
				typedef const T					value_type;
				typedef	const node<value_type>	node_type;
				typedef	const node<T>*			pointer;
				typedef	const node_type*		const_pointer;
				typedef value_type&				reference;
				typedef	::std::ptrdiff_t		difference_type;

				static const bool			input_iter;
				
				const_NodeIterator(): _ptr(NULL) {}
				const_NodeIterator(const pointer ptr) : _ptr(ptr) {}
				const_NodeIterator(const const_pointer ptr) : _ptr(ptr) {}
				const_NodeIterator(const const_NodeIterator& vec): _ptr(vec.getPointer())
				{
					if (PRINT)
						std::cout << "const_NodeIter copy ctor\n";
				}
				const_NodeIterator(const NodeIterator<T>& vec):
					_ptr(vec.getPointer())
				{
					if (PRINT)
						std::cout << "const_NodeIter copy ctor\n";
				}
				~const_NodeIterator() {}

				const_NodeIterator& operator=(const const_NodeIterator& vec)
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

				const_NodeIterator	operator++()
				{
					this->_ptr = this->_ptr->next;
					return *this;
				}

				const_NodeIterator	operator++(int)
				{
					const_NodeIterator	tmp(*this);

					this->_ptr = this->_ptr->next;
					return tmp;
				}

				const_NodeIterator	operator--()
				{
					this->_ptr = this->_ptr->prev;
					return *this;
				}

				const_NodeIterator	operator--(int)
				{
					const_NodeIterator	tmp(*this);

					this->_ptr = this->_ptr->prev;
					return tmp;
				}

				bool 			operator==(const const_NodeIterator& right) const 
				{
					return (this->_ptr == right.getPointer());
				}

				bool 			operator!=(const const_NodeIterator& right) const 
				{
					bool ret = (*this == right);

					return (!ret);
				}

			private:
				pointer			_ptr;
		};

	template<class T>
		bool operator!=(const const_NodeIterator<T>& lhs,
			const const_NodeIterator<T>& rhs)
		{
			if (PRINT)
				std::cout << "Operator != (const_NodeIter, const_NodeIter)\n";
			return !(lhs == rhs);
		}
	

	template <class T>
		const bool const_NodeIterator<T>::input_iter = true;
}

#endif