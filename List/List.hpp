/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:03:47 by hbaudet           #+#    #+#             */
/*   Updated: 2020/10/20 15:02:53 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "elem.hpp"
#include "iterator.hpp"
// #include "reverse_iterator.hpp"

#ifdef DEBUG
# define PRINT 1
#else
# define PRINT 0
#endif

namespace ft
{
	template<class T>
	class elem;
	
	template<class T>
	class iterator;

	template <class T, class Alloc = std::allocator<T> >
	class List
	{
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename ft::iterator< elem<T> >			iterator;
			typedef const ft::iterator< elem<T> >				const_iterator;
			typedef typename ft::reverse_iterator< elem<T> >	reverse_iterator;
			typedef const ft::reverse_iterator< elem<T> >		const_reverse_iterator;
			typedef ptrdiff_t									difference_type;
			typedef size_t										size_type;
			
			private:
				elem<T>*				_obj;
				size_type				_n;
				const allocator_type	_alloc;

			public:
				List(const allocator_type& alloc = allocator_type());
				List(size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type());
				List(const List&);
				~List();
				List&	operator=(const List&);

				void			push_back(const value_type& val);
	};
}


/*************************************************/
/*******************  LIST  **********************/

//COPLIEN REQUIREMENTS

template<class T, class Alloc>
ft::List<T, Alloc>::List(const allocator_type& alloc) : _obj(NULL), _n(0), _alloc(alloc)
{
	if (PRINT)
		std::cout << "Default Constructor called";
}

template<class T, class Alloc>
ft::List<T, Alloc>::List(size_type n, const value_type& val, const allocator_type& alloc)
		: _obj(NULL), _n(0), _alloc(alloc)
{
	if (PRINT)
		std::cout << "Fill Constructor called";
	this->insert(0, n, val);
}

template<class T, class Alloc>
ft::List<T, Alloc>::~List()
{
	iterator	it;
	iterator	it2;
	
	if (PRINT)
		std::cout << "Destructor called";
	it = this->_obj;
	while (it != NULL)
	{
		it2 = it + 1;
		delete *it;
		it = it2;
	}
}

template<class T, class Alloc>
ft::List<T, Alloc>::List(const ft::List<T, Alloc>& lst)
{
	if (PRINT)
		std::cout << "Copy Constructor called";
	*this = lst;
}

template<class T, class Alloc>
ft::List<T, Alloc>&	ft::List<T, Alloc>::operator=(const ft::List<T, Alloc>& lst)
{
	if (PRINT)
		std::cout << "Assignation operator called";
	this->_n = 0;
	this->_alloc = allocator_type();
	this->insert(0, lst.front(), lst.back());
	return *this;
}

//MEMBER FUNCTIONS

template<class T, class Alloc>
void	ft::List<T, Alloc>::push_back(const value_type& val)
{
	iterator	it;

	if (!this->_obj)
	{
		this->_obj = new elem<value_type>(val);
		this->_n = 1;
		return;
	}
	it = this->_obj;
	while ((it + 1) != NULL)
		it++;
	it->next = new elem<value_type>(val);
	this->_n = this->_n + 1;
}


/***************** END OF LIST  ******************/
/*************************************************/

/*************************************************/
/********************* ELEM **********************/


/***************** END OF ELEM *******************/
/*************************************************/

/*************************************************/
/********************* ITERATOR ******************/
