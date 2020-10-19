/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:54:49 by hbaudet           #+#    #+#             */
/*   Updated: 2020/10/19 17:59:28 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
	template<class T>
	class iterator
	{
		private:
			T*	_ptr;

		public:
			iterator();
			iterator(const iterator&);
			virtual ~iterator();
			bool					operator==(void*) const;
			bool					operator!=(void*) const;
			T*						operator->() const;
			T*						operator*() const;
			virtual const iterator&	operator=(T*);
			virtual const iterator&	operator=(const iterator<T>&);
			virtual const iterator&	operator+(int);
			virtual const iterator&	operator-(int);
			virtual const iterator&	operator++();
			virtual const iterator&	operator++(int);
			virtual const iterator&	operator--();
			virtual const iterator&	operator--(int);
	};
	
	template<class T>
	class reverse_iterator : public iterator<T>
	{
		public:
			~reverse_iterator();
			const reverse_iterator&	operator=(T*);
			const reverse_iterator&	operator=(const iterator<T>&);
			const reverse_iterator&	operator+(int);
			const reverse_iterator&	operator-(int);
			const reverse_iterator&	operator++();
			const reverse_iterator&	operator++(int);
			const reverse_iterator&	operator--();
			const reverse_iterator&	operator--(int);
	};
} 