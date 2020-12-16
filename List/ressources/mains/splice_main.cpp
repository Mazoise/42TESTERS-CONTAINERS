/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splice_main.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2020/12/16 14:44:22 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "List.hpp"
#include <list>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

template <class T>
void	print(list<T>& lst)
{
	for (typename list<T>::iterator it = lst.begin(); it != lst.end(); it++)
		cout << *it << " ";
	cout << '\n';
}

int main()
{
	list<int>	one(5, 42);
	list<int>	two(one);
	list<int>	three(two.begin(), two.end());

	print(one);
	print(two);
	print(three);
	cout << one.size() << '\n';
	cout << two.size() << '\n';
	cout << three.size() << '\n';

	one.push_back(48);
	one.push_back(5);
	one.push_back(1);
	one.push_back(896475);
	print(one);
	print(two);
	print(three);
	cout << one.size() << '\n';
	cout << two.size() << '\n';
	cout << three.size() << '\n';

	two.push_back(1654);
	two.push_back(0);
	two.push_back(-9);
	two.push_back(8666);
	print(one);
	print(two);
	print(three);
	cout << one.size() << '\n';
	cout << two.size() << '\n';
	cout << three.size() << '\n';

	list<int>::iterator	it;
	list<int>::iterator rev;

	it = one.begin();

	it++;
	it++;

	three.splice(++(three.begin()), one, it);
	print(one);
	print(two);
	print(three);
	cout << one.size() << '\n';
	cout << two.size() << '\n';
	cout << three.size() << '\n';

	rev = one.end();
	rev--;
	rev--;
	rev--;
	rev--;

	three.splice(three.end(), one, ++(one.begin()), rev);
	print(one);
	print(two);
	print(three);

	three.splice(three.begin(), two, two.begin(), two.end());
	print(one);
	print(two);
	print(three);
	cout << one.size() << '\n';
	cout << two.size() << '\n';
	cout << three.size() << '\n';

	
	return (0);
}
