/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyComp_main.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/12 17:46:01 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

  map<char,int>::key_compare mycomp = mymap.key_comp();

  mymap['a']=100;
  mymap['b']=200;
  mymap['c']=300;

  cout << "mymap contains:\n";

  char highest = mymap.rbegin()->first;     // key value of last element

  map<char,int>::iterator it = mymap.begin();
  do {
    cout << it->first << " => " << it->second << '\n';
  } while ( mycomp((*it++).first, highest) );

  cout << '\n';

  return 0;
}