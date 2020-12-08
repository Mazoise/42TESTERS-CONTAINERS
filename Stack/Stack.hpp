/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:03:50 by hbaudet           #+#    #+#             */
/*   Updated: 2020/12/08 13:32:18 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <deque>

#ifdef DEBUG
# define PRINT 1
#else
# define PRINT 0
#endif

namespace ft
{

	template <class T, class Container = std::deque<T> >
	class stack
	{
		public:

		// TYPES
		typedef T				value_type;
		typedef Container		container_type;
		typedef size_t			size_type;
	
		// MEMBER FCTS
		explicit stack(const container_type& ctnr = container_type()):
			c(ctnr) {}
		/* Is is needed though?
		~stack()
		{
			this->c::~c();
		}
		*/
		bool				empty() const
		{
			return this->c.empty();
		}
		size_type			size() const
		{
			return this->c.size();
		}
		value_type&		top()
		{
			return this->c.back();
		}
		const value_type&	top() const
		{
			return this->c.back();
		}
		void				push(const value_type& val)
		{
			this->c.push_back(val);
		}
		void				pop()
		{
			this->c.pop_back();
		}

		friend bool operator==(const stack<value_type, container_type>& lhs,
			const stack<value_type, container_type>& rhs)
		{
			return lhs.c == rhs.c;
		}

		friend bool operator!=(const stack<value_type, container_type>& lhs,
			const stack<value_type, container_type>& rhs)
		{
			return lhs.c != rhs.c;
		}

		friend bool operator<(const stack<value_type, container_type>& lhs,
			const stack<value_type, container_type>& rhs)
		{
			return lhs.c < rhs.c;
		}

		friend bool operator<=(const stack<value_type, container_type>& lhs,
			const stack<value_type, container_type>& rhs)
		{
			return lhs.c <= rhs.c;
		}

		friend bool operator>(const stack<value_type, container_type>& lhs,
			const stack<value_type, container_type>& rhs)
		{
			return lhs.c > rhs.c;
		}

		friend bool operator>=(const stack<value_type, container_type>& lhs,
			const stack<value_type, container_type>& rhs)
		{
			return lhs.c >= rhs.c;
		}

		protected:
			container_type	c;
	};
}
