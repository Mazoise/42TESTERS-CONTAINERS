/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:07:47 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/06 13:21:54 by hbaudet          ###   ########.fr       */
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
	pair<string, int>	my_pair("salut", 42);
	map<string, int>	test;

	test.insert(my_pair);
	test.insert(pair<string, int>("truc", 45));
	test.insert(pair<string, int>("machin", 78));
	test.insert(pair<string, int>("foo", 413));
	test.insert(pair<string, int>("bar", 02));
	test.insert(pair<string, int>("Marcel", 746));

	map<string, int>::iterator	it;

	it = test.begin();

	while (it != test.end())
	{
		cout << it->first << ", " << it->second << '\n';
		it++;
	}
}