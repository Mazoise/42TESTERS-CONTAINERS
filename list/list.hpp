/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:03:47 by hbaudet           #+#    #+#             */
/*   Updated: 2021/02/02 13:12:33 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "list_Node.hpp"
#include "list_NodeIterator.hpp"
#include "const_list_NodeIterator.hpp"
#include "../ReverseIterator.hpp"
#include "../hbaudet_utils.hpp"
#include <iostream>
#include <string>
#include <limits>

#ifdef DEBUG
# define PRINT 1
#else
# define PRINT 0
#endif

namespace ft
{
	template <class T>
	class list
	{
		public:
			//		TYPEDEFS		//

			typedef T											value_type;
			typedef value_type&									reference;
			typedef const value_type&							const_reference;
			typedef value_type*									pointer;
			typedef const value_type*							const_pointer;
			typedef list_NodeIterator<T>						iterator;
			typedef const_list_NodeIterator<T>					const_iterator;
			typedef ReverseIterator< iterator>					reverse_iterator;
			typedef const_ReverseIterator<const_iterator>		const_reverse_iterator;
			typedef std::ptrdiff_t								difference_type;
			typedef std::size_t									size_type;
			typedef list_node<value_type>						node_type;

			node_type		_head;
			node_type		_tail;

			//	MEMBER FUNCTIONS	//

			explicit list(): _n(0)
			{
				if (PRINT)
					std::cout << "Default Constructor called\n";
				this->_head.next = &this->_tail;
				this->_tail.prev = &this->_head;
			}
			explicit list(size_type n, const value_type& val = value_type()): _n(0)
			{
				if (PRINT)
					std::cout << "Fill Constructor called\n";
				
				this->_head.next = &this->_tail;
				this->_tail.prev = &this->_head;
				this->assign(n, val);
			}

			template < class InputIter>
				list(InputIter first,
					typename enable_if<InputIter::input_iter,
						InputIter>::type last): _n(0)
				{
					if (PRINT)
						std::cout << "Range Constructor called\n";
					this->_head.next = &this->_tail;
					this->_tail.prev = &this->_head;
					this->assign(first, last);
				}

			list(T* first, T* last): _n(0)
			{
				if (PRINT)
					std::cout << "Pointer range constructor called\n";
				this->_head.next = &this->_tail;
				this->_tail.prev = &this->_head;
				while(first != last)
				{
					push_back(*first);
					++first;
				}
			}

			list(const list& lst): _n(0)
			{
				if (PRINT)
					std::cout << "Copy Constructor called\n";
				this->_head.next = &this->_tail;
				this->_tail.prev = &this->_head;
				*this = lst;
			}

			~list()
			{
				this->clear();
			}

			list&	operator=(const list& obj)
			{
				if (PRINT)
					std::cout << "Assignation operator called\n";
				this->assign(obj.begin(), obj.end());
				return *this;
			}

			//	Iterators	//
			iterator		begin()
			{
				iterator	ret(this->_head.next);

				return ret;
			}
			const_iterator	begin() const
			{
				const_iterator	ret(_head.next);

				return ret;
			}
			iterator		end()
			{
				iterator	ret(&this->_tail);

				return ret;
			}

			const_iterator	end() const
			{
				const_iterator	ret(&_tail);

				return ret;
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
				reverse_iterator ret(this->begin());

				return ret;
			}

			const_reverse_iterator	rend() const
			{
				reverse_iterator ret(this->begin());

				return ret;
			}

			//	Capacity	//
			bool			empty() const
			{
				return (this->_n == 0);
			}

			size_type		size() const
			{
				return this->_n;
			}
			
			size_type	max_size() const
			{
				return std::numeric_limits<size_type>::max() / (2 * sizeof(node_type));
			}

			//	ELEMENT ACCES	//
			reference front()
			{
				return this->_head.next->getMember();
			}

			const_reference front() const
			{
				return this->_head.next->getMember();
			}

			reference back()
			{
				return this->_tail.prev->getMember();
			}

			const_reference back() const
			{
				return this->_tail.prev->getMember();
			}

			//	MODIFIERS	//
			template <class InputIter>
  				void	assign(InputIter first,
					typename enable_if<InputIter::input_iter, InputIter>::type last)
				{
					this->clear();
					this->insert(this->begin(), first, last);
				}
			
			void		assign(value_type *first, value_type *second)
			{
				this->clear();
				while(first != second)
				{
					this->push_back(*first);
					first++;
				}
			}

			void		assign(size_type n, const value_type& val)
			{
				this->clear();
				this->insert(this->begin(), n, val);
			}

			void		push_front(const value_type& val)
			{
				this->insert(this->begin(), val);
			}

			void		pop_front()
			{
				this->erase(this->begin());
			}
			void		push_back(const value_type& val)
			{
				this->insert(this->end(), val);
			}

			void		pop_back()
			{
				this->erase(--(this->end()));
			}

			iterator 	insert(iterator position, const value_type& val)
			{
				node_type*	node = new node_type(val,
					position.getPointer(), position.getPointer()->prev);

				if (node)
				{
					node->prev->next = node;
					node->next->prev = node;

					this->_n++;
					return iterator(node);
				}
				throw std::bad_alloc();
			}

    		void 		insert(iterator position, size_type n, const value_type& val)
			{
				while (n-- > 0)
					position = insert(position, val);
			}

			template <class InputIter>
    			void	insert(iterator position, InputIter first,
					typename enable_if<InputIter::input_iter, InputIter>::type last)
				{
					iterator	tmp(last.getPointer()->prev);
					while (first != last)
					{
						position = insert(position, *tmp);
						tmp--;
						last--;
					}
				}

			iterator	erase(iterator position)
			{
				if (position == this->end())
					return position;
				iterator	ret(position.getPointer()->next);

				position.getPointer()->prev->next = position.getPointer()->next;
				position.getPointer()->next->prev = position.getPointer()->prev;

				delete(position.getPointer());
				this->_n--;

				return ret;
			}

			iterator	erase(iterator first, iterator last)
			{
				while (first != last)
				{
					first = erase(first);
				}
				return first;
			}

			void		swap(list& lst)
			{
				iterator 	beg(lst.begin());
				iterator 	end(lst.end());
				size_type	i(lst.size());

				end--;

				if (this->size())
				{
					lst._head.next = this->_head.next;
					lst._head.next->prev = &lst._head;
					lst._tail.prev = this->_tail.prev;
					lst._tail.prev->next = &lst._tail;
					lst._n = this->size();
				}
				else
				{
					lst._head.next = &lst._tail;
					lst._tail.prev = &lst._head;
					lst._n = 0;
				}
				if (i)
				{
					this->_head.next = beg.getPointer();
					this->_head.next->prev = &this->_head;
					this->_tail.prev = end.getPointer();
					this->_tail.prev->next = &this->_tail;
					this->_n = i;
				}
				else
				{
					this->_head.next = &this->_tail;
					this->_tail.prev = &this->_head;
					this->_n = 0;
				}
			}

			void		resize(size_type n, value_type val = value_type())
			{
				if (n >= this->size())
				{
					while (n != this->size())
						push_back(val);
				}
				else
				{
					while (n != this->size())
						this->pop_back();
				}
			}

			void		clear()
			{
				this->erase(this->begin(), this->end());
			}

			//	OPERATIONS	//
			void	splice(iterator position, list& x)
			{
				splice(position, x, x.begin(), x.end());
			}

			void	splice(iterator position, list& x, iterator i)
			{
				i.getPointer()->prev->next = i.getPointer()->next;
				i.getPointer()->next->prev = i.getPointer()->prev;
				x.resetSize();

				i.getPointer()->prev = position.getPointer()->prev;
				i.getPointer()->prev->next = i.getPointer();
				i.getPointer()->next = position.getPointer();
				position.getPointer()->prev = i.getPointer();
				this->_n++;
			}

			void	splice(iterator position, list& x, iterator first, iterator last)
			{
				iterator	tmp;

				tmp = first;
				tmp++;
				while(first != last)
				{
					splice(position, x, first);
					first = tmp;
					if (tmp != last)
						tmp++;
				}
			}

			void	remove(const value_type& val)
			{
				iterator it = this->begin();

				while (it != this->end())
					if (*it == val)
						it = erase(it);
					else
						it++;
			}

			template <class Predicate>
				void	remove_if(Predicate pred)
				{
					iterator it = this->begin();

					while (it != this->end())
						if (pred(*it))
							it = erase(it);
						else
							it++;
				}

			void		unique()
			{
				iterator	it = this->begin();
				iterator	it2 = it;

				++it2;
				while (it2 != this->end())
				{
					if (*it2 == *it)
						it2 = erase(it2);
					else
					{
						it2++;
						it++;
					}
				}
			}

			template <class BinaryPredicate>
				void	unique(BinaryPredicate binary_pred)
				{
					iterator	it = this->begin();
					iterator	it2 = it;

					++it2;
					while (it2 != this->end())
					{
						if (binary_pred(*it2, *it))
							it2 = erase(it2);
						else
						{
							it2++;
							it++;
						}
					}
				}

			void	merge(list& x)
			{
				this->merge(x, default_comp);
			}

			template <class Compare>
				void	merge(list& x, Compare comp)
				{
					iterator	tmp;

					if (&x == this)
						return ;

					tmp = this->begin();
					while(x.size() && tmp != this->end())
					{
						if (comp(*x.begin(), *tmp))
						{
							this->splice(tmp, x, x.begin());
						}
						else
							tmp++;
					}
					if (x.size())
						splice(this->end(), x, x.begin(), x.end());
				}

			void		sort()
			{
				this->sort(default_comp);
			}

			template <class Compare>
				void	sort(Compare comp)
				{
					if (this->size() < 2)
						return ;
					iterator	it = this->begin();
					iterator	it2 = it;

					++it2;
					while (it2 != this->end())
					{
						if (comp(*it2, *it))
						{
							splice(it, *this, it2);
							it = this->begin();
							it2 = this->begin();
							it2++;
						}
						else
						{
							it++;
							it2++;
						}
					}
				}

			void		reverse()
			{
				iterator	it;
				iterator	it2;

				if (this->_n < 2)
					return ;
				it = this->begin();
				it2 = this->begin();
				it2++;
				this->_tail.prev = it.getPointer();
				it.getPointer()->next = &this->_tail;
				it.getPointer()->prev = it2.getPointer();
				it = it2;
				it2++;
				while (it2 != this->end())
				{
					it.getPointer()->next = it.getPointer()->prev;
					it.getPointer()->prev = it2.getPointer();
					it = it2;
					it2++;
				}
				it.getPointer()->next = it.getPointer()->prev;
				it.getPointer()->prev = &this->_head;
				this->_head.next = it.getPointer();
			}


			void		reset()
			{
				this->_head.next = &this->_tail;
				this->_tail.prev = &this->_head;
				// this->_n = 0;
			}
			
			void		resetSize()
			{
				iterator beg(this->begin());
				this->_n = 0;

				while (beg != this->end())
				{
					beg++;
					this->_n++;
				}
			}
			
		private:
			size_type		_n;

			static bool default_comp(value_type first, value_type second)
			{
				return (first < second);
			}
	};

	template<class T >
		void	swap(list<T>& x, list<T>& y)
		{
			x.swap(y);
		}

	template <class T>
		bool operator==(const list<T>& left, const list<T>& right)
		{
			typename list<T>::iterator it = right.begin();

			if (left.size() != right.size())
				return false;
			for (typename list<T>::iterator i = left.begin(); i != left.end(); i++)
			{
				if (*i != *it)
					return false;
				it++;
			}
			return true;
		}
	
	template <class T>
		bool operator==(list<T>& left, list<T>& right)
		{
			typename list<T>::iterator	it = right.begin();

			if (left.size() != right.size())
				return false;

			for (typename list<T>::iterator i = left.begin(); i != left.end(); i++)
			{
				if (*i != *it)
					return false;
				it++;
			}
			return true;
		}
	
	template <class T>
		bool operator<(list<T>& left, list<T>& right)
		{
			typename list<T>::iterator	it = right.begin();
			typename list<T>::iterator	i = left.begin();

			while (it != right.end() && i != left.end() && *it == *i)
			{
				i++;
				it++;
			}
			if (it == right.end() && i != left.end())
				return false;
			if (i == left.end() && it != right.end())
				return true;
			return (*i < *it);
		}

	template <class T>
		bool operator!=(list<T>& left, list<T>& right)
		{
			return (!(left == right));
		}

	template <class T>
		bool operator>(list<T>& left, list<T>& right)
		{
			return (right < left);
		}

	template <class T>
		bool operator<=(list<T>& left, list<T>& right)
		{
			return (!(right < left));
		}

	template <class T>
		bool operator>=(list<T>& left, list<T>& right)
		{
			return (!(left < right));
		}
}
