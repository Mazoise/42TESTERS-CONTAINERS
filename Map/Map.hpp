/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:03:48 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/06 13:33:55 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
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
					cout << "insert single\n";
				if (!this->size())
				{
					insert_first_elem(val);
					return pair<iterator, bool>(this->begin(), true);
				}
				iterator beg = this->begin();
				iterator end = this->end();

				while (beg != end && this->_comp(beg->first, val.first))
				{
					if (beg->first == val.first)
					{
						beg->second = val.second;
						return (pair<iterator, bool>(beg, false));
					}
					beg++;
				}
				beg--;

				pair<iterator, bool>	ret(this->insert(beg, val), true);

				return (ret);
			}

			iterator				insert(iterator position, const value_type& val)
			{
				if (PRINT)
					cout << "insert position\n";
				if (!this->size())
				{
					insert_first_elem(val);
					return this->begin();
				}
				iterator	ret = find(val.first);

				if (ret != this->end())
					return ret;
				if (key_comp()(position->first, val.first)
					&& !(key_comp()(position.getPointer()->next->getMember().first, val.first))
					&& this->find(val.first) == this->end())
				{
					node_type*	tmp = new node_type(val, position.getPointer()->next, NULL, position.getPointer());
					position.getPointer()->next->parent = tmp;
					position.getPointer()->next = tmp;
					this->_size++;
					return (iterator(tmp));
				}
				pair<iterator, bool>	inserted = this->insert(val);
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
				if (this->_size == 1)
				{
					delete this->_root->next;
					this->reset_map();
					return ;
				}
				
				node_type*	ptr(position.getPointer());
				node_type*	next(ptr->prev);
				node_type*	prev(ptr);
				this->_size--;

				if (ptr->next == &this->_end)
					ptr->parent->next = &this->_end;
				else if (ptr->prev == &this->_begin)
					ptr->parent->prev = &this->_begin;
				else
				{
					ptr->parent->next = prev;
					prev->parent = ptr->parent;
					while(next->next)
						next = next->next;
					next->next = ptr->next;
					next->next->parent = next;
				}
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

				while (first != last)
				{
					tmp++;
					erase(first);
					first = tmp;
				}
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

		private:
			node_type*		_root;
			node_type		_end;
			node_type		_begin;
			key_compare		_comp;
			size_type		_size;


			void					reset_map()
			{
				this->_size = 0;
				this->_root = &this->_end;
				this->_begin.parent = &this->_end;
				this->_begin.next = NULL;
				this->_begin.prev = NULL;
				this->_end.parent = NULL;
				this->_end.next = NULL;
				this->_end.prev = &this->_begin;
			}

			void					insert_first_elem(const value_type& val)
			{
				if (PRINT)
					cout << "insert_first_elen\n";
				this->_root = new node_type(val, &this->_end, &this->_begin);

				this->_end.parent = this->_root;
				this->_begin.parent = this->_root;
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
