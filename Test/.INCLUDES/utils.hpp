/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:20:31 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/13 17:29:52 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <string>
# include <sstream>

# ifdef DEBUG
#  define PRINT 1
#  else
#  define PRINT 0
# endif


namespace ft
{
	static std::ostream& 									cout = std::cout;
	typedef std::string										string;


	string	to_string(size_t n)
	{
		std::stringstream tmp;

		tmp << n;

		return tmp.str();
	}

	template<bool B, class T = void>
		struct enable_if {};

	template<class T>
		struct enable_if<true, T> { typedef T type; };

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
				typedef typename Iterator::const_iterator	const_iterator;

				ReverseIterator(): input_iter(false), _base(NULL) {}
				ReverseIterator(const ReverseIterator<iterator_type>& rev):
					input_iter(rev.input_iter), _base(rev._base) {}
				ReverseIterator(const ReverseIterator<typename enable_if<Iterator::is_not_const, typename Iterator::const_iterator>::type>& rev):
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

				pointer				operator->() const
				{
					iterator_type	tmp(this->_base);
					tmp--;

					pointer		ret = tmp.operator->();
					
					return ret;
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

				reference			operator[](difference_type n) const
				{
					return this->_base[-n - 1];
				}

				ReverseIterator&	operator=(const ReverseIterator& vec)
				{
					if (PRINT)
						std::cout << "ReverseIterator operator =\n";
					this->_base = vec.base();
					return *this;
				}

			private:
				iterator_type	_base;
		};

	template < class Iterator>
		bool	operator==(const ReverseIterator<Iterator>& l, const ReverseIterator<Iterator>& r)
		{
			return l.base() == r.base();
		}

	template < class Iterator>
		bool	operator!=(const ReverseIterator<Iterator>& l, const ReverseIterator<Iterator>& r)
		{
			return l.base() != r.base();
		}

	template < class Iterator>
		bool	operator<(const ReverseIterator<Iterator>& l, const ReverseIterator<Iterator>& r)
		{
			return l.base() < r.base();
		}

	template < class Iterator>
		bool	operator<=(const ReverseIterator<Iterator>& l, const ReverseIterator<Iterator>& r)
		{
			return l.base() <= r.base();
		}

	template < class Iterator>
		bool	operator>(const ReverseIterator<Iterator>& l, const ReverseIterator<Iterator>& r)
		{
			return l.base() > r.base();
		}

	template < class Iterator>
		bool	operator>=(const ReverseIterator<Iterator>& l, const ReverseIterator<Iterator>& r)
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

#endif