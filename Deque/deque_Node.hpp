/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:35:37 by hbaudet           #+#    #+#             */
/*   Updated: 2020/12/16 17:32:13 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_NODE_HPP
# define DEQUE_NODE_HPP
# include <string>
# include <iostream>

# ifdef DEBUG
#  define PRINT 1
# else
#  define PRINT 0
# endif

namespace ft
{
	template<class T>
	class deque_node
	{
		private:
			T	m;

		public:
			deque_node(const deque_node&);
			deque_node(const T& t, deque_node<T>* n = NULL, deque_node<T>* p = NULL);
			deque_node(deque_node<T>* n = NULL, deque_node<T>* p = NULL);
			~deque_node();
			deque_node&		operator=(const deque_node&);
			T&			getMember();
			const T&	getMember() const;

			deque_node*	next;
			deque_node*	prev;
	};
}

template<class T>
ft::deque_node<T>::deque_node(const deque_node& el) : m(el.getMember()), next(el.next), prev(el.prev)
{
	if (PRINT)
		std::cout << "deque_Node copy ctor\n";
}

template<class T>
ft::deque_node<T>::deque_node(const T& t, deque_node* n, deque_node* p) : m(t), next(n), prev(p)
{
	if (PRINT)
		std::cout << "deque_Node T ctor\n";
}

template<class T>
ft::deque_node<T>::deque_node(deque_node* n, deque_node* p) : m(T()), next(n), prev(p)
{
	if (PRINT)
		std::cout << "deque_Node default ctor\n";
}

template<class T>
ft::deque_node<T>::~deque_node()
{
	if (PRINT)
		std::cout << "deque_Node destructtor\n";
}

template<class T>
ft::deque_node<T>&	ft::deque_node<T>::operator=(const ft::deque_node<T>& el)
{
	if (PRINT)
		std::cout << "deque_Node operator =\n";
	this->m = el.getMember();
	this->next = el.next;
	this->prev = el.prev;
	return *this;
}

template<class T>
T&	ft::deque_node<T>::getMember()
{
	if (PRINT)
		std::cout << "deque_Node getMember()\n";
	return this->m;
}

template<class T>
const T&	ft::deque_node<T>::getMember() const
{
	if (PRINT)
		std::cout << "deque_Node const getMember()\n";
	return this->m;
}

#endif