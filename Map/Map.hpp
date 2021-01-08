/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:03:48 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/08 16:12:26 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <limits>
#include "../utils.hpp"
#include "MapNodeIterator.hpp"
#include "Node_pair.hpp"

#ifdef DEBUG
# define PRINT 1
#else
# define PRINT 0
#endif

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key> >
	class map
	{
		public:
			typedef Key									key_type;
			typedef T									mapped_type;
			typedef pair<key_type, mapped_type>			value_type;
			typedef node_pair<key_type, mapped_type>	node_type;
			typedef Compare								key_compare;
			typedef value_type&							reference;
			typedef const value_type&					const_reference;
			typedef value_type*							pointer;
			typedef const value_type*					const_pointer;
			typedef MapNodeIterator<Key, T>				iterator;
			// typedef const_NodeIterator<Key, T>			const_iterator;
			typedef ReverseIterator<iterator>			reverse_iterator;
			// typedef ReverseIterator<const_iterator>		const_reverse_iterator;
			typedef std::ptrdiff_t						difference_type;
			typedef size_t								size_type;

			class value_compare
				{
					friend class map;
					
					protected:
						Compare comp;
						value_compare(Compare c): comp(c) {}

					public:
						bool	operator()(const value_type& x, const value_type& y) const
						{
							return comp(x.first, y.first);
						}
				};

			explicit map(const key_compare& comp = key_compare()): _comp(comp)
			{
				if (PRINT)
					cout << "Empty map ctor\n";
				
				this->reset_map();
			}

			template <class InputIter>
				map(InputIter first, typename enable_if<InputIter::input_iter,
					InputIter>::type last, const key_compare& comp = key_compare()): _comp(comp)
				{
					if (PRINT)
						cout << "Range map ctor\n";

					this->reset_map();
					this->insert(first, last);
				}
			
			map (const map& x): _comp(x.key_comp())
			{
				if (PRINT)
					cout << "Copy map ctor\n";
				
				this->reset_map();
				this->insert(x.begin(), x.end());
			}

			~map()
			{
				if (PRINT)
					cout << "Map dtor\n";
				this->clear();
				cout << "end of map dtor\n";
			}

			map&	operator=(const map& x)
			{
				this->clear();
				if (PRINT)
					cout << "map::operator=\n";
				
				iterator	beg = x.begin();
				iterator	end = x.end();

				this->insert(beg, end);
			}

			iterator				begin()
			{
				return iterator(this->_begin.parent);
			}

			// const_iterator			begin() const
			// {
			// 	return iterator(this->_begin.parent);
			// }

			iterator				end()
			{
				iterator	tmp(&this->_end);

				return tmp;
			}

			// const_iterator			end() const
			// {
			// 	iterator	tmp(&this->_end);

			// 	return tmp;
			// }

			reverse_iterator		rbegin()
			{
				reverse_iterator ret(this->end());

				return ret;
			}

			// const_reverse_iterator	rbegin() const
			// {
			// 	const_reverse_iterator ret(this->end());

			// 	return ret;
			// }

			reverse_iterator		rend()
			{
				reverse_iterator ret(this->begin());

				return ret;
			}

			// const_reverse_iterator	rend() const
			// {
			// 	const_reverse_iterator ret(this->begin());

			// 	return ret;
			// }

			bool					empty() const
			{
				return (!this->_size);
			}

			size_type				size() const
			{
				return this->_size;
			}

			size_type				max_size() const
			{
				return std::numeric_limits<size_type>::max() / (2 * sizeof(node_type));
			}

			mapped_type&			operator[](const key_type& k)
			{
				iterator found = this->find(k);

				if (found != this->end())
					return found->second;

				pair<iterator, bool>	ret(this->insert(value_type(k)));

				return ret->first->second;
			}

			pair<iterator, bool>		insert(const value_type& val)
			{
				if (PRINT)
					ft::cout << "insert single : " << val.first << ", " << val.second << "\n";
				if (!this->size())
				{
					insert_first_elem(val);
					return pair<iterator, bool>(this->begin(), true);
				}
				node_type*	tmp = this->_root;
				node_type*	beg = &this->_begin;
				node_type*	end = &this->_end;

				while (tmp && tmp != beg && tmp != end)
				{
					if (this->key_comp()(tmp->getMember().first, val.first))
					{
						if (tmp->next)
							tmp = tmp->next;
						else
							return pair<iterator, bool>(this->insert(tmp, val), true);
					}
					else if (this->key_comp()(val.first, tmp->getMember().first))
					{
						if (tmp->prev)
							tmp = tmp->prev;
						else
							return pair<iterator, bool>(this->insert(tmp->parent, val), true);
					}
					else
					{
						tmp->getMember().second = val.second;
						return pair<iterator, bool>(tmp, false);
					}
				}
				if (tmp == beg)
				{
					return pair<iterator, bool>(this->insert(iterator(&this->_begin), val), true);
				}
				else
				{
					return pair<iterator, bool>(this->insert(iterator(this->_end.parent), val), true);
				}
			}

			iterator				insert(iterator position, const value_type& val)
			{
				if (PRINT)
					cout << "insert position : " << val.first << ", " << val.second;
				if (!this->size())
				{
					insert_first_elem(val);
					return this->begin();
				}
				iterator	ret = find(val.first);

				if (ret != this->end()) //case where key already exists
				{
					ret->second = val.second;
					return ret;
				}
				// Checking if position is relevant
				if (((position == iterator(&this->_begin)) && (this->key_comp()(val.first, this->begin()->first)))
					|| ((position == iterator(this->_end.parent)) && (this->key_comp()(position->first, val.first)))
					|| (this->key_comp()(position->first, val.first)
							&& (this->key_comp()(val.first, position.getPointer()->next->getMember().first))) )
				{
					node_type*	tmp = new node_type(val);
					if (position == iterator(&this->_begin)) //Inserting BEFORE beginning (used by insert(val) when all keys > val.first)
					{
						tmp->parent = this->_begin.parent;
						tmp->prev =&this->_begin;
						tmp->parent->prev = tmp;
						this->_begin.parent = tmp;
					}
					else //Inserting in the middle
					{
						tmp->parent = position.getPointer();
						tmp->next = position.getPointer()->next;
						tmp->parent->next = tmp;
						tmp->next->parent = tmp;
					}
					this->_size++;
					return (iterator(tmp));
				}
				pair<iterator, bool>	inserted = this->insert(val); //position is wrong, need to find the right one
				return inserted.first;
			}

			template <class InputIter>
				void				insert(InputIter first,
					typename enable_if<InputIter::input_iter, InputIter>::type last)
				{
					if (PRINT)
						cout << "insert range\n";
					while (first != last)
					{
						this->insert(*first);
						first++;
					}
				}

			void					erase(iterator position)
			{
				cout << "deleting : " << position->first << '\n';
				if (this->_size == 1)
				{
					delete this->_root;
					this->reset_map();
					return ;
				}
				
				node_type*	ptr(position.getPointer());
				node_type*	next(ptr->prev);
				node_type*	prev(ptr->prev);
				node_type*	parent(ptr->parent);

				if (prev != &this->_begin)
				{
					if (parent)
					{
						if (parent->next == ptr)
							parent->next = prev;
						else
							parent->prev = next;
					}
					else
						this->_root = prev;
					while(next->next)
						next = next->next;
					next->next = ptr->next;
				}
				else
				{
					if (parent)
					{
						if (ptr->next)
						{
							parent->prev = ptr->next;
							next = ptr->next;
							while(next->prev)
								next = next->prev;
							next->prev = &this->_begin;
						}
						else
						{
							parent->prev = &this->_begin;
						}
					}
					else
					{
						next = ptr->next;
						this->_root = next;
						next->parent = NULL;
						while (next->prev)
							next = next->prev;
						next->prev = &this->_begin;
					}
				}
				this->_size--;
				delete position.getPointer();
				return ;
			}

			size_type				erase(const key_type& k)
			{
				iterator	tmp = this->find(k);

				if (tmp == this->end())
					return 0;
				erase(tmp);
				return 1;
			}

			void					erase(iterator first, iterator last)
			{
				iterator tmp(first);

				cout << "erase from :" << first->first <<" to : " << last.getPointer()->parent->getMember().first << '\n';

				while (first != last)
				{
					tmp++;
					erase(first);
					first = tmp;
				}
				cout << "end of erase range\n";
			}

			iterator				find(const key_type& k)
			{
				node_type*		ptr(this->_root);

				while(ptr && ptr != &this->_begin && ptr != &this->_end)
				{
					if (this->_comp(k, ptr->getMember().first))
						ptr = ptr->prev;
					else if (this->_comp(ptr->getMember().first, k))
						ptr = ptr->next;
					else
						return iterator(ptr);
				}
				return this->end();
			}

			// const_iterator			find(const key_type& k) const
			// {
			// 	node_type*		ptr(this->_root);

			// 	while(ptr != &this->_begin && ptr != &this->_end)
			// 	{
			// 		if (this->_comp(k, ptr->first))
			// 			ptr = ptr->prev;
			// 		else if (this->_comp(ptr->first, k))
			// 			ptr = ptr->next;
			// 		else
			// 			return iterator(ptr);
			// 	}
			// 	return this->end();
			// }

			void					swap (map& x)
			{
				node_type*	root;
				node_type*	end;
				node_type*	begin;
				node_type*	xbeg;
				size_type	size;

				root = this->_root;
				end = this->_end.parent;
				begin = this->_begin.parent;
				xbeg = x.begin().getPointer()->prev;
				size = this->size();

				this->_end.parent = x.end().getPointer()->parent;
				this->_end.parent->next = &this->_end;
				this->_begin.parent = x.begin().getPointer();
				this->_begin.parent->prev = &this->_begin;
				this->_root = x.getRoot();
				this->_size = x.size();

				x.setRoot(root);
				x.end().getPointer()->parent = end;
				x.end().getPointer()->parent->next = x.end().getPointer();
				begin->prev = xbeg;
				xbeg->parent = begin;
				x.setSize(size);
			}

			void					clear()
			{
				this->erase(this->begin(), this->end());
				cout << "end of clear\n";
			}

			void					setSize(size_type size)
			{
				this->_size = size;
			}

			key_compare				key_comp() const
			{
				return	this->_comp;
			}

			value_compare			value_comp() const
			{
				return value_comp(this->_comp);
			}
			
			size_type				count(const key_type& k) const
			{
				if (this->find(k) != this->end())
					return 1;
				return 0;
			}

			iterator				lower_bound(const key_type& k)
			{
				return iterator(this->lower_node(this->_root, k));
			}

			// const_iterator			lower_bound(const key_type& k) const
			// {
			// 	return const_iterator(this->lower_node(this->_root, k));
			// }

			node_type&				getRoot()
			{
				return this->_root;
			}

			const node_type&		getRoot() const
			{
				return this->_root;
			}

			void					setRoot(const node_type& r)
			{
				this->_root = r;
			}

			node_type&				getMember()
			{
				return this->root;
			}

			const node_type&		getMember() const
			{
				return this->root;
			}

		// private:
			node_type*		_root;
			node_type		_end;
			node_type		_begin;
			key_compare		_comp;
			size_type		_size;


			void					reset_map()
			{
				cout << "test\n";
				this->_size = 0;
				cout << "test1\n";
				this->_root = &this->_end;
				cout << "test2\n";
				this->_begin.parent = &this->_end;
				cout << "test3\n";
				this->_begin.next = NULL;
				cout << "test4\n";
				this->_begin.prev = NULL;
				cout << "test5\n";
				this->_end.parent = NULL;
				cout << "test6\n";
				this->_end.next = NULL;
				cout << "test7\n";
				this->_end.prev = &this->_begin;
				cout << "test8\n";
			}

			void					insert_first_elem(const value_type& val)
			{
				if (PRINT)
					cout << "insert_first_elem : " << val.first << ", " << val.second << "\n";
				this->_root = new node_type(val, &this->_end, &this->_begin);

				this->_end.parent = this->_root;
				this->_begin.parent = this->_root;
				this->_end.prev = NULL;
				this->_size = 1;
			}

			node_type*				lower_node(node_type* node, const key_type& k)
			{
				node_type*	ret;

				if (PRINT)
					cout << "node : (" << node->first << ", " << node->second << ") // " << k << "\n";

				if (!node)
					return NULL;
				if (this->_comp(node->first, k))
				{
					ret = this->lower_node(node->next, k);
					if (!ret)
						return &this->_end;
					return ret;
				}
				else if (this->_comp(k, node->first))
				{
					ret = this->lower_node(node->prev, k);
					if (!ret)
						return &this->_begin;
					return ret;
				}
				else
					return node->next;
			}
	};
}
