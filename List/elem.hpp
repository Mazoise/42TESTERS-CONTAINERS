/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:35:37 by hbaudet           #+#    #+#             */
/*   Updated: 2020/10/19 16:55:14 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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
			elem(T& t, elem<T>* n = NULL, elem<T>* p = NULL);
			elem(const T& t, elem<T>* n = NULL, elem<T>* p = NULL);
			~elem();
			elem&	operator=(const elem&);
			elem*	next;
			elem*	prev;
	};
}

template<class T>
ft::elem<T>::elem(const ft::elem<T>& el) : m(el.getMember()), next(NULL), prev(NULL) {}

template<class T>
ft::elem<T>::elem(T& t, elem* n, elem* p) : m(t), next(n), prev(p) {}

template<class T>
ft::elem<T>::elem(const T& t, elem* n, elem* p) : m(t), next(n), prev(p) {}

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
