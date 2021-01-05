/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:03:48 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/05 15:45:34 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "../utils.hpp"
#include "NodeIterator.hpp"
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
			typedef NodeIterator						iterator;
			typedef const_NodeIterator					const_iterator;
			typedef reverseIterator<iterator>			reverse_iterator;
			typedef reverseIterator<const_iterator>		const_reverse_iterator;
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


			explicit map(const key_compare& comp = key_compare()): _comp(comp), _size(0)
			{
				if (PRINT)
					cout << "Empty map ctor\n";
				
				this->_root.prev = NULL;
				this->_root.parent = NULL;
				this->_root.next = &this->_end;
				this->_end.parent = &this->_root;
				this->_end.prev = NULL;
			}

			template <class InputIterator>
				map(InputIterator first, typename enable_if<InputIter::input_iter,
					InputIter>::type last, const key_compare& comp = key_compare()): _comp(comp), _size(0)
				{
					if (PRINT)
						cout << "Range map ctor\n";

					this->_root.prev = NULL;
					this->_root.parent = NULL;
					this->_root.next = &this->_end;
					this->_end.parent = &this->_root;
					this->_end.prev = NULL;
					this->insert(first, last);
				}
			
			map (const map& x): _comp(comp), _size(0)
			{
				if (PRINT)
					cout << "Copy map ctor\n";
				
				iterator	beg = x.begin();
				iterator	end = x.end();

				this->_root.prev = NULL;
				this->_root.parent = NULL;
				this->_root.next = &this->_end;
				this->_end.parent = &this->_root;
				this->_end.prev = NULL;
				this->insert(beg, end);
			}

			~map()
			{
				if (PRINT)
					cout << "Map dtor\n"
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
				
			}

			const_iterator			begin() const
			{
				
			}

			iterator				end()
			{
				iterator	tmp(&this->_end);

				return tmp;
			}

			const_iterator			end() const
			{
				iterator	tmp(&this->_end);

				return tmp;
			}

			reverse_iterator		rbegin()
			{
				reverse_iterator ret(this->end());

				return ret;
			}

			const_reverse_iterator	rbegin() const
			{
				const_reverse_iterator ret(this->end());

				return ret;
			}

			reverse_iterator		rend()
			{
			
			}

			const_reverse_iterator	rend() const
			{
				
			}

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

				if (found != this->end()))
					return found->second;

				pair<iterator, bool>	ret(this->insert(value_type(pair(k))));

				return ret->first->second;
			}

			pair<iterator,bool>		insert(const value_type& val)
			{
				iterator beg = this->begin();
				iterator end = this->end();

				while (beg != end && key_comp(beg->first, val.first))
				{
					if (beg->first == val.first)
					{
						beg->second = val.second;
						return (pair<iterator, bool>(beg, false));
					}
					beg++
				}
				beg--;

				pair<iterator, bool>	ret(this->insert(beg, val), true);

				return (ret);
			}

			iterator				insert(iterator position, const value_type& val)
			{
				iterator	ret = find(val.first);

				if (ret != this->end())
					return ret;
				if (key_comp(position->first, val.first)
					&& !(key_comp(position.getPointer()->next->first, val.first))
					&& this->find(val.first) == this->end())
				{
					node_type*	tmp = new node_type(val, position.getPointer()->next, NULL, position.getPointer());
					position.getPointer()->next.getPointer()->parent = tmp;
					position.getPointer()->next = tmp;
					this->_size++;
					return (iterator(tmp));
				}
				pair<iterator, bool>	inserted = this->insert(val);
				return inserted->first;
			}

			template <class InputIterator>
				void				insert(InputIterator first,
					typename enable_if<InputIter::input_iter, InputIter>::type last)
				{
					while (first != last)
					{
						this->insert(*first);
						first++;
					}
				}

			void					erase(iterator position)
			{
				position.getPointer()->parent.getPointer()->next = position.getPointer()->prev;
				position.getPointer()->next.getPointer()->parent = position.getointer()->parent;

				pointer		tmp = position.getPointer();

				while (tmp->next)
					tmp = tmp->next;
				tmp->next = position.getPointer();
				tmp->next->parent = tmp;

				delete *position;
				this->_size--;
			}

			size_type				erase(const key_type& k)
			{
				iterator	tmp = this->find(k);

				if (tmp == ths->end())
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
				iterator beg = this->begin();
				iterator end = this->end();

				while (beg != end && key_comp(beg->first, val.first))
				{
					if (beg->first == k)
						return beg;
					beg++
				}
				return this->end();
			}

			const_iterator			find(const key_type& k) const
			{
				const_iterator beg = this->begin();
				const_iterator end = this->end();

				while (beg != end && key_comp(beg->first, val.first))
				{
					if (beg->first == k)
						return beg;
					beg++
				}
				return this->end();
			}

			void					swap (map& x)
			{
				node_type	root;
				node_type*	end;
				size_type	size;

				root = this->_root;
				end = this->_end.prev;
				size = this->size();

				this->_end.prev = x.end().getPointer()->prev;
				this->_end.prev->next = &this->_end;
				this->_root = x.getRoot();
				if (this->_root->next)
					this->_root->next->parent = &this->_root;
				if (this->_root->prev)
					this->_root->prev->parent = &this->_root;
				this->_size = x.size();

				x.setRoot(root);
				if (x.getRoot().next)
					x.getRoot().next->prev = &x.getRoot();
				if (x.getRoot().prev)
					x.getRoot().prev->parent = &x.getRoot();
				end->next = x.end().getPointer();
				end->next->prev = end;
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
				node_type		_root;
				node_type		_end;
				key_compare		_comp;
				size_type		_size;
	};
}
