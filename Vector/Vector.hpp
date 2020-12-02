/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:03:48 by hbaudet           #+#    #+#             */
/*   Updated: 2020/12/02 18:16:08 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <limits>

#ifdef DEBUG
# define PRINT 1
#else
# define PRINT 0
#endif


namespace ft 
{
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
				/*
				   typedef VectorIterator<value_type>				iterator;
				   typedef VectorIterator<const value_type>			const_iterator;
				   typedef ReverseIterator<iterator>				reverse_iterator;
				   typedef ReverseIterator<const_iterator>			const_reverse_iterator;
				 */
				typedef ptrdiff_t									difference_type;
				typedef size_t										size_type;

				// CTOR / DTOR
				vector(const allocator_type& alloc = allocator_type()):
					_alloc(alloc), _size(0), _capacity(0)
				{
					if (PRINT)
						std::cout << "Default constructor called\n";

					this->_tab = new value_type[0];
				}

				vector(size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type()):
						_alloc(alloc), _size(n), _capacity(n)
				{
					if (PRINT)
						std::cout << "Fill constructor called\n";

					this->_tab = new T[n];
					for (size_t i = 0; i < n; i++)
						this->_tab[i] = val;
				}
				
				/*
				   vector(InputIter first, InputIter last,
				   const allocator_type& alloc = allocator_type());
				 */
				
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
					/*
					if (obj == *this)
						return obj;
					*/
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

				// Capacity
				size_type	size() const
				{
					return this->_size;
				}

				size_type	max_size() const // WITHOUT STL ?!
				{
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
							tmp[i] = this->_tab[i];
						for (size_type i = 0; i < this->_size; i++)
							this->_tab[i].value_type::~value_type();
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
				/*
				void	assign(iter first, iter last)
				*/

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

				/*
				iterator	insert(iterator position, const value_type& val)
				void		insert(iterator position, size_type n, const value_type& val)
				template iter
				void		insert(iterator position, iter first, iter last)
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
					vector<T, Alloc>	tmp = vec;

					vec = *this;
					*this = tmp;
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
}
