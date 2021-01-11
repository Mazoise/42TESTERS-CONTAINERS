/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:07:47 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/11 17:53:04 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "MAP_UC.HPP"
#include "Map.hpp"
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
		cout << *it << ' ';
	cout << '\n';
}

int main()
{
	pair<int, string>			my_pair(8, "salut");
	map<int, string>			test;
	map<int, string>::iterator	it;

	test.insert(my_pair);
	test.insert(pair<int, string>(-4, "bar"));
	test.insert(pair<int, string>(2, "machin"));
	test.insert(pair<int, string>(3, "foo"));
	test.insert(pair<int, string>(746, "Marcel"));
	test.insert(pair<int, string>(1, "truc"));
	it = test.begin();
	cout << '\n';

	while (it != test.end())
	{
		cout << it->first << ", " << it->second << '\n';
		it++;
		cout << "iterator incremented\n";
		cout << it.getPointer() << '\n';
		cout << test.end().getPointer() << '\n';
	}
	cout << "End of display loop\n";
}