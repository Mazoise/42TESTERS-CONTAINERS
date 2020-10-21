/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:54:49 by hbaudet           #+#    #+#             */
/*   Updated: 2020/10/21 18:10:42 by hbaudet          ###   ########.fr       */
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
			iterator(T* t = NULL);
			iterator(const iterator&);
			virtual ~iterator();
			T*						getPtr() const;
			bool					operator==(const iterator&) const;
//			bool					operator!=(void*) const;
//			T*						operator->() const;
//			T*						operator*() const;
//			virtual const iterator&	operator=(T*);
			virtual const iterator&	operator=(const iterator<T>&);
	/*
			virtual const iterator&	operator++();
			virtual const iterator&	operator++(int);
			virtual const iterator&	operator--();
			virtual const iterator&	operator--(int);
	*/
	};
/*
	
	template<class T>
	class reverse_iterator : public iterator<T>
	{
		public:
			~reverse_iterator();
			const reverse_iterator&	operator=(const iterator<T>&);
			const reverse_iterator&	operator++();
			const reverse_iterator&	operator++(int);
			const reverse_iterator&	operator--();
			const reverse_iterator&	operator--(int);
	};
*/
} 

template<class T>
ft::iterator<T>::iterator(T* t) : _ptr(t) {}

template<class T>
ft::iterator<T>::~iterator() {}

template<class T>
ft::iterator<T>::iterator(const iterator& it) : _ptr(it.getPtr()) {}

template<class T>
const ft::iterator<T>&	ft::iterator<T>::operator=(const iterator& it)
{
	this->_ptr = it.getPtr();
	return *this;
}

template<class T>
T*	ft::iterator<T>::getPtr() const
{
	return this->_ptr;
}

template<class T>
bool	ft::iterator<T>::operator==(const iterator& it) const
{
	return (*(this->_ptr) == *it);
}
