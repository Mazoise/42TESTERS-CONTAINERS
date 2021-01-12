/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popFront_main.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/12 14:25:56 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
  deque<int> mydeque;

  mydeque.push_back (100);
  mydeque.push_back (200);
  mydeque.push_back (300);

  cout << "Popping out the elements in mydeque:";
  while (!mydeque.empty())
  {
    cout << ' ' << mydeque.front();
    mydeque.pop_front();
  }

  cout << "\nThe final size of mydeque is " << int(mydeque.size()) << '\n';

  return 0;
}