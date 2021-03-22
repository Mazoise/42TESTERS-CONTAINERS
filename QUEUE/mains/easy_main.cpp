/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:40:31 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/18 16:06:28 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "QUEUE_UC.HPP"
#include "test_utils.hpp"
#include "LIST_UC.HPP"
#include <list>
#include <queue>
#include <string>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

int main()
{
	queue<float>								other_queue;
	list<std::string>						lst;

	lst.push_back("salut");
	lst.push_back("tu vas bien?");
	lst.push_back("super");
	lst.push_back("et toi?");

	queue<std::string, list<std::string> >	my_queue(lst);

	std::cout << std::boolalpha << other_queue.empty() << std::endl;
	other_queue.push(8.5);
	other_queue.push(42.4242);
	std::cout << other_queue.size() << '\n';
	other_queue.pop();
	std::cout << other_queue.size() << '\n';
	other_queue.push(78541.987);
	std::cout << other_queue.size() << '\n';
	std::cout << other_queue.front() << '\n';
	std::cout << other_queue.back() << '\n';
	std::cout << std::boolalpha << other_queue.empty() << std::endl;
	std::cout << std::boolalpha << other_queue.empty() << std::endl;

	my_queue.push("8.5");
	my_queue.push("42.4242");
	std::cout << my_queue.size() << '\n';
	my_queue.pop();
	std::cout << my_queue.size() << '\n';
	my_queue.push("78541.987");
	std::cout << my_queue.size() << '\n';
	std::cout << my_queue.front() << '\n';
	std::cout << my_queue.back() << '\n';
	std::cout << std::boolalpha << my_queue.empty() << std::endl;

	const std::string const_front = my_queue.front();
	const std::string const_back = my_queue.back();

	std::cout << "const front: " << const_front << '\n';
	std::cout << "const back: " << const_back << '\n';

	while (!my_queue.empty())
	{
		std::cout << my_queue.front() << '\n';
		my_queue.pop();
	}

	return (0);
}
