/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/18 16:03:50 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"
#include "LIST_UC.HPP"
#include <list>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

template <class T>
void	print(list<list<T> >& lst)
{
	for (typename list<list<T> >::iterator it = lst.begin(); it != lst.end(); it++)
	{
		for (typename list<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
			cout << *it2 << ' ';
		cout << '\n';
	}
}

template <class T>
void	print(list<T>& lst)
{
	for (typename list<T>::iterator it = lst.begin(); it != lst.end(); it++)
		cout << *it << ' ';
	cout << '\n';
}

int main ()
{
  list<int> myints;
  cout << "0. size: " << myints.size() << '\n';

  for (int i=0; i<10; i++) myints.push_back(i);
  cout << "1. size: " << myints.size() << '\n';

  myints.insert (myints.begin(),10,100);
  cout << "2. size: " << myints.size() << '\n';

  myints.pop_back();
  cout << "3. size: " << myints.size() << '\n';

  return 0;
}
