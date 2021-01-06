/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:35:37 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/06 17:54:55 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_PAIR_HPP
# define NODE_PAIR_HPP
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

			pair&	operator=(const pair& p)
			{
				this->first = p.first;
				this->second = p.second;

				return *this;
			}

			K	first;
			V	second;
	};

	template<class K, class V>
	class node_pair
	{
		private:
			pair<K, V>	m;

		public:
			node_pair();
			node_pair(const node_pair&);
			node_pair(const pair<K, V>&, node_pair* n = NULL,
				node_pair* p = NULL, node_pair* parent = NULL); 
			~node_pair();
			node_pair&			operator=(const node_pair&);
			pair<K, V>&			getMember();
			const pair<K, V>&	getMember() const;

			node_pair*	next;
			node_pair*	prev;
			node_pair*	parent;
			node_pair*	getNext(const node_pair* source = NULL) const;
			node_pair*	getPrev(const node_pair* source = NULL) const;
	};
}

template<class K, class V>
ft::node_pair<K, V>::node_pair():
	next(NULL), prev(NULL), parent(NULL)
{
	// if (PRINT)
	// 	std::cout << "Node default ctor\n";
}

template<class K, class V>
ft::node_pair<K, V>::node_pair(const node_pair& el):
	m(el.getMember()), next(el.next), prev(el.prev), parent(el.parent)
{
	// if (PRINT)
	// 	std::cout << "Node copy ctor\n";
}

template<class K, class V>
ft::node_pair<K, V>::node_pair(const pair<K, V>& pair, node_pair* n, node_pair* p, node_pair* par):
	m(pair), next(n), prev(p), parent(par)
{
	// if (PRINT)
	// 	std::cout << "Node pair ctor : " << pair.first << ", " << pair.second << "\n";
}

template<class K, class V>
ft::node_pair<K, V>::~node_pair()
{
	if (PRINT)
		std::cout << "Node destructor\n";
}

template<class K, class V>
ft::node_pair<K, V>&	ft::node_pair<K, V>::operator=(const ft::node_pair<K, V>& el)
{
	if (PRINT)
		std::cout << "Node operator =\n";
	this->m = el.getMember();
	this->next = el.next;
	this->prev = el.prev;
	this->parent = el.parent;
	return *this;
}

template<class K, class V>
ft::pair<K, V>&	ft::node_pair<K, V>::getMember()
{
	// if (PRINT)
	// 	std::cout << "Node getMember() : " << this->m.first << ", " << this->m.second << "\n";
	return this->m;
}

template<class K, class V>
const ft::pair<K, V>&	ft::node_pair<K, V>::getMember() const
{
	if (PRINT)
		std::cout << "Node const getMember()" << this->m.first << ", " << this->m.second << "\n";
	return this->m;
}

template<class K, class V>
ft::node_pair<K, V>*	ft::node_pair<K, V>::getNext(const node_pair<K, V>* source) const
{
	if (source != this->next && this->next)
		return (this->next);
	if (this->parent)
		return (this->parent->getNext(this));
	return (NULL);
}

template<class K, class V>
ft::node_pair<K, V>*	ft::node_pair<K, V>::getPrev(const node_pair<K, V>* source) const
{
	if (source != this->prev && this->prev)
		return (this->prev);
	if (this->parent)
		return (this->parent->getNext(this));
	return (NULL);
}

#endif
