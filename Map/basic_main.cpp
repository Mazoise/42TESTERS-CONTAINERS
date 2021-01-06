/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:07:47 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/06 17:50:49 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Map.hpp"

#ifdef STD
# define NAMESPACE std
#else
# define NAMESPACE ft
#endif

using namespace NAMESPACE;

int main()
{
	pair<int, string>	my_pair(-4, "salut");
	map<int, string>	test;
	map<int, string>::iterator	it;

	test.insert(my_pair);
	it = test.begin();
	cout << '\n';
	while (it != test.end())
	{
		cout << it->first << ", " << it->second << '\n';
		it++;
	}
	test.insert(pair<int, string>(1, "truc"));
	it = test.begin();
	cout << '\n';
	while (it != test.end())
	{
		cout << it->first << ", " << it->second << '\n';
		it++;
	}
	test.insert(pair<int, string>(2, "machin"));
	it = test.begin();
	cout << '\n';
	while (it != test.end())
	{
		cout << it->first << ", " << it->second << '\n';
		it++;
	}
	test.insert(pair<int, string>(3, "foo"));
	it = test.begin();
	cout << '\n';
	while (it != test.end())
	{
		cout << it->first << ", " << it->second << '\n';
		it++;
	}
	test.insert(pair<int, string>(8, "bar"));
	it = test.begin();
	cout << '\n';
	while (it != test.end())
	{
		cout << it->first << ", " << it->second << '\n';
		it++;
	}
	test.insert(pair<int, string>(746, "Marcel"));
	it = test.begin();
	cout << '\n';
	while (it != test.end())
	{
		cout << it->first << ", " << it->second << '\n';
		it++;
	}

	cout << "==================\n";
	cout << test._begin.parent->getMember().first << '\n';

	my_pair.pair<int, string>::~pair();
	test.map<int, string>::~map();
	cout << "\n\nWhile(1)\ntest leaks\n";
	// while(1);
}