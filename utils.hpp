/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:20:31 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/15 16:39:29 by hbaudet          ###   ########.fr       */
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

	template <bool flag, class IsTrue, class IsFalse>
		struct choose;

	template <class IsTrue, class IsFalse>
		struct choose<true, IsTrue, IsFalse>
		{
			typedef IsTrue type;
		};

	template <class IsTrue, class IsFalse>
		struct choose<false, IsTrue, IsFalse>
		{
			typedef IsFalse type;
		};

	template<bool B, class T = void>
		struct enable_if {};

	template<class T>
		struct enable_if<true, T> { typedef T type; };

	template <class Iterator>
		class ReverseIterator
		{
			public:
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

				bool										input_iter;
				iterator_type	_base;

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

	template <class Iterator>
		class const_ReverseIterator
		{
			public:
				typedef	typename Iterator::iterator_not_const	iterator_not_const;
				typedef Iterator								iterator_type;
				typedef typename Iterator::value_type			value_type;
				typedef	typename Iterator::difference_type		difference_type;
				typedef typename Iterator::pointer				pointer;
				typedef typename Iterator::reference			reference;

				const_ReverseIterator(): input_iter(false), _base(NULL) {}
				const_ReverseIterator(const const_ReverseIterator<iterator_type>& rev):
					input_iter(rev.input_iter), _base(rev._base) {}
				const_ReverseIterator(const ReverseIterator<iterator_not_const>& rev):
					input_iter(rev.input_iter), _base(rev._base) {}
				const_ReverseIterator(iterator_type it): input_iter(it.input_iter), _base(it) {}
				const_ReverseIterator(iterator_not_const it): input_iter(it.input_iter), _base(iterator_type(it)) {}
				~const_ReverseIterator() {}
				
				bool										input_iter;
				iterator_type								_base;

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

				const_ReverseIterator		operator+(difference_type n) const
				{
					const_ReverseIterator	ret(this->_base - n);

					return ret;
				}

				const_ReverseIterator&	operator++()
				{
					--this->_base;

					return (*this);
				}

				const_ReverseIterator		operator++(int)
				{
					const_ReverseIterator	ret = *this;

					++(*this);
					return ret;
				}

				const_ReverseIterator&	operator+=(difference_type n)
				{
					this->_base -= n;
					return *this;
				}

				const_ReverseIterator		operator-(difference_type n) const
				{
					const_ReverseIterator	ret(this->_base + n);

					return ret;
				}

				const_ReverseIterator&	operator--()
				{
					++this->_base;

					return (*this);
				}

				const_ReverseIterator		operator--(int)
				{
					const_ReverseIterator	ret = *this;

					--(*this);
					return ret;
				}

				const_ReverseIterator&	operator-=(difference_type n)
				{
					this->_base += n;
					return *this;
				}

				reference			operator[](difference_type n) const
				{
					return this->_base[-n - 1];
				}

				const_ReverseIterator&	operator=(const const_ReverseIterator& vec)
				{
					if (PRINT)
						std::cout << "const_ReverseIterator operator =\n";
					this->_base = vec.base();
					return *this;
				}

		};

	template < class Iterator>
		bool	operator==(const const_ReverseIterator<Iterator>& l, const const_ReverseIterator<Iterator>& r)
		{
			return l.base() == r.base();
		}

	template < class Iterator>
		bool	operator!=(const const_ReverseIterator<Iterator>& l, const const_ReverseIterator<Iterator>& r)
		{
			return l.base() != r.base();
		}

	template < class Iterator>
		bool	operator<(const const_ReverseIterator<Iterator>& l, const const_ReverseIterator<Iterator>& r)
		{
			return l.base() < r.base();
		}

	template < class Iterator>
		bool	operator<=(const const_ReverseIterator<Iterator>& l, const const_ReverseIterator<Iterator>& r)
		{
			return l.base() <= r.base();
		}

	template < class Iterator>
		bool	operator>(const const_ReverseIterator<Iterator>& l, const const_ReverseIterator<Iterator>& r)
		{
			return l.base() > r.base();
		}

	template < class Iterator>
		bool	operator>=(const const_ReverseIterator<Iterator>& l, const const_ReverseIterator<Iterator>& r)
		{
			return l.base() >= r.base();
		}
	
	template < class Iterator>
  		const_ReverseIterator<Iterator> operator+
			(typename const_ReverseIterator<Iterator>::difference_type n,
             	const const_ReverseIterator<Iterator>& rev_it)
		{
			return rev_it + n;
		}

	template < class Iterator>
  		typename const_ReverseIterator<Iterator>::difference_type operator-
			(const const_ReverseIterator<Iterator>& lhs,
				const const_ReverseIterator<Iterator>& rhs)
		{
			return rhs.base() - lhs.base();
		}


		//left const right not const

	template < class Iterator>
		bool	operator==(const const_ReverseIterator<Iterator>& l, const ReverseIterator<typename Iterator::iterator_not_const>& r)
		{
			return l.base() == r.base();
		}

	template < class Iterator>
		bool	operator!=(const const_ReverseIterator<Iterator>& l, const ReverseIterator<typename Iterator::iterator_not_const>& r)
		{
			return l.base() != r.base();
		}

	template < class Iterator>
		bool	operator<(const const_ReverseIterator<Iterator>& l, const ReverseIterator<typename Iterator::iterator_not_const>& r)
		{
			return l.base() < r.base();
		}

	template < class Iterator>
		bool	operator<=(const const_ReverseIterator<Iterator>& l, const ReverseIterator<typename Iterator::iterator_not_const>& r)
		{
			return l.base() <= r.base();
		}

	template < class Iterator>
		bool	operator>(const const_ReverseIterator<Iterator>& l, const ReverseIterator<typename Iterator::iterator_not_const>& r)
		{
			return l.base() > r.base();
		}

	template < class Iterator>
		bool	operator>=(const const_ReverseIterator<Iterator>& l, const ReverseIterator<typename Iterator::iterator_not_const>& r)
		{
			return l.base() >= r.base();
		}
	
	template < class Iterator>
  		const_ReverseIterator<Iterator> operator+
			(typename const_ReverseIterator<Iterator>::difference_type n,
             	const ReverseIterator<typename Iterator::iterator_not_const>& rev_it)
		{
			return rev_it + n;
		}

	template < class Iterator>
  		typename const_ReverseIterator<Iterator>::difference_type operator-
			(const const_ReverseIterator<Iterator>& lhs,
				const ReverseIterator<typename Iterator::iterator_not_const>& rhs)
		{
			return rhs.base() - lhs.base();
		}

	// left not const, right const
	template < class Iterator>
		bool	operator==(const ReverseIterator<typename Iterator::iterator_not_const>& l, const const_ReverseIterator<Iterator>& r)
		{
			return l.base() == r.base();
		}

	template < class Iterator>
		bool	operator!=(const ReverseIterator<typename Iterator::iterator_not_const>& l, const const_ReverseIterator<Iterator>& r)
		{
			return l.base() != r.base();
		}

	template < class Iterator>
		bool	operator<(const ReverseIterator<typename Iterator::iterator_not_const>& l, const const_ReverseIterator<Iterator>& r)
		{
			return l.base() < r.base();
		}

	template < class Iterator>
		bool	operator<=(const ReverseIterator<typename Iterator::iterator_not_const>& l, const const_ReverseIterator<Iterator>& r)
		{
			return l.base() <= r.base();
		}

	template < class Iterator>
		bool	operator>(const ReverseIterator<typename Iterator::iterator_not_const>& l, const const_ReverseIterator<Iterator>& r)
		{
			return l.base() > r.base();
		}

	template < class Iterator>
		bool	operator>=(const ReverseIterator<typename Iterator::iterator_not_const>& l, const const_ReverseIterator<Iterator>& r)
		{
			return l.base() >= r.base();
		}

	template < class Iterator>
  		typename const_ReverseIterator<Iterator>::difference_type operator-
			(const ReverseIterator<typename Iterator::iterator_not_const>& lhs,
				const const_ReverseIterator<Iterator>& rhs)
		{
			return rhs.base() - lhs.base();
		}
}

#endif