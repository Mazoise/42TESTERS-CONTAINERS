/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:03:47 by hbaudet           #+#    #+#             */
/*   Updated: 2020/10/21 23:16:46 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "elem.hpp"
#include "iterator.hpp"
// #include "reverse_iterator.hpp"
#include <iostream>
#include <fstream>
#include <string>

#ifdef DEBUG
# define PRINT 1
#else
# define PRINT 0
#endif

namespace ft
{
	static std::ostream& cout = std::cout;
	
	template<class T>
	class elem;
	
	template<class T>
	class iterator;
	
	template<class T>
	class reverse_iterator;

	template <class T, class Alloc = std::allocator<T> >
	class list
	{
		public:
			// TYPEDEFS	//

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

			//**********//

			list(const allocator_type& alloc = allocator_type());
			list(size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type());
			list(iterator first, iterator last,
				const allocator_type& alloc = allocator_type());
			list(const list&);
			~list();
			list&	operator=(const list&);

			//	Iterators	//
			iterator		begin();
			const_iterator	begin() const;
			iterator		end();
			const_iterator	end() const;
//			iterator		rbegin();
//			const_iterator	rbegin() const;
//			iterator		rend();
//			const_iterator	rend() const;

			//	Capacity	//
			bool			empty() const;
			size_type		size() const;


			void			push_back(const value_type& val);

		private:
			elem<T>*				_obj;
			size_type				_n;
			const allocator_type	_alloc;
	};
}


/*************************************************/
/*******************  LIST  **********************/

//COPLIEN REQUIREMENTS

template<class T, class Alloc>
ft::list<T, Alloc>::list(const allocator_type& alloc) : _obj(NULL), _n(0), _alloc(alloc)
{
	if (PRINT)
		std::cout << "Default Constructor called\n";
}

template<class T, class Alloc>
ft::list<T, Alloc>::list(size_type n, const value_type& val, const allocator_type& alloc)
		: _obj(NULL), _n(0), _alloc(alloc)
{
	if (PRINT)
		std::cout << "Fill Constructor called\n";
	this->insert(0, n, val);
}

template<class T, class Alloc>
ft::list<T, Alloc>::list(ft::list<T, Alloc>::iterator first, ft::list<T, Alloc>::iterator last,
		const allocator_type& alloc) : _obj(NULL), _n(0), _alloc(alloc)
{
	if (PRINT)
		std::cout << "Range Constructor called\n";
	this->insert(this->begin(), first, last);
}

template<class T, class Alloc>
ft::list<T, Alloc>::list(const ft::list<T, Alloc>& lst)
{
	if (PRINT)
		std::cout << "Copy Constructor called";
	*this = lst;
}

template<class T, class Alloc>
ft::list<T, Alloc>::~list()
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
ft::list<T, Alloc>&	ft::list<T, Alloc>::operator=(const ft::list<T, Alloc>& lst)
{
	if (PRINT)
		std::cout << "Assignation operator called";
	this->_n = 0;
	this->_alloc = allocator_type();
	this->insert(0, lst.front(), lst.back());
	return *this;
}

//MEMBER FUNCTIONS

// ITERATORS

template<class T, class Alloc>
typename ft::list<T, Alloc>::iterator	ft::list<T, Alloc>::begin()
{
	typename ft::list<T, Alloc>::iterator it(this->_obj);

	return it;
}

template<class T, class Alloc>
typename ft::list<T, Alloc>::const_iterator	ft::list<T, Alloc>::begin() const
{
	typename ft::list<T, Alloc>::iterator it(this->_obj);

	return it;
}

template<class T, class Alloc>
typename ft::list<T, Alloc>::iterator	ft::list<T, Alloc>::end()
{
	elem<T>*	el(this->obj);

	while (el->next)
		el = el->next;
	
	elem<T>*	ret(NULL, el);
	typename ft::list<T, Alloc>::iterator it(ret);

	return it;
}

template<class T, class Alloc>
typename ft::list<T, Alloc>::const_iterator	ft::list<T, Alloc>::end() const
{
	elem<T>*	el(this->obj);

	while (el->next)
		el = el->next;
	
	elem<T>*	ret(NULL, el);
	typename ft::list<T, Alloc>::iterator it(ret);

	return it;
}

// CAPACITY
template<class T, class Alloc>
bool	ft::list<T, Alloc>::empty() const
{
	return (this->_n == 0);
}

template<class T, class Alloc>
ft::list<T, Alloc>::size_type	ft::list<T, Alloc>::size() const
{
	return this->_n;
}



template<class T, class Alloc>
void	ft::list<T, Alloc>::push_back(const value_type& val)
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
