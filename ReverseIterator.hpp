/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:20:31 by hbaudet           #+#    #+#             */
/*   Updated: 2020/12/03 16:53:36 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

#ifdef DEBUG
# define PRINT 1
# else
# define PRINT 0
#endif


namespace ft
{
	template <class Iterator>
		class ReverseIterator
		{
			public:
				bool										input_iter;
				
				typedef Iterator							iterator_type;
				typedef typename Iterator::value_type		value_type;
				typedef	typename Iterator::difference_type	difference_type;
				typedef typename Iterator::pointer			pointer;
				typedef typename Iterator::reference		reference;

				ReverseIterator(): input_iter(false), _base(NULL) {}
				ReverseIterator(const ReverseIterator<iterator_type>& rev):
					input_iter(rev.input_iter), _base(rev._base) {}
				ReverseIterator(iterator_type it): input_iter(it.input_iter), _base(it) {}
				~ReverseIterator() {}

				iterator_type		base() const
				{
					return this->_base;
				}

				reference			operator*() const
				{
					iterator_type	tmp(this->_base);

					return (*(--tmp));
				}

				ReverseIterator		operator+(difference_type n) const
				{
					ReverseIterator	ret(this->_base - n);

					return ret;
				}

				ReverseIterator&	operator++()
				{
					--this->_base;

					return (*this);
				}

				ReverseIterator		operator++(int)
				{
					ReverseIterator	ret = *this;

					++(*this);
					return ret;
				}

				ReverseIterator&	operator+=(difference_type n)
				{
					this->_base -= n;
					return *this;
				}

				ReverseIterator		operator-(difference_type n) const
				{
					ReverseIterator	ret(this->_base + n);

					return ret;
				}

				ReverseIterator&	operator--()
				{
					++this->_base;

					return (*this);
				}

				ReverseIterator		operator--(int)
				{
					ReverseIterator	ret = *this;

					--(*this);
					return ret;
				}

				ReverseIterator&	operator-=(difference_type n)
				{
					this->_base += n;
					return *this;
				}

				pointer				operator->() const
				{
					return &(operator*());
				}

				reference			operator[](difference_type n) const
				{
					return this->_base[-n - 1];
				}

			private:
				iterator_type	_base;
		};

	template < class Iterator>
		bool	operator==(ReverseIterator<Iterator>& l, ReverseIterator<Iterator>& r)
		{
			return l.base() == r.base();
		}

	template < class Iterator>
		bool	operator!=(ReverseIterator<Iterator>& l, ReverseIterator<Iterator>& r)
		{
			return l.base() != r.base();
		}

	template < class Iterator>
		bool	operator<(ReverseIterator<Iterator>& l, ReverseIterator<Iterator>& r)
		{
			return l.base() < r.base();
		}

	template < class Iterator>
		bool	operator<=(ReverseIterator<Iterator>& l, ReverseIterator<Iterator>& r)
		{
			return l.base() <= r.base();
		}

	template < class Iterator>
		bool	operator>(ReverseIterator<Iterator>& l, ReverseIterator<Iterator>& r)
		{
			return l.base() > r.base();
		}

	template < class Iterator>
		bool	operator>=(ReverseIterator<Iterator>& l, ReverseIterator<Iterator>& r)
		{
			return l.base() >= r.base();
		}
	
	template < class Iterator>
  		ReverseIterator<Iterator> operator+
			(typename ReverseIterator<Iterator>::difference_type n,
             	const ReverseIterator<Iterator>& rev_it)
		{
			return rev_it + n;
		}

	template < class Iterator>
  		typename ReverseIterator<Iterator>::difference_type operator-
			(const ReverseIterator<Iterator>& lhs,
				const ReverseIterator<Iterator>& rhs)
		{
			return rhs.base() - lhs.base();
		}
}
