/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator=_main.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/20 10:24:27 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"
#include "SET_UC.HPP"
#include <set>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

template <class T>
void	print(set<T>& lst)
{
	for (typename set<T>::iterator it = lst.begin(); it != lst.end(); it++)
		cout << it->first << " => " << it->second << '\n';
}

int main ()
{
  int myints[]={ 12,82,37,64,15 };
  set<int> first (myints,myints+5);   // set with 5 ints
  set<int> second;                    // empty set

  second = first;                          // now second contains the 5 ints
  first = set<int>();                 // and first is empty

  cout << "Size of first: " << int (first.size()) << '\n';
  cout << "Size of second: " << int (second.size()) << '\n';
  return 0;
}
