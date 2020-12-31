/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:35:37 by hbaudet           #+#    #+#             */
/*   Updated: 2020/12/21 13:29:19 by hbaudet          ###   ########.fr       */
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
	template<class K, class V>
	class	pair
	{
		public:
			pair(const K& k = K(), const V& v = V()): first(k), second(v) {}
			~pair() {}
			K	first;
			V	second;
	};

	template<class T>
	class node_pair
	{
		private:
			T	m;

		public:
			node_pair(const node_pair&);
			node_pair(const T& t, node_pair<T>* n = NULL,
				node_pair<T>* p = NULL, node_pair<T>*pa); 
			~node_pair();
			node_pair&		operator=(const node_pair&);
			T&			getMember();
			const T&	getMember() const;

			node_pair*	next;
			node_pair*	prev;
			node_pair*	parent;
			node_pair*	getNext(node_pair* source = NULL) const;
			node_pair*	getPrev() const;
	};
}

template<class T>
ft::node_pair<T>::node_pair(const node_pair& el):
	m(el.getMember()), next(el.next), prev(el.prev)
{
	if (PRINT)
		std::cout << "Node copy ctor\n";
}

template<class T>
ft::node_pair<T>::node_pair(const T& t, node_pair* n, node_pair* p, node_pair* pa):
	m(t), next(n), prev(p), parent(pa)
{
	if (PRINT)
		std::cout << "Node T ctor\n";
}

template<class T>
ft::node_pair<T>::~node_pair()
{
	if (PRINT)
		std::cout << "Node destructtor\n";
}

template<class T>
ft::node_pair<T>&	ft::node_pair<T>::operator=(const ft::node_pair<T>& el)
{
	if (PRINT)
		std::cout << "Node operator =\n";
	this->m = el.getMember();
	this->next = el.next;
	this->prev = el.prev;
	return *this;
}

template<class T>
T&	ft::node_pair<T>::getMember()
{
	if (PRINT)
		std::cout << "Node getMember()\n";
	return this->m;
}

template<class T>
const T&	ft::node_pair<T>::getMember() const
{
	if (PRINT)
		std::cout << "Node const getMember()\n";
	return this->m;
}

template<class T>
ft::node_pair<T>*	ft::node_pair<T>::getNext(node_pair<T>* source) const
{
	if (source != this->next)
		return (this->next.getNext(this));
	return (this->parent.getNext(this));
}

template<class T>
ft::node_pair<T>*	ft::node_pair<T>::getPrev() const
{
	return this->prev;
}

#endif
