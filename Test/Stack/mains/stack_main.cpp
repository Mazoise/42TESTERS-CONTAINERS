/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:40:31 by hbaudet           #+#    #+#             */
/*   Updated: 2020/12/18 19:30:38 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "STACK.HPP"
#include <list>
#include "LIST.HPP"
#include <stack>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

int main()
{
	stack<float>								other_stack;
	list<string>							lst;

	lst.push_back("salut");
	lst.push_back("tu vas bien?");
	lst.push_back("super");
	lst.push_back("et toi?");

	stack<string, list<string> >	my_stack(lst);

	cout << std::boolalpha << other_stack.empty() << std::endl;
	other_stack.push(8.5); // 8.5;
	other_stack.push(42.4242); // 8.5; 42.4242;
	cout << other_stack.size() << '\n'; // 2
	other_stack.pop(); // 8.5;
	cout << other_stack.size() << '\n'; // 1
	other_stack.push(78541.987); // 8.5; 78541.987;
	cout << other_stack.size() << '\n'; // 2
	cout << other_stack.top() << '\n'; //78541.987
	cout << std::boolalpha << other_stack.empty() << std::endl;

	const string const_top = my_stack.top();

	cout << "const top: " << const_top << '\n';

	while (!my_stack.empty())
	{
		cout << my_stack.top() << '\n';
		my_stack.pop();
	}


	return (0);
}