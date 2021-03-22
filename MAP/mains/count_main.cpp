/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/18 16:05:27 by hbaudet          ###   ########.fr       */
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
  char c;

  mymap ['a']=101;
  cout << "assigned 'a'\n";
  mymap ['c']=202;
  cout << "assiged 'c'\n";
  mymap ['f']=303;
  cout << "assigned 'f'\n";

	cout << "end of assignations\n";
  for (c='a'; c<'h'; c++)
  {
    cout << c;
    if (mymap.count(c)>0)
      cout << " is an element of mymap.\n";
    else 
      cout << " is not an element of mymap.\n";
  }

  return 0;
}
