/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:03:48 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/18 16:02:03 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"
#include "DEQUE_UC.HPP"
#include <deque>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

int main()
{
//	Deque<int> i;

//	i.push_back(5);

	deque<int>	li;
	deque<int>	lst(5, 0);
	deque<string>	test;
	
	li.push_back(7);
	li.push_back(9);
	li.push_back(456);
	li.push_back(45);
	li.push_back(42);

	deque<int>::iterator	it = li.begin();
	deque<int>::iterator	ti = li.end();

	ti--;
	ti--;
	cout << *(++it) << '\n';


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

	for (deque<int>::iterator iter = lst.begin(); iter != lst.end(); iter++)
		cout << *iter << ' ';
	cout << '\n';

	return 0;
}
