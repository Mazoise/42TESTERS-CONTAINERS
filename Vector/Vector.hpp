/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:03:48 by hbaudet           #+#    #+#             */
/*   Updated: 2020/12/03 18:31:54 by hbaudet          ###   ########.fr       */
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

				static bool					input_iter;
				
				VectorIterator(): _ptr(NULL) {}
				VectorIterator(pointer ptr) : _ptr(ptr) {}
				VectorIterator(const VectorIterator<T>& vec): _ptr(&(*vec)) {}
				~VectorIterator() {}
				VectorIterator& operator=(const VectorIterator& vec)
				{
					this->_ptr = &(*vec);
				}

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

				difference_type	operator-(VectorIterator& vec)
				{
					return (this->_ptr - vec._ptr);
				}

				reference		operator[](difference_type i)
				{
					return *(this->_ptr + i);
				}

				bool operator==(const VectorIterator& right) const 
				{
					return (this->_ptr == right._ptr);
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
	bool VectorIterator<T>::input_iter = true;

	// VECTOR
	template < class T, class Alloc = std::allocator<T> >
		class vector
		{
			public:
				// Typedefs
				typedef	T											value_type;
				typedef	Alloc										allocator_type; 
				typedef typename allocator_type::reference			reference;
				typedef typename allocator_type::const_reference	const_reference;
				typedef typename allocator_type::pointer			pointer;
				typedef typename allocator_type::const_pointer		const_pointer;
				typedef VectorIterator<value_type>					iterator;
				typedef VectorIterator<const value_type>			const_iterator;
				typedef ReverseIterator<iterator>					reverse_iterator;
				typedef ReverseIterator<const_iterator>				const_reverse_iterator;
				typedef ptrdiff_t									difference_type;
				typedef size_t										size_type;

				// MEMBER
				explicit vector(const allocator_type& alloc = allocator_type()):
					_alloc(alloc), _size(0), _capacity(0)
				{
					if (PRINT)
						std::cout << "Default constructor called\n";

					this->_tab = new value_type[0];
				}

				explicit vector(size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type()):
						_alloc(alloc), _size(n), _capacity(n)
				{
					if (PRINT)
						std::cout << "Fill constructor called\n";

					this->_tab = new T[n];
					for (size_t i = 0; i < n; i++)
						this->_tab[i] = val;
				}
				
				template < class InputIter>
				vector(typename enable_if<InputIter::input_iter, InputIter>::type first,
						typename enable_if<InputIter::input_iter, InputIter>::type last,
					const allocator_type& alloc = allocator_type()):
						_tab(NULL), _alloc(alloc), _size(0), _capacity(0)
				{
					if (PRINT)
						std::cout << "Range constructor called\n";

					this->assign(first, last);
				}

				vector(const vector& obj):
					_tab(NULL), _alloc(allocator_type()), _size(0), _capacity(0)
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
					for (size_type i = 0; i < this->_size; i++)
						this->_tab[i].value_type::~value_type();
					delete[] this->_tab;
					this->_size = obj.size();
					this->_tab = new value_type[this->_size];
					this->_capacity = this->_size;
					for (size_t i = 0; i < this->_size; i++)
						this->_tab[i] = obj[i];
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
					const_iterator ret(this->_tab);

					return ret;
				}

				iterator end()
				{
					iterator ret(this->_tab + this->_size);

					return ret;
				}

				const_iterator end() const
				{
					const_iterator ret(this->_tab + this->_size);

					return ret;
				}

				reverse_iterator	rbegin()
				{
					reverse_iterator	ret(this->end() - 1);

					return ret;
				}

				const_reverse_iterator	rbegin() const
				{
					const_reverse_iterator	ret(this->end() - 1);

					return ret;
				}

				reverse_iterator	rend()
				{
					reverse_iterator	ret(this->begin() - 1);

					return ret;
				}

				const_reverse_iterator	rend() const
				{
					const_reverse_iterator	ret(this->end() - 1);

					return ret;
				}

				// Capacity
				size_type	size() const
				{
					return this->_size;
				}

				size_type	max_size() const // WITHOUT STL ?!
				{
					return this->_alloc.max_size();
//					return (std::numeric_limits<size_type>::max());
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
						throw std::out_of_range("vector::at() | Out of range access)\n");
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
				void	assign
					(typename enable_if<InputIter::input_iter, InputIter>::type first,
						typename enable_if<InputIter::input_iter, InputIter>::type last)
				{
					this->reserve(last - first);
					this->clear();
					while (first < last)
					{
						this->push_back(*first++);
					}
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
					this->insert(position, 1, val);
					return position;
				}

				void		insert(iterator position, size_type n, const value_type& val)
				{
					this->reserve(this->_size + n);
					for (iterator it = this->end() - 1; it != position + n - 1; it--)
					{
						*it = *(it - n);
					}
					for (iterator it = position; it != position + n; it++)
						*it = val;
				}

/*
				template < class InputIterator>
					void		insert(iterator position, InputIterator first, InputIterator last)
					{
	
					}
*/

				/*
				iterator	erase(iterator position)
				{

				}
				iterator	erase(iterator first, iterator last)
				{

				}
				*/

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
				const allocator_type	_alloc;
				size_type				_size;
				size_type				_capacity;
		};

// NON MEMBER functions

	template <class T, class Alloc = std::allocator<T> >
		void	swap(vector<T, Alloc>& x, vector<T, Alloc>& y)
		{
			x.swap(y);
		}
	
	template <class T, class Alloc = std::allocator<T> >
		bool operator==(const vector<T, Alloc>& left, const vector<T, Alloc>& right)
		{
			if (left.size() != right.size())
				return false;
			for (typename ft::vector<T, Alloc>::size_type i = 0; i < left.size(); i++)
				if (left[i] != right[i])
					return false;

			return true;
		}
	
	template <class T, class Alloc = std::allocator<T> >
		bool operator==(vector<T, Alloc>& left, vector<T, Alloc>& right)
		{
			if (left.size() != right.size())
				return false;
			for (typename ft::vector<T, Alloc>::size_type i = 0; i < left.size(); i++)
				if (left[i] != right[i])
					return false;

			return true;
		}
	
	template <class T, class Alloc = std::allocator<T> >
		bool operator<(vector<T, Alloc>& left, vector<T, Alloc>& right)
		{
			typename ft::vector<T, Alloc>::size_type	i = 0;

			while (i < left.size() && i < right.size() && left[i] == right[i])
				i++;
			if (i >= left.size())
				return true;
			if (i >= right.size())
				return false;
			return (left[i] < right[i]);
		}

	template <class T, class Alloc = std::allocator<T> >
		bool operator!=(vector<T, Alloc>& left, vector<T, Alloc>& right)
		{
			return (!(left == right));
		}

	template <class T, class Alloc = std::allocator<T> >
		bool operator>(vector<T, Alloc>& left, vector<T, Alloc>& right)
		{
			return (right < left);
		}

	template <class T, class Alloc = std::allocator<T> >
		bool operator<=(vector<T, Alloc>& left, vector<T, Alloc>& right)
		{
			return (!(right < left));
		}

	template <class T, class Alloc = std::allocator<T> >
		bool operator>=(vector<T, Alloc>& left, vector<T, Alloc>& right)
		{
			return (!(left < right));
		}
}


