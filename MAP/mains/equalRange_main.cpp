/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equalRange_main.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/19 10:01:55 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"
#include "MAP_UC.HPP"
#include <map>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

template <class Key, class T>
void	print(map<Key, T>& lst)
{
	for (typename map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		cout << it->first << " => " << it->second << '\n';
}

int main ()
{
  map<char,int> mymap;

  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;

  pair<map<char,int>::iterator,map<char,int>::iterator> ret;
  ret = mymap.equal_range('b');

  cout << "lower bound points to: ";
  cout << ret.first->first << " => " << ret.first->second << '\n';

  cout << "upper bound points to: ";
  cout << ret.second->first << " => " << ret.second->second << '\n';

  return 0;
}
