/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/18 16:42:59 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <queue>
#include "test_utils.hpp"
#include "QUEUE_UC.HPP"
#include "LIST_UC.HPP"

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

template <class T>
void	print(queue<queue<T> >& lst)
{
	for (typename queue<queue<T> >::iterator it = lst.begin(); it != lst.end(); it++)
	{
		for (typename queue<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
			cout << *it2 << ' ';
		cout << '\n';
	}
}

template <class T>
void	print(queue<T>& lst)
{
	for (typename queue<T>::iterator it = lst.begin(); it != lst.end(); it++)
		cout << *it << ' ';
	cout << '\n';
}

int main ()
{
  queue<int> myints;
  cout << "0. size: " << myints.size() << '\n';

  for (int i=0; i<5; i++) myints.push(i);
  cout << "1. size: " << myints.size() << '\n';

  myints.pop();
  cout << "2. size: " << myints.size() << '\n';

  return 0;
}
