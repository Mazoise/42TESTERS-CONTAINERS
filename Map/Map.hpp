/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:03:48 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/04 17:05:01 by hbaudet          ###   ########.fr       */
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
			template <class Key, class T, class Compare>
				class map<Key, T, Compare>::value_comp
				{
					friend class map;
					
					protected:
						Compare comp;
						value_compare (Compare c) : comp(c) {}

					public:
						typedef bool result_type;
						typedef value_type first_argument_type;
						typedef value_type second_argument_type;
						bool operator() (const value_type& x, const value_type& y) const
						{
							return comp(x.first, y.first);
						}
				};

			typedef Key									key_type;
			typedef T									mapped_type;
			typedef pair<key_type, mapped_type>			value_type;
			typedef node_pair<key_type, mapped_type>	node_type;
			typedef Compare								key_compare;
			typedef map::value_comp<Key, T, Compare>	value_compare;
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

			explicit map(const key_compare& comp = key_compare()): _size(0)
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
					InputIter>::type last, const key_compare& comp = key_compare()): _size(0)
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
			
			map (const map& x): _size(0)
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
				iterator	tmp(&this->_root);

				return tmp;
			}

			const_iterator			begin() const
			{
				iterator	tmp(&this->_root);

				return tmp;
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
				reverse_iterator ret(this->_root);

				return ret;
			}

			const_reverse_iterator	rend() const
			{
				reverse_iterator ret(this->_root);

				return ret;
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
				iterator beg = this->begin();
				iterator end = this->end();

				while (beg != end)
				{
					if (beg->first == k)
						return beg->second;
					beg++
				}

				pair<iterator, bool>	ret(this->insert(value_type(k)));

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
			{}

			template <class InputIterator>
				void				insert(InputIterator first,
					typename enable_if<InputIter::input_iter, InputIter>::type last)
				{}

			node_type&	getMember()
			{
				return this->root;
			}

			const node_type&	getMember() const
			{
				return this->root;
			}

			private:
				node_type		_root;
				node_type		_end;
				size_type		_size;
	};
}
