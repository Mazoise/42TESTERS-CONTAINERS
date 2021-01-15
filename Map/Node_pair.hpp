/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:35:37 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/15 16:08:05 by hbaudet          ###   ########.fr       */
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
	template<class Key, class T>
	class	pair
	{
		public:
			pair(const Key& k = Key(), const T& v = T()): first(k), second(v) {}
			~pair() {}

			pair&	operator=(const pair& p)
			{
				this->first = p.first;
				this->second = p.second;

				return *this;
			}

			Key	first;
			T	second;
	};

	template<class Key, class T>
	class node_pair
	{
		private:
			ft::pair<Key, T>	m;

		public:
			node_pair();
			node_pair(const node_pair&);
			node_pair(const pair<Key, T>&, node_pair* n = NULL,
				node_pair* p = NULL, node_pair* parent = NULL); 
			~node_pair();
			node_pair&			operator=(const node_pair&);
			ft::pair<Key, T>&			getMember();
			const ft::pair<Key, T>&	getMember() const;

			node_pair*	next;
			node_pair*	prev;
			node_pair*	parent;
			node_pair*	getNext(const node_pair* source = NULL) const;
			node_pair*	getPrev(const node_pair* source = NULL) const;
	};

	template<class Key, class T>
		bool	operator==(const ft::pair<Key, T>& left, const ft::pair<Key, T>& right)
		{
			return left.first == right.first && left.second == right.second;
		}

	template<class Key, class T>
		bool	operator==(ft::pair<Key, T>& left, ft::pair<Key, T>& right)
		{
			return left.first == right.first && left.second == right.second;
		}
		
	template<class Key, class T>
		bool	operator<(const ft::pair<Key, T>& left, const ft::pair<Key, T>& right)
		{
			return left.first < right.first || (left.first == right.first && left.second < right.second);
		}

	template<class Key, class T>
		bool	operator!=(const ft::pair<Key, T>& left, const ft::pair<Key, T>& right)
		{
			return (!(left == right));
		}

	template<class Key, class T>
		bool	operator>(const ft::pair<Key, T>& left, const ft::pair<Key, T>& right)
		{
			return (right < left);
		}

	template<class Key, class T>
		bool	operator<=(const ft::pair<Key, T>& left, const ft::pair<Key, T>& right)
		{
			return (!(right < left));
		}

	template<class Key, class T>
		bool	operator>=(const ft::pair<Key, T>& left, const ft::pair<Key, T>& right)
		{
			return (!(left < right));
		}
}

template<class Key, class T>
	ft::node_pair<Key, T>::node_pair():
		next(NULL), prev(NULL), parent(NULL)
	{
		if (PRINT)
			std::cout << "Node default ctor\n";
	}

template<class Key, class T>
	ft::node_pair<Key, T>::node_pair(const node_pair& el):
		m(el.getMember()), next(el.next), prev(el.prev), parent(el.parent)
	{
		if (PRINT)
			std::cout << "Node copy ctor\n";
	}

template<class Key, class T>
	ft::node_pair<Key, T>::node_pair(const pair<Key, T>& pair, node_pair* n, node_pair* p, node_pair* par):
		m(pair), next(n), prev(p), parent(par)
	{
		if (PRINT)
			std::cout << "Node pair ctor : " << pair.first << ", " << pair.second << "\n";
	}

template<class Key, class T>
	ft::node_pair<Key, T>::~node_pair()
	{
		if (PRINT)
			std::cout << "Node destructor\n";
	}

template<class Key, class T>
	ft::node_pair<Key, T>&	ft::node_pair<Key, T>::operator=(const ft::node_pair<Key, T>& el)
	{
		if (PRINT)
			std::cout << "Node operator =\n";
		this->m = el.getMember();
		this->next = el.next;
		this->prev = el.prev;
		this->parent = el.parent;
		return *this;
	}

template<class Key, class T>
	ft::pair<Key, T>&	ft::node_pair<Key, T>::getMember()
	{
		// if (PRINT)
		// 	std::cout << "Node getMember() : " << this->m.first << ", " << this->m.second << "\n";
		return this->m;
	}

	template<class Key, class T>
	const ft::pair<Key, T>&	ft::node_pair<Key, T>::getMember() const
	{
		if (PRINT)
			std::cout << "Node const getMember()" << this->m.first << ", " << this->m.second << "\n";
		return this->m;
	}

template<class Key, class T>
	ft::node_pair<Key, T>*	ft::node_pair<Key, T>::getNext(const node_pair<Key, T>* source) const
	{
		node_pair<Key, T>*	tmp;

		if (!this->next || source == this->next)	//end of branch, looking recursively for next elem
			return this->parent->getNext(this);
		else if (source == this->prev && this->prev)// prev branch ended, return this
			return source->parent;
		else //only case left : return lowest node from next branch
		{
			tmp = this->next;
			while(tmp->prev)
				tmp = tmp->prev;
			return tmp;
		}
	}

template<class Key, class T>
	ft::node_pair<Key, T>*	ft::node_pair<Key, T>::getPrev(const node_pair<Key, T>* source) const
	{
		node_pair<Key, T>*	tmp;

		if (source && source == this->next)
			return source->parent;
		if (source && source == this->prev)
			return this->parent->getPrev(this);
		else
		{
			if (!this->prev)
				return this->parent->getPrev(this);
			tmp = this->prev;
			while(tmp->next)
				tmp = tmp->next;
			return tmp;
		}
	}

#endif
