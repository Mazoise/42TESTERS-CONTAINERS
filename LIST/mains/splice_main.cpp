/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splice_main.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/18 16:03:45 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"
#include "LIST_UC.HPP"
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
	}
	{
		list<int> mylist1, mylist2;
		list<int>::iterator it;

		// set some initial values:
		for (int i=1; i<=4; ++i)
			mylist1.push_back(i);      // mylist1: 1 2 3 4

		for (int i=1; i<=3; ++i)
			mylist2.push_back(i*10);   // mylist2: 10 20 30

		it = mylist1.begin();
		++it;                         // points to 2

		mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
										// mylist2 (empty)
										// "it" still points to 2 (the 5th element)
												
		mylist2.splice (mylist2.begin(),mylist1, it);
										// mylist1: 1 10 20 30 3 4
										// mylist2: 2
										// "it" is now invalid.
		it = mylist1.begin();
		for (int i = 0; i < 3; i++)
			it++;        				 // "it" points now to 30

		mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
										// mylist1: 30 3 4 1 10 20

		cout << "mylist1 contains:";
		for (it=mylist1.begin(); it!=mylist1.end(); ++it)
			cout << ' ' << *it;
		cout << '\n';

		cout << "mylist2 contains:";
		for (it=mylist2.begin(); it!=mylist2.end(); ++it)
			cout << ' ' << *it;
		cout << '\n';
	}
	
	return (0);
}
