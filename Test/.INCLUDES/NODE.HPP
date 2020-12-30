/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:35:37 by hbaudet           #+#    #+#             */
/*   Updated: 2020/12/16 17:32:13 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP
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
	class node
	{
		private:
			T	m;

		public:
			node(const node&);
			node(const T& t, node<T>* n = NULL, node<T>* p = NULL);
			node(node<T>* n = NULL, node<T>* p = NULL);
			~node();
			node&		operator=(const node&);
			T&			getMember();
			const T&	getMember() const;

			node*	next;
			node*	prev;
	};
}

template<class T>
ft::node<T>::node(const node& el) : m(el.getMember()), next(el.next), prev(el.prev)
{
	if (PRINT)
		std::cout << "Node copy ctor\n";
}

template<class T>
ft::node<T>::node(const T& t, node* n, node* p) : m(t), next(n), prev(p)
{
	if (PRINT)
		std::cout << "Node T ctor\n";
}

template<class T>
ft::node<T>::node(node* n, node* p) : m(T()), next(n), prev(p)
{
	if (PRINT)
		std::cout << "Node default ctor\n";
}

template<class T>
ft::node<T>::~node()
{
	if (PRINT)
		std::cout << "Node destructtor\n";
}

template<class T>
ft::node<T>&	ft::node<T>::operator=(const ft::node<T>& el)
{
	if (PRINT)
		std::cout << "Node operator =\n";
	this->m = el.getMember();
	this->next = el.next;
	this->prev = el.prev;
	return *this;
}

template<class T>
T&	ft::node<T>::getMember()
{
	if (PRINT)
		std::cout << "Node getMember()\n";
	return this->m;
}

template<class T>
const T&	ft::node<T>::getMember() const
{
	if (PRINT)
		std::cout << "Node const getMember()\n";
	return this->m;
}

#endif