/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:03:47 by hbaudet           #+#    #+#             */
/*   Updated: 2020/12/10 15:05:35 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Node.hpp"
#include "NodeIterator.hpp"
#include "../ReverseIterator.hpp"
#include "../enable_if.hpp"
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
	static std::ostream& cout = std::cout;

	typedef std::string										string;

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
			typedef NodeIterator< node<value_type>, T >			iterator;
			typedef const_NodeIterator< node<value_type>, T >	const_iterator;
			typedef ReverseIterator< iterator>					reverse_iterator;
			typedef ReverseIterator< const_iterator>			const_reverse_iterator;
			typedef std::ptrdiff_t								difference_type;
			typedef std::size_t									size_type;
			typedef node<value_type>							node_type;

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
				if (PRINT)
				{
					std::cout << "Head : " << &this->_head;
					std::cout << " | Tail : " << &this->_tail << "\n";
				}
				this->assign(n, val);
			}

			template < class InputIter>
				list(InputIter first,
					typename enable_if<InputIter::input_iter, InputIter>::type last): _n(0)
				{
					if (PRINT)
						std::cout << "Range Constructor called\n";
					this->_head.next = &this->_tail;
					this->_tail.prev = &this->_head;
					this->assign(first, last);
				}

			list(const list& lst)
			{
				if (PRINT)
					std::cout << "Copy Constructor called";
				*this = lst;
			}

			~list()
			{
				this->clear();
			}

			list&	operator=(const list& obj)
			{
				if (PRINT)
					std::cout << "Assignation operator called";
				if (*this == obj)
					return *this;
				this->assign(obj.begin(), obj.endl());
				return *this;
			}

			//	Iterators	//
			iterator		begin()
			{
				return this->_head.next;
			}
			const_iterator	begin() const
			{
				return this->_head.next;
			}
			iterator		end()
			{
				return &this->_tail;
			}

			const_iterator	end() const
			{
				return &this->_tail;
			}
			//			iterator		rbegin();
			//			const_iterator	rbegin() const;
			//			iterator		rend();
			//			const_iterator	rend() const;

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
				return std::numeric_limits<size_type>::max() / (sizeof(node_type));
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
					while (first != last)
					{
						position = insert(position, *last);
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
				bool	check = (first != last);
				while (check)
				{
					first = erase(first);
					check = (first != last);
				}
					
				return first;
			}

			void		swap(const list& lst)
			{
				iterator	beg;
				iterator	end;

				beg = lst.begin();
				end = iterator(lst._tail.prev);

				if (this->size())
				{
					lst._head.next = this->_head.next;
					lst.begin().getPointer()->prev = lst._head;
					lst._tail.prev = this->_tail.prev;
					lst._tail.prev->next = lst._tail;
				}
				else
					lst.reset();
				if (lst.size())
				{
					this->_head.next = beg.getPointer();
					beg.getPointer()->prev = this->_head;
					this->_tail.prev = end.getPointer();
					this->_tail.prev->next = this->_tail;
				}
				else
					this->reset();
				this->resetSize();
				lst.resetSize();
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
				iterator	tmp(position.getPointer()->prev);

				tmp->next = x.begin().getPointer();
				tmp->next->prev = tmp.getPointer();
				position.getPointer()->prev = x._tail.prev;
				position.getPointer()->prev->next = position.getPointer();
				x.reset();
				x.resetSize();
				this->resetSize();
			}

			void	splice(iterator position, list& x, iterator i)
			{
				if (x == *this && i == position)
					return ;

				i.getPointer()->prev->next = i.getPointer()->next;
				i.getPointer()->next->prev = i.getPointer()->prev;
				x.resetSize();

				i.getPointer()->prev = position.getPointer()->prev;
				i.getPointer()->prev->next = i.getPointer();
				i.getPointer()->next = position.getPointer();
				position.getPointer()->prev = i.getPointer();
				this->resetSize();
			}

			void	splice(iterator position, list& x, iterator first, iterator last)
			{
				while(first != last)
					splice(position, x, first++);
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
				iterator	tmp;

				if (x == *this)
					return ;
				
				tmp = this->begin();
				while(x.size())
				{
					if (*x.begin() < tmp)
						this->splice(tmp, x, x.begin());
					else
						tmp++;
				}
			}

			template <class Compare>
				void	merge(list& x, Compare comp)
				{
					iterator	tmp;

					if (x == *this)
						return ;

					tmp = this->begin();
					while(x.size())
					{
						if (comp(x.begin(), tmp))
							this->splice(tmp, x, x.begin());
						else
							tmp++;
					}
				}

			void		sort()
			{
				iterator	it = this->begin();
				iterator	it2 = it;

				++it2;
				while (it2 != this->end())
				{
					if (*it >= *it2)
					{
						splice(it, *this, it2);
						it = this->begin();
						it2 = this->bein();
						it2++;
					}
					else
					{
						it++;
						it2++;
					}
				}
			}

			template <class Compare>
				void	sort(Compare comp)
				{
					iterator	it = this->begin();
					iterator	it2 = it;

					++it2;
					while (it2 != this->end())
					{
						if (comp(*it, *it2))
						{
							splice(it, *this, it2);
							it = this->begin();
							it2 = this->bein();
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
				size_t		i;

				i = 0;
				while (i < (this->size() / 2))
				{
					this->splice(this->begin(), *this, --(this->end()));
					this->splice(this->end(), *this, this->begin());
					i++;
				}
			}


			void		reset()
			{
				this->_head.next = this->_tail;
				this->_tail.prev = this->_head;
			}
			
			void		resetSize()
			{
				iterator beg(this->begin());
				this->_n = 0;

				while (beg != this->end())
					this->_n++;
			}
			
		private:
			size_type		_n;
	};
}
