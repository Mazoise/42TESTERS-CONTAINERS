/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at_main.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/18 16:02:33 by hbaudet          ###   ########.fr       */
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

	}
	{
		deque<unsigned> mydeque (10);   // 10 zero-initialized unsigneds

		// assign some values:
		for (unsigned i=0; i<mydeque.size(); i++)
			mydeque.at(i)=i;

		cout << "mydeque contains:";
		for (unsigned i=0; i<mydeque.size(); i++)
			cout << ' ' << mydeque.at(i);

		cout << '\n';

		return 0;
	}
}
