/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NodeIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:54:49 by hbaudet           #+#    #+#             */
/*   Updated: 2020/12/09 14:02:33 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
	template<class T>
		class NodeIterator
		{
			public:
				typedef T					value_type;
				typedef	value_type*			pointer;
				typedef	const value_type*	const_pointer;
				typedef value_type&			reference;
				typedef const value_type&	const_reference;
				typedef	std::ptrdiff_t		difference_type;

				static const bool			input_iter;
				
				NodeIterator(): _ptr(NULL) {}
				NodeIterator(value_type node) : _ptr(&node) {}
				NodeIterator(pointer ptr) : _ptr(ptr) {}
				NodeIterator(const NodeIterator& vec): _ptr(vec.getPointer()) {}
				~NodeIterator() {}

				NodeIterator& operator=(const NodeIterator& vec)
				{
					this->_ptr = vec.getPointer();
					return *this;
				}

				pointer			getPointer() const
				{
					return this->_ptr;
				}

				virtual reference		operator*()
				{
					if (PRINT)
						std::cout << "Operator*\n";
					return (*(this->_ptr));
				}

				virtual const_reference	operator*() const
				{
					if (PRINT)
						std::cout << "Const operator*\n";
					return (*(this->_ptr));
				}

				pointer			operator->()
				{
					return (this->_ptr);
				}

				NodeIterator	operator++()
				{
					this->_ptr = this->_ptr->next;
					return this;
				}

				NodeIterator	operator++(int)
				{
					NodeIterator	tmp(this);

					this->_ptr = this->_ptr->next
					return tmp;
				}

				NodeIterator	operator--()
				{
					this->_ptr = this->_ptr->prev
					return this;
				}

				NodeIterator	operator--(int)
				{
					NodeIterator	tmp(this);

					this->_ptr = this->_ptr->prev;
					return tmp;
				}

				bool 			operator==(const NodeIterator& right) const 
				{
					return (this->_ptr == right.getPointer());
				}

				bool 			operator!=(const NodeIterator& right) const 
				{
					return (!(*this == right));
				}

				pointer			getPointer() const
				{
					return this->_ptr;
				}

			private:
				pointer		_ptr;
		};

	template<class T>
		bool operator!=(const NodeIterator<T>& lhs, const NodeIterator<T>& rhs)
		{
			return !(lhs == rhs);
		}
	

	template < class T>
		const bool NodeIterator<T>::input_iter = true;


	template < class T>
		class const_NodeIterator : public NodeIterator<T>
		{
			private:
				const T*	_ptr;
			
			public:
				const_NodeIterator(): _ptr(NULL) {}
				const_NodeIterator(const NodeIterator<T>& vec): _ptr(vec.getPointer()) {}
				const_NodeIterator(const_NodeIterator& vec): _ptr(vec.getPointer()) {}
				const T&	operator*() const
				{
					return *this->_ptr;
				}
		};
}
