/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_main.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/20 11:06:29 by hbaudet          ###   ########.fr       */
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
void	print(list<T>& lst)
{
	for (typename list<T>::iterator it = lst.begin(); it != lst.end(); it++)
		cout << *it << ' ';
	cout << '\n';
}

int main ()
{
  list<int> first;
  list<int> second;

  first.assign (7,100);                      // 7 ints with value 100
  print(first);

  second.assign (first.begin(), first.end()); // a copy of first
  print(second);

  int myints[]={1776,7,4};
  first.assign (myints,myints+3);            // assigning from array
  print(first);

  cout << "Size of first: " << int (first.size()) << '\n';
  cout << "Size of second: " << int (second.size()) << '\n';
  return 0;
}
