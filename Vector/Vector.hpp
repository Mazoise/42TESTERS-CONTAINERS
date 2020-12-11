/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:03:48 by hbaudet           #+#    #+#             */
/*   Updated: 2020/12/11 15:16:13 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../utils.hpp"
#include "VectorIterator.hpp"
#include "const_VectorIterator.hpp"
#include <limits>
#include <iostream>

#ifdef DEBUG
# define PRINT 1
#else
# define PRINT 0
#endif


namespace ft 
{
	template < class T>
		class vector
		{
			public:
				// Typedefs
				typedef	T											value_type;
				typedef value_type&									reference;
				typedef const value_type&							const_reference;
				typedef value_type*									pointer;
				typedef const value_type*							const_pointer;
				typedef VectorIterator<value_type>					iterator;
				typedef const_VectorIterator<value_type>			const_iterator;
				typedef ReverseIterator<iterator>					reverse_iterator;
				typedef ReverseIterator<const_iterator>				const_reverse_iterator;
				typedef std::ptrdiff_t								difference_type;
				typedef size_t										size_type;

				// MEMBER
				explicit vector(): _size(0), _capacity(0)
				{
					if (PRINT)
						std::cout << "Default constructor called\n";

					this->_tab = new value_type[0];
				}

				explicit vector(size_type n,const value_type& val = value_type()):
					_size(n), _capacity(n)
				{
					if (PRINT)
						std::cout << "Fill constructor called\n";

					this->_tab = new T[n];
					for (size_t i = 0; i < n; i++)
						this->_tab[i] = val;
				}
				
				template < class InputIter>
					vector(InputIter first,
					typename enable_if<InputIter::input_iter, InputIter>::type last):
						_tab(NULL), _size(0), _capacity(0)
				{
					if (PRINT)
						std::cout << "Range constructor called\n";

					this->assign(first, last);
				}

				vector(const vector& obj):
					_tab(NULL), _size(0), _capacity(0)
				{
					if (PRINT)
						std::cout << "Copy Constructor called\n";
					*this = obj;
				}
				
				~vector()
				{
					if (PRINT)
						std::cout << "Destructor called\n";
					this->clear();
					delete[] this->_tab;
				}

				vector&		operator=(const vector& obj)
				{
					if (PRINT)
						std::cout << "Assignation operator called\n";
					/*
					if (*this == obj)
						return *this; // Undefined case
					*/ 

					this->assign(obj.begin(), obj.end());

					return *this;
				}

				// ITERATORS

				iterator begin()
				{
					iterator ret(this->_tab);

					return ret;
				}

				const_iterator begin() const
				{
					const_iterator	ret(this->_tab);

					return ret;
				}

				iterator end()
				{
					iterator ret(this->_tab + this->_size);

					return ret;
				}

				const_iterator end() const
				{
					const_iterator	ret(this->_tab + this->_size);

					return ret;
				}

				reverse_iterator	rbegin()
				{
					reverse_iterator	ret(this->end() - 1);

					return ret;
				}

				const_reverse_iterator	rbegin() const
				{
					return const_reverse_iterator(this->end() - 1);
				}

				reverse_iterator	rend()
				{
					reverse_iterator	ret(this->begin() - 1);

					return ret;
				}

				const_reverse_iterator	rend() const
				{
					return const_reverse_iterator(this->end() - 1);
				}

				// Capacity
				size_type	size() const
				{
					return this->_size;
				}

				size_type	max_size() const
				{
					return std::numeric_limits<size_type>::max() / (2 * (sizeof(value_type)));
				}

				void		resize(size_type n, value_type val = value_type())
				{
					if (n < this->_size)
						erase(this->begin() + n, this->end());
					else
					{
						this->reserve(n);
						for (size_type i = this->size(); i < n; i++)
							this->_tab[i] = val;
						this->_size = n;
					}
				}

				size_type	capacity() const
				{
					return this->_capacity;
				}

				bool	empty() const
				{
					return !this->_size;
				}

				void	reserve(size_type n)
				{
					if (n > this->_capacity)
					{
						size_type	size;

						size = this->size();
						value_type	*tmp = new value_type[n];
						for (size_type i = 0; i < this->_size; i++)
							tmp[i] = this->_tab[i];
						this->clear();
						delete[] this->_tab;
						this->_tab = tmp;
						this->_size = size;
						this->_capacity = n;
					}
				}


				// Operators
				reference	operator[](const size_type i)
				{
					return this->_tab[i];
				}

				const_reference	operator[](const size_type i) const
				{
					return this->_tab[i];
				}

				reference	at(const size_type i)
				{
					if (i >= this->_size)
						throw std::out_of_range("vector::_M_range_check: __n (which is "
						+ to_string(i) + ") >= this->size() (which is "
						+ to_string(this->size()) + ")");
					return this->_tab[i];
				}

				const_reference	at(const size_type i) const
				{
					if (i >= this->_size)
						throw std::out_of_range("vector::_M_range_check: __n (which is "
						+ to_string(i) + ") >= this->size() (which is "
						+ to_string(this->size()) + ")");
					return this->_tab[i];
				}

				reference front()
				{
					return this->_tab[0];
				}

				const_reference front() const
				{
					return this->_tab[0];
				}

				reference back()
				{
					if (PRINT)
						cout << "Vector::back(), size = " << this->_size << '\n';
					if (!this->_size)
						std::cerr << "Size == 0, expect to be "
						<< "absorbed by a Black Hole, or something\n";
					return this->_tab[this->_size - 1];
				}

				const_reference back() const
				{
					if (PRINT)
						cout << "Vector::const_back(), size = " << this->_size << '\n';
					if (!this->_size)
						std::cerr << "Size == 0, expect to be "
						<< "absorbed by a Black Hole, or something\n";
					return this->_tab[this->_size - 1];
				}

				// MODIFIERS
				template < class InputIter>
				void	assign(InputIter first,
					typename enable_if<InputIter::input_iter, InputIter>::type last)
				{
					this->clear();
					this->insert(this->begin(), first, last);
				}

				void	assign(size_type n, const value_type& val)
				{
					this->clear();
					this->reserve(n);
					for (size_type i = 0; i < n; i++)
						this->_tab[i] = val;
					this->_size = n;
				}

				void	push_back(const value_type& val)
				{
					this->reserve(this->_size + 1);
					this->_tab[this->_size] = val;
					this->_size++;
				}

				void	pop_back()
				{
					this->resize(this->size() - 1);
				}

				iterator	insert(iterator position, const value_type& val)
				{
					difference_type	tmp;

					tmp = position - this->begin();
					this->insert(position, 1, val);

					return this->begin() + tmp;
				}

				void		insert(iterator position, size_type n, const value_type& val)
				{
					difference_type tmp;

					tmp = position - this->begin();

					this->reserve(this->_size + n);
					position = this->begin() + tmp;

					this->_size += n;
					for (iterator it = this->end() - 1; it != position + n - 1; it--)
						*it = *(it - n);
					for (iterator it = position; it != position + n; it++)
						*it = val;
				}

				template < class InputIter>
				void	insert(iterator position, InputIter first,
					typename enable_if<InputIter::input_iter, InputIter>::type last)
					{
						difference_type	n, tmp;
						
						n = last - first;
						tmp = position - this->begin();
						this->reserve(this->_size + n);
						position = this->begin() + tmp;
						this->_size += n;
						for (iterator it = this->end() - 1; it != (position + n  - 1); it--)
						{
							*it = *(it - n);
						}
						while (first != last)
						{
							*position = *first;
							position++;
							first++;
						}
					}

				iterator	erase(iterator position)
				{
					iterator	ret;

					ret = position;
//					position->value_type::~value_type();
					while (position + 1 != this->end())
					{
						*position = *(position + 1);
						position++;
					}
//					position->value_type::~value_type();
					this->_size--;
					return ret;
				}

				iterator	erase(iterator first, iterator last)
				{
					while (first != last)
					{
						erase(first);
						last--;
					}
					return first;
				}

				void	swap(vector& vec)
				{
					value_type*	tmp = vec._tab;
					size_type	sz = vec._size;
					size_type	cp = vec._capacity;

					vec._tab = this->_tab;
					vec._size = this->_size;
					vec._capacity = this->_capacity;
					this->_tab = tmp;
					this->_size = sz;
					this->_capacity = cp;
				}

				void	clear()
				{
					erase(this->begin(), this->end());
				}

				pointer					_tab;
			private:

				size_type				_size;
				size_type				_capacity;
		};

