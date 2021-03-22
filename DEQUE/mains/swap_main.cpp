/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/18 16:01:10 by hbaudet          ###   ########.fr       */
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
  unsigned int i;
  deque<int> foo (3,100);   // three ints with a value of 100
  deque<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  cout << "foo contains:";
  for (deque<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
    cout << ' ' << *it;
  cout << '\n';

  cout << "bar contains:";
  for (deque<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
    cout << ' ' << *it;
  cout << '\n';

  return 0;
}
