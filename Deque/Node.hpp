/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:35:37 by hbaudet           #+#    #+#             */
/*   Updated: 2020/12/09 10:49:30 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

namespace ft
{
	template<class T>
	class node
	{
		private:
			T	m;

		public:
			node();
			node(const node&);
			node(T& t, node<T>* n = NULL, node<T>* p = NULL);
			node(const T& t, node<T>* n = NULL, node<T>* p = NULL);
			node(node<T>* n = NULL, node<T>* p = NULL);
			~node();
			node&	operator=(const node&);
			node&	getMember() const;
			node*	next;
			node*	prev;
	};
}

template<class T>
ft::node<T>::node(const node& el) : m(el.getMember()), next(el.next), prev(el.prev) {}

template<class T>
ft::node<T>::node(T& t, node* n, node* p) : m(t), next(n), prev(p) {}

template<class T>
ft::node<T>::node(const T& t, node* n, node* p) : m(t), next(n), prev(p) {}

template<class T>
ft::node<T>::node(node* n, node* p) : next(n), prev(p) {}

template<class T>
ft::node<T>::~node() {}

template<class T>
ft::node<T>&	ft::node<T>::operator=(const ft::node<T>& el)
{
	this->m = el.getMember();
	this->next = el.next;
	this->prev = el.prev;
	return *this;
}

template<class T>
ft::node<T>&	ft::node<T>::getMember() const
{
	return this->m;
}
