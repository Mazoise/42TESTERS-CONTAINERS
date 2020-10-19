/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:03:47 by hbaudet           #+#    #+#             */
/*   Updated: 2020/10/19 11:25:00 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

#ifdef DEBUG
# define PRINT 1
#else
# define PRINT 0
#endif

namespace ft
{
	template<class T>
	class elem
	{
		private:
			T	m;
			elem();

		public:
			elem(const elem&);
			elem(T t, T* n = NULL, T* p = NULL);
			~elem();
			elem<T>&	operator=(const elem<T>&);
			elem<T>*	next;
			elem<T>*	prev;
	};

	template <class T, class Alloc = std::allocator<T> >
	class List
	{
			private:
				elem<T>*	obj;

			public:
				List();
				List(const List&);
				~List();
				List&	operator=(const List&);
	};
}


/*************************************************/
/*******************  LIST  **********************/


template<class T, class Alloc>
ft::List<T, Alloc>::List()
{
	if (PRINT)
		std::cout << "Constructor called";
}

template<class T, class Alloc>
ft::List<T, Alloc>::~List()
{
	if (PRINT)
		std::cout << "Destructor called";
}

template<class T, class Alloc>
ft::List<T, Alloc>::List(const ft::List<T, Alloc>& obj)
{
	if (PRINT)
		std::cout << "Copy Constructor called";
	*this = obj;
}

template<class T, class Alloc>
ft::List<T, Alloc>&	ft::List<T, Alloc>::operator=(const ft::List<T, Alloc>& obj)
{
	if (PRINT)
		std::cout << "Assignation operator called";
	return *this;
}

/***************** END OF LIST  ******************/
/*************************************************/

/*************************************************/
/********************* ELEM **********************/

template<class T>
ft::elem<T>::elem(const ft::elem<T>& el) : m(el.getMember()), next(NULL), prev(NULL) {}

template<class T>
ft::elem<T>::elem(T t, T* n, T* p) : m(t), next(n), prev(p) {}

template<class T>
ft::elem<T>::~elem() {}

template<class T>
ft::elem<T>&	ft::elem<T>::operator=(const ft::elem<T>& el)
{
	this->m = el.getMember();
	this->next = el.next;
	this->prev = el.prev;
	return *this;
}

/***************** END OF ELEM *******************/
/*************************************************/