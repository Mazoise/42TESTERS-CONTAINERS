/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:03:48 by hbaudet           #+#    #+#             */
/*   Updated: 2020/12/10 14:54:57 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "List.hpp"
#include <list>
#include <iterator>
#include <iostream>
#include <string>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

int main()
{
//	List<int> i;

//	i.push_back(5);

	list<int>	li;
	list<int>	lst(5, 0);
	list<string>	test;
	
	li.push_back(7);
	li.push_back(9);
	li.push_back(456);
	li.push_back(45);
	li.push_back(42);

	list<int>::iterator	it = li.begin();
	list<int>::iterator	ti = li.end();

	ti--;
	ti--;
	cout << *(++it) << '\n';

	cout << "List<int> max size : " << li.max_size() << '\n';
	cout << "List<string> max size : " << test.max_size() << '\n';

	while (*it != 42)
	{
		if (*it == *ti)
			cout << "Reached n - 1 elem\n";
		it++;
	}
	

	cout << *it << '\n';
	cout << *ti << '\n';

	li.pop_back();
	cout << *(--(li.end())) << '\n';

	for (list<int>::iterator iter = lst.begin(); iter != lst.end(); iter++)
		cout << *iter << ' ';
	cout << '\n';

	return 0;
}
