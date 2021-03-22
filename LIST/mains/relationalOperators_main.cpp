/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relationalOperators_main.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/18 16:04:05 by hbaudet          ###   ########.fr       */
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
  list<int> a, b, c;
  a.push_back(10);
  a.push_back(20);
  a.push_back(30);

  b.push_back(10);
  b.push_back(20);
  b.push_back(30);

  c.push_back(30);
  c.push_back(20);
  c.push_back(10);

  if (a==b) cout << "a and b are equal\n";
  if (b!=c) cout << "b and c are not equal\n";
  if (b<c) cout << "b is less than c\n";
  if (c>b) cout << "c is greater than b\n";
  if (a<=b) cout << "a is less than or equal to b\n";
  if (a>=b) cout << "a is greater than or equal to b\n";

  return 0;
}
