/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/18 16:05:30 by hbaudet          ###   ########.fr       */
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


	if (mymap.begin() != mymap.end())
		cout << "This should not happen\n";

  mymap['b'] = 100;
  mymap['a'] = 200;
  mymap['c'] = 300;

	if (mymap.begin() == mymap.end())
		cout << "This is wrong\n";
  // show content:
  for (map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); it++)
    cout << it->first << " => " << it->second << '\n';

	cout << "Hello there\n";
	for (map<char,int>::const_iterator it=mymap.begin(); it!=mymap.end(); it++)
    cout << it->first << " => " << it->second << '\n';
	cout << "General Kenobi\n";

	map<char, int>::const_iterator it = mymap.begin();
	map<char, int>::const_iterator ti = mymap.end();
	cout << "Wupwup\n";

	it++;
	++it;
	it--;
	--it;
	cout << "marker1\n";

	ti--;
	--ti;
	++ti;
	ti++;

	ti = it;

	cout << "Trump is a kiddo\n";
	map<char, int>::iterator end = mymap.end();
	while(it != end)
	{
    	cout << it->first << " => " << it->second << '\n';
		it++;
	}

  return 0;
}
