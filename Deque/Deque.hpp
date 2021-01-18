/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deque.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:03:47 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/18 15:56:34 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Node.hpp"
#include "NodeIterator.hpp"
#include "../ReverseIterator.hpp"
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
	class deque
	{
		public:
			//		TYPEDEFS		//

			typedef T											value_type;
			typedef value_type&									reference;
			typedef const value_type&							const_reference;
			typedef value_type*									pointer;
			typedef const value_type*							const_pointer;
			typedef NodeIterator<T>								iterator;
			typedef const_NodeIterator<T>						const_iterator;
			typedef ReverseIterator< iterator>					reverse_iterator;
			typedef ReverseIterator< const_iterator>			const_reverse_iterator;
			typedef std::ptrdiff_t								difference_type;
			typedef std::size_t									size_type;

			//	MEMBER FUNCTIONS	//

			explicit deque(): _n(0)
			{
				if (PRINT)
					std::cout << "Default Constructor called\n";
				this->_head.next = &this->_tail;
				this->_tail.prev = &this->_head;
			}
			explicit deque(size_type n, const value_type& val = value_type()): _n(0)
			{
				if (PRINT)
					std::cout << "Fill Constructor called\n";
				
				this->_head.next = &this->_tail;
				this->_tail.prev = &this->_head;
				this->assign(n, val);
			}

			template < class InputIter>
				deque(InputIter first,
					typename enable_if<InputIter::input_iter,
						InputIter>::type last): _n(0)
				{
					if (PRINT)
						std::cout << "Range Constructor called\n";
					this->_head.next = &this->_tail;
					this->_tail.prev = &this->_head;
					this->assign(first, last);
				}

			deque(T* first, T* last): _n(0)
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

			deque(const deque& lst): _n(0)
			{
				if (PRINT)
					std::cout << "Copy Constructor called\n";
				this->_head.next = &this->_tail;
				this->_tail.prev = &this->_head;
				*this = lst;
			}

			~deque()
			{
				this->clear();
			}

			deque&	operator=(const deque& obj)
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
				reverse_iterator ret(this->_head);

				return ret;
			}

			const_reverse_iterator	rend() const
			{
				reverse_iterator ret(this->_head);

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

			reference		operator[](size_type n)
			{
				iterator	it(this->begin());

				while (n-- != 0)
					it++;
				return *it;
			}

			const_reference	operator[](size_type n) const
			{
				iterator	it(this->begin());

				while (n-- != 0)
					it++;
				return *it;
			}

			reference		at(size_type n)
			{
				if (n >= this->size())
					throw std::out_of_range("vector::_M_range_check: __n (which is "
						+ to_string(n) + ") >= this->size() (which is "
						+ to_string(this->size()) + ")");
				
				return ((*this)[n]);
			}

			const_reference	at(size_type n) const
			{
				if (n >= this->size())
					throw std::out_of_range("vector::_M_range_check: __n (which is "
						+ to_string(n) + ") >= this->size() (which is "
						+ to_string(this->size()) + ")");
			
				return ((*this)[n]);
			}

			//	MODIFIERS	//
			template <class InputIter>
  				void	assign(InputIter first,
					typename enable_if<InputIter::input_iter, InputIter>::type last)
				{
					this->clear();
					this->insert(this->begin(), first, last);
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

			void		swap(deque& lst)
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


			void		reset()
			{
				this->_head.next = &this->_tail;
				this->_tail.prev = &this->_head;
			}
			
			void		resetSize()
			{
				iterator beg(this->begin());
				this->_n = 0;

				while (beg != this->end())
					this->_n++;
			}
			
		private:
			typedef node<value_type>	node_type;

			size_type					_n;
			node_type					_head;
			node_type					_tail;
	};

	template<class T >
		void	swap(deque<T>& x, deque<T>& y)
		{
			x.swap(y);
		}

	template <class T>
		bool operator==(const deque<T>& left, const deque<T>& right)
		{
			typename deque<T>::iterator it = right.begin();

			if (left.size() != right.size())
				return false;
			for (typename deque<T>::iterator i = left.begin(); i != left.end(); i++)
			{
				if (*i != *it)
					return false;
				it++;
			}
			return true;
		}
	
	template <class T>
		bool operator==(deque<T>& left, deque<T>& right)
		{
			typename deque<T>::iterator	it = right.begin();

			if (left.size() != right.size())
				return false;

			for (typename deque<T>::iterator i = left.begin(); i != left.end(); i++)
			{
				if (*i != *it)
					return false;
				it++;
			}
			return true;
		}
	
	template <class T>
		bool operator<(deque<T>& left, deque<T>& right)
		{
			typename deque<T>::iterator	it = right.begin();
			typename deque<T>::iterator	i = left.begin();

			while (it != right.end() && i != left.end() && *it == *i)
			if (it == right.end() && i != left.end())
				return false;
			if (i == left.end() && it != right.end())
				return true;
			return (*i < *it);
		}

	template <class T>
		bool operator!=(deque<T>& left, deque<T>& right)
		{
			return (!(left == right));
		}

	template <class T>
		bool operator>(deque<T>& left, deque<T>& right)
		{
			return (right < left);
		}

	template <class T>
		bool operator<=(deque<T>& left, deque<T>& right)
		{
			return (!(right < left));
		}

	template <class T>
		bool operator>=(deque<T>& left, deque<T>& right)
		{
			return (!(left < right));
		}
}
