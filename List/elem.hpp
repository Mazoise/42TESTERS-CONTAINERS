/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:35:37 by hbaudet           #+#    #+#             */
/*   Updated: 2020/10/21 19:03:06 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

namespace ft
{
	template<class T>
	class elem
	{
		private:
			T	m;

		public:
			elem();
			elem(const elem&);
			elem(T& t, elem<T>* n = NULL, elem<T>* p = NULL);
			elem(const T& t, elem<T>* n = NULL, elem<T>* p = NULL);
			elem(elem<T>* n = NULL, elem<T>* p = NULL);
			~elem();
			elem&	operator=(const elem&);
			elem&	getMember() const;
			elem*	next;
			elem*	prev;
	};
}

template<class T>
ft::elem<T>::elem(const elem& el) : m(el.getMember()), next(el.next), prev(el.prev) {}

template<class T>
ft::elem<T>::elem(T& t, elem* n, elem* p) : m(t), next(n), prev(p) {}

template<class T>
ft::elem<T>::elem(const T& t, elem* n, elem* p) : m(t), next(n), prev(p) {}

template<class T>
ft::elem<T>::elem(elem* n, elem* p) : next(n), prev(p) {}

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

template<class T>
ft::elem<T>&	ft::elem<T>::getMember() const
{
	return this->m;
}