// NON MEMBER functions

	template <class T>
		void	swap(vector<T>& x, vector<T>& y)
		{
			x.swap(y);
		}
	
	template <class T>
		bool operator==(const vector<T>& left, const vector<T>& right)
		{
			if (left.size() != right.size())
				return false;
			for (typename ft::vector<T>::size_type i = 0; i < left.size(); i++)
				if (left[i] != right[i])
					return false;

			return true;
		}
	
	template <class T>
		bool operator==(vector<T>& left, vector<T>& right)
		{
			if (left.size() != right.size())
				return false;
			for (typename ft::vector<T>::size_type i = 0; i < left.size(); i++)
				if (left[i] != right[i])
					return false;

			return true;
		}
	
	template <class T>
		bool operator<(vector<T>& left, vector<T>& right)
		{
			typename ft::vector<T>::size_type	i = 0;

			while (i < left.size() && i < right.size() && left[i] == right[i])
				i++;
			if (i >= left.size())
				return true;
			if (i >= right.size())
				return false;
			return (left[i] < right[i]);
		}

	template <class T>
		bool operator!=(vector<T>& left, vector<T>& right)
		{
			return (!(left == right));
		}

	template <class T>
		bool operator>(vector<T>& left, vector<T>& right)
		{
			return (right < left);
		}

	template <class T>
		bool operator<=(vector<T>& left, vector<T>& right)
		{
			return (!(right < left));
		}

	template <class T>
		bool operator>=(vector<T>& left, vector<T>& right)
		{
			return (!(left < right));
		}
}


