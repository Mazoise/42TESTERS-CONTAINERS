/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nonMemberSwap_main.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/12 14:05:24 by hbaudet          ###   ########.fr       */
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
  map<char,int> foo,bar;

  foo['x']=100;
  foo['y']=200;

  bar['a']=11;
  bar['b']=22;
  bar['c']=33;

  swap(foo,bar);

  cout << "foo contains:\n";
  for (map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    cout << it->first << " => " << it->second << '\n';

  cout << "bar contains:\n";
  for (map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    cout << it->first << " => " << it->second << '\n';

  return 0;
}