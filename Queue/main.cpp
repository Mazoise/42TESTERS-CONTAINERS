/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:40:31 by hbaudet           #+#    #+#             */
/*   Updated: 2020/12/08 12:55:54 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Queue.hpp"
#include <list>

int main()
{
	ft::queue<float>								other_queue;
	std::list<std::string>							lst;

	lst.push_back("salut");
	lst.push_back("tu vas bien?");
	lst.push_back("super");
	lst.push_back("et toi?");

	ft::queue<std::string, std::list<std::string> >	my_queue(lst);

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

	while (!my_queue.empty())
	{
		std::cout << my_queue.front() << '\n';
		my_queue.pop();
	}

	return (0);
}
