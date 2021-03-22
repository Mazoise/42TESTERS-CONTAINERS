/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/20 12:30:44 by hbaudet          ###   ########.fr       */
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
  queue<int> myqueue;
  int myint = 42;

  do {
    myint += 76;
	myint /= 3;
	myint *= 4;
    myqueue.push (myint);
  } while (myint < 10000);

  cout << "myqueue contains: ";
  while (!myqueue.empty())
  {
    cout << ' ' << myqueue.front();
    myqueue.pop();
  }
  cout << '\n';

  return 0;
}
