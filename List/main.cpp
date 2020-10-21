/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:03:48 by hbaudet           #+#    #+#             */
/*   Updated: 2020/10/21 19:17:05 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "List.hpp"
#include <list>
#include <iterator>
#include <iostream>
#include <string>


int main()
{
//	std::List<int> i;

//	i.push_back(5);

	std::list<int>	li;
	std::list<int>	lst(5, 0);
	std::list<std::string>	test;
	
	li.push_back(7);
	li.push_back(9);
	li.push_back(456);
	li.push_back(45);
	li.push_back(42);

	std::list<int>::iterator	it = li.begin();
	std::list<int>::iterator	ti = li.end();

	ti--;
	ti--;
	std::cout << *(++it) << '\n';

	std::cout << "List<int> max size : " << li.max_size() << '\n';
	std::cout << "List<string> max size : " << test.max_size() << '\n';

	while (*it != 42)
	{
		if (*it == *ti)
			std::cout << "Reached n - 1 elem\n";
		it++;
	}
	

	std::cout << *it << '\n';
	std::cout << *ti << '\n';

	return 0;
}
