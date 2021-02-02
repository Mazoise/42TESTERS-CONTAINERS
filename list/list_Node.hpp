/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:35:37 by hbaudet           #+#    #+#             */
/*   Updated: 2020/12/16 17:32:52 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_NODE_HPP
# define LIST_NODE_HPP
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
	class list_node
	{
		private:
			T	m;

		public:
			list_node(const list_node&);
			list_node(const T& t, list_node<T>* n = NULL, list_node<T>* p = NULL);
			list_node(list_node<T>* n = NULL, list_node<T>* p = NULL);
			~list_node();
			list_node&		operator=(const list_node&);
			T&			getMember();
			const T&	getMember() const;

			list_node*	next;
			list_node*	prev;
	};
}

template<class T>
ft::list_node<T>::list_node(const list_node& el) : m(el.getMember()), next(el.next), prev(el.prev)
{
	if (PRINT)
		std::cout << "list_Node copy ctor\n";
}

template<class T>
ft::list_node<T>::list_node(const T& t, list_node* n, list_node* p) : m(t), next(n), prev(p)
{
	if (PRINT)
		std::cout << "list_Node T ctor\n";
}

template<class T>
ft::list_node<T>::list_node(list_node* n, list_node* p) : m(T()), next(n), prev(p)
{
	if (PRINT)
		std::cout << "list_Node default ctor\n";
}

template<class T>
ft::list_node<T>::~list_node()
{
	if (PRINT)
		std::cout << "list_Node destructtor\n";
}

template<class T>
ft::list_node<T>&	ft::list_node<T>::operator=(const ft::list_node<T>& el)
{
	if (PRINT)
		std::cout << "list_Node operator =\n";
	this->m = el.getMember();
	this->next = el.next;
	this->prev = el.prev;
	return *this;
}

template<class T>
T&	ft::list_node<T>::getMember()
{
	if (PRINT)
		std::cout << "list_Node getMember()\n";
	return this->m;
}

template<class T>
const T&	ft::list_node<T>::getMember() const
{
	if (PRINT)
		std::cout << "list_Node const getMember()\n";
	return this->m;
}

#endif