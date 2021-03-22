/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbegin_main.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/18 16:05:10 by hbaudet          ###   ########.fr       */
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

  mymap['x'] = 100;
  mymap['y'] = 200;
  mymap['z'] = 300;

  // show content:
  map<char,int>::reverse_iterator rit;
  for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
    cout << rit->first << " => " << rit->second << '\n';


	for (map<char,int>::const_reverse_iterator it=mymap.rbegin(); it!=mymap.rend(); it++)
    cout << it->first << " => " << it->second << '\n';

	map<char, int>::const_reverse_iterator it = mymap.rbegin();
	map<char, int>::const_reverse_iterator ti = mymap.rend();

	it++;
	++it;
	it--;
	--it;

	ti--;
	--ti;
	++ti;
	ti++;

	ti = it;

	map<char, int>::reverse_iterator end = mymap.rend();
	while(it != end)
	{
    	cout << it->first << " => " << it->second << '\n';
		it++;
	}


  return 0;
}
