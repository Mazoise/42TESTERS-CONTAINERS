/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_main.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/18 16:04:03 by hbaudet          ###   ########.fr       */
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

// a predicate implemented as a function:
bool single_digit (const int& value) { return (value < 10); }
bool too_high (const int& value) { return (value > 2147483647); }
bool first_b (const string& value) { return (value[0] == 'b'); }

// a predicate implemented as a class:
struct is_odd {
  bool operator() (const int& value) { return (value % 2) == 1; }
};

int main()
{
	{
		list<int>	lst;


		lst.remove(42);

		lst.push_front(89);
		print(lst);
		lst.remove(0);
		print(lst);
		lst.remove(89);

		for (int i = 0; i < 8; i++)
			lst.push_back(57);

		print(lst);
		lst.remove(42);
		print(lst);

		lst.remove(57);
		print(lst);


		for (int i = 0; i < 8; i++)
			lst.push_back(456);
		for (int i = 0; i < 4; i++)
			lst.push_back(3 * i);
		for (int i = 0; i < 2; i++)
			lst.push_front(5 * i);

		print(lst);
		lst.remove(9);
		print(lst);

		lst.remove_if(single_digit);
		print(lst);
		lst.remove_if(is_odd());
		print(lst);
		lst.remove_if(too_high);
		print(lst);

		list<string>		str;

		str.remove_if(first_b);
		print(str);

		str.push_front("salut");
		str.push_front("bien");
		str.push_front("salade");
		str.push_front("beatau");
	}
	{
	int myints[]= {17,89,7,14};
	list<int> mylist (myints,myints+4);

	mylist.remove(89);

	cout << "mylist contains:";
	for (list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		cout << ' ' << *it;
	cout << '\n';

	}
	{
		int myints[]= {15,36,7,17,20,39,4,1};
		list<int> mylist (myints,myints+8);   // 15 36 7 17 20 39 4 1

		mylist.remove_if (single_digit);           // 15 36 17 20 39

		mylist.remove_if (is_odd());               // 36 20

		cout << "mylist contains:";
		for (list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			cout << ' ' << *it;
		cout << '\n';
  }

	return (0);
}
