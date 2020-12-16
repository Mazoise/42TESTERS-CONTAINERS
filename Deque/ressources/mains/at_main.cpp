/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at_main.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2020/12/16 15:02:45 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Deque.hpp"
#include <deque>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

template <class T>
void	print(deque<deque<T> >& lst)
{
	for (typename deque<deque<T> >::iterator it = lst.begin(); it != lst.end(); it++)
	{
		for (typename deque<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
			cout << *it2 << ' ';
		cout << '\n';
	}
}

template <class T>
void	print(deque<T>& lst)
{
	for (typename deque<T>::iterator it = lst.begin(); it != lst.end(); it++)
		cout << *it << ' ';
	cout << '\n';
}

int main()
{
	deque<float>	one;

	for (float i = 0.0f; i < 15.f; i++)
		one.push_back(i * 42.0f / 37.0f);
	
	print(one);

	cout << one[4] << '\n';
	cout << one[0] << '\n';
	cout << one[6] << '\n';
	cout << one[9] << '\n';
//	cout << one[155555] << '\n'; // will crash

	try {
		cout << one.at(15) << '\n';
	}
	catch(std::exception e) { e.what(); }

	return (0);
}