/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:03:48 by hbaudet           #+#    #+#             */
/*   Updated: 2020/12/08 15:18:58 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <limits>
#include "ReverseIterator.hpp"

#ifdef DEBUG
# define PRINT 1
#else
# define PRINT 0
#endif


namespace ft 
{

	template<bool B, class T = void>
		struct enable_if {};

	template<class T>
		struct enable_if<true, T> { typedef T type; };

	// ITERATOR
	template < class T>
		class VectorIterator
		{
			public:
				typedef T					value_type;
				typedef	value_type*			pointer;
				typedef	const value_type*	const_pointer;
				typedef value_type&			reference;
				typedef const value_type&	const_reference;
				typedef	std::ptrdiff_t		difference_type;

				static const bool			input_iter;
				
				VectorIterator(): _ptr(NULL) {}
				VectorIterator(pointer ptr) : _ptr(ptr) {}
				VectorIterator(const VectorIterator<T>& vec): _ptr(vec.getPointer()) {}
				~VectorIterator() {}
				VectorIterator& operator=(const VectorIterator& vec)
				{
					this->_ptr = vec.getPointer();
					return *this;
				}

				pointer			getPointer() const
				{
					return this->_ptr;
				}

/*
				const_pointer	getPointer() const
				{
					return this->_ptr;
				}
*/

				reference		operator*()
				{
					return (*(this->_ptr));
				}

				const_reference	operator*() const
				{
					return (*(this->_ptr));
				}

				pointer			operator->()
				{
					return (this->_ptr);
				}

				VectorIterator	operator++()
				{
					++(this->_ptr);
					return this;
				}

				VectorIterator	operator++(int)
				{
					VectorIterator	tmp = *this;

					++(this->_ptr);
					return tmp;
				}

				VectorIterator	operator--()
				{
					--(this->_ptr);
					return this;
				}

				VectorIterator	operator--(int)
				{
					VectorIterator	tmp = *this;

					--(this->_ptr);
					return tmp;
				}

				VectorIterator	operator+(difference_type i) const
				{
					VectorIterator	tmp(*this);

					tmp += i;
					return tmp;
				}

				VectorIterator	operator-(difference_type i) const
				{
					VectorIterator	tmp(*this);

					tmp -= i;
					return tmp;
				}

				VectorIterator	operator+=(difference_type i)
				{
					this->_ptr += i;
					return *this;
				}

				VectorIterator	operator-=(difference_type i)
				{
					this->_ptr -= i;
					return *this;
				}

				difference_type	operator-(const VectorIterator& vec) const
				{
					return (this->_ptr - vec.getPointer());
				}

				reference		operator[](difference_type i)
				{
					return *(this->_ptr + i);
				}

				bool operator==(const VectorIterator& right) const 
				{
					return (this->_ptr == right.getPointer());
				}

				bool operator!=(const VectorIterator& right) const 
				{
					return (!(*this == right));
				}

				bool operator<(const VectorIterator& right) const
				{
					return (&(*(this->_ptr)) < &(*right));
				}

				bool operator>(const VectorIterator& right) const
				{
					return right < *this;
				}

				bool operator<=(const VectorIterator& right) const
				{
					return !(*this > right);
				}

				bool operator>=(const VectorIterator& right) const
				{
					return !(*this < right);
				}

			protected:
				pointer		_ptr;
		};

	template<class T>
		bool operator!=(const VectorIterator<T>& lhs, const VectorIterator<T>& rhs)
		{
			return !(lhs == rhs);
		}
	

	template < class T>
	const bool VectorIterator<T>::input_iter = true;


	// VECTOR
	template < class T>
		class vector
		{
			public:
				// Typedefs
				typedef	T											value_type;
				typedef value_type&									reference;
				typedef const value_type&							const_reference;
				typedef T*											pointer;
				typedef const T*									const_pointer;
				typedef VectorIterator<value_type>					iterator;
				typedef VectorIterator<const value_type>			const_iterator;
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
					for (size_type i = 0; i < this->_size; i++)
						this->_tab[i].value_type::~value_type();
					delete[] this->_tab;
				}

				vector&		operator=(const vector& obj)
				{
					if (PRINT)
						std::cout << "Assignation operator called\n";
					if (*this == obj)
						return *this;
					
					this->clear();
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
					return const_iterator(this->_tab);
				}

				iterator end()
				{
					iterator ret(this->_tab + this->_size);

					return ret;
				}

				const_iterator end() const
				{
					return const_iterator(this->_tab + this->_size);
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

				size_type	max_size() const // WITHOUT STL ?!
				{
//					return value_type::value_type.max_size();
					return (std::numeric_limits<size_type>::max());
				}

				void		resize(size_type n, value_type val = value_type())
				{
					if (n < this->_size)
					{
						for (size_type i = n; i < this->_size; i++)
							this->_tab[i].value_type::~value_type();
						this->_size = n;
					}
					else if (n > this->_capacity)
					{
						value_type	*tmp = new value_type[n];
						for (size_type i = 0; i < this->_size; i++)
							tmp[i] = this->_tab[i];
						for (size_type i = this->_size; i < n; i++)
							tmp[i] = val;
						for (size_type i = 0; i < this->_size; i++)
							this->_tab[i].value_type::~value_type();
						delete[] this->_tab;
						this->_tab = tmp;
						this->_size = n;
						this->_capacity = n;
					}
					else
					{
						for (size_type i = this->_size; i < n; i++)
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
						value_type	*tmp = new value_type[n];
						for (size_type i = 0; i < this->_size; i++)
						{
							tmp[i] = this->_tab[i];
							this->_tab[i].value_type::~value_type();
						}
						delete[] this->_tab;
						this->_tab = tmp;
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
						throw std::out_of_range("vector::at() | Out of range access)\n");
					return this->_tab[i];
				}

				const_reference	at(const size_type i) const
				{
					if (i >= this->_size)
						throw std::out_of_range("vector::at() | Out of range access\n");
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
					return this->_tab[this->_size - 1];
				}

				const_reference back() const
				{
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
					this->reserve(n);
					for (size_type i = 0; i < n; i++)
					{
						this->_tab[i].value_type::~value_type();
						this->_tab[i] = val;
					}
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
					this->_tab[this->_size - 1].value_type::~value_type();
					this->_size--;
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
					(*position).value_type::~value_type();
					while (position != this->end() - 1)
					{
						*position = *(position + 1);
						position++;
					}
					this->_size--;
					return ret;
				}

				iterator	erase(iterator first, iterator last)
				{
					iterator		ret;
					difference_type	i;

					ret = first;
					i = 0;
					while (first != last)
					{
						(*first).value_type::~value_type();
						if (last + i < this->end())
							*first = *(last + i);
						first++;
						i++;
					}
					while (first != this->end() - i)
					{
						(*first).value_type::~value_type();
						*first = *(first + i);
						first++;
					}
					while (first != this->end())
					{
						(*first).value_type::~value_type();
						first++;
					}
					this->_size -= i;
					return ret;
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
					for (size_type i = 0; i < this->_size; i++)
						this->_tab[i].value_type::~value_type();
					this->_size = 0;
				}

			private:

				pointer					_tab;
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


