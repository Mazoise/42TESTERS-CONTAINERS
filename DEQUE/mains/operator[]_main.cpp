/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator[]_main.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/18 16:01:47 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"
#include "DEQUE_UC.HPP"
#include <deque>
#include <vector>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

template <class T>
void	print(deque<deque<T> >& lst)
{
	for (typename deque<deque<T> >::iterator it = lst.begin(); it != lst.end(); it++)
	{
		for (typename deque<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
			cout << *it2 << ' ';
		cout << '\n';
	}
}

template <class T>
void	print(deque<T>& lst)
{
	for (typename deque<T>::iterator it = lst.begin(); it != lst.end(); it++)
		cout << *it << ' ';
	cout << '\n';
}

int main ()
{
  deque<int> mydeque (10);   // 10 zero-initialized elements
  deque<int>::size_type sz = mydeque.size();

  // assign some values:
  for (unsigned i=0; i<sz; i++) mydeque[i]=i;

  // reverse order of elements using operator[]:
  for (unsigned i=0; i<sz/2; i++)
  {
    int temp;
    temp = mydeque[sz-1-i];
    mydeque[sz-1-i]=mydeque[i];
    mydeque[i]=temp;
  }

  // print content:
  cout << "mydeque contains:";
  for (unsigned i=0; i<sz; i++)
    cout << ' ' << mydeque[i];
  cout << '\n';

  return 0;
}
