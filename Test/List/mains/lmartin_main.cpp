/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmartin_main.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 04:32:26 by lmartin           #+#    #+#             */
/*   Updated: 2021/01/15 17:22:45 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIST_UC.HPP"
#include <list>

/*
** This is a minimal set of ANSI/VT100 color codes
*/
# define _END			"\x1b[0m"
# define _BOLD			"\x1b[1m"
# define _UNDER			"\x1b[4m"
# define _REV			"\x1b[7m"

/*
** Colors
*/
# define _GREY			"\x1b[30m"
# define _RED			"\x1b[31m"
# define _GREEN			"\x1b[32m"
# define _YELLOW		"\x1b[33m"
# define _BLUE			"\x1b[34m"
# define _PURPLE		"\x1b[35m"
# define _CYAN			"\x1b[36m"
# define _WHITE			"\x1b[37m"

/*
** Inverted, i.e. colored backgrounds
*/
# define _IGREY			"\x1b[40m"
# define _IRED			"\x1b[41m"
# define _IGREEN		"\x1b[42m"
# define _IYELLOW		"\x1b[43m"
# define _IBLUE			"\x1b[44m"
# define _IPURPLE		"\x1b[45m"
# define _ICYAN			"\x1b[46m"
# define _IWHITE		"\x1b[47m"

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

template <class T>
void	print(list<list<T> >& lst)
{
	for (typename list<list<T> >::iterator it = lst.begin(); it != lst.end(); it++)
	{
		for (typename list<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
			cout << *it2 << ' ';
		cout << '\n';
	}
}

template <class T>
void	print(list<T>& lst)
{
	for (typename list<T>::iterator it = lst.begin(); it != lst.end(); it++)
		cout << *it << ' ';
	cout << '\n';
}

template <class T>
void	error_diff(list<T> mylist, list<T> list)
{
	cout << "ERROR - DIFF" << std::endl;
	cout << "mylist.empty(): " << mylist.empty() << std::endl;
	cout << "list.empty(): " << list.empty() << std::endl;
	cout << "mylist.size(): " << mylist.size() << std::endl;
	cout << "list.size(): " << list.size() << std::endl;
	cout << "mylist : ";
	print(mylist);
	cout << "list : ";
	print(list);
}

template <class T>
void	compareList(string function, list<T> mylist, list<T> ft_list)
{
	print(ft_list);
	print(mylist);
	cout << function << ": ";
	if (mylist.empty() != ft_list.empty())
		error_diff(mylist, ft_list);
	else if (mylist.size() != ft_list.size())
		error_diff(mylist, ft_list);
	else
	{
		typename list<T>::iterator my_it;
		typename list<T>::iterator	i;
		my_it = mylist.begin();
		i = ft_list.begin();
		while (i != ft_list.end())
		{
			if (*i != *my_it)
			{
				error_diff(mylist, ft_list);
				return ;
			}
			i++;
			my_it++;
		}
		cout << _GREEN << "OK " << _END;
		print(mylist);
	}
}

int	main(void)
{
	cout << _WHITE << "# test_list" << _END << std::endl;
	cout << _YELLOW <<  "/* ********************************************************************** */" << std::endl;
	cout << "/*                          "<< _WHITE << "BASIC TESTS" << _YELLOW << "                                   */" << std::endl;
	cout << "/* ********************************************************************** */" << _END << std::endl;
	cout << std::endl;
	list<int> mylist;
	list<int> ft_list;

	cout << "list<" << _PURPLE << "int" << _END << "> mylist = list<" << _PURPLE << "int" << _END << ">();" << std::endl;
	cout << "list<" << _PURPLE << "int" << _END << "> list = list<" << _PURPLE << "int" << _END << ">();" << std::endl;
	cout << std::endl;

	cout << "list.max_size(): " << ft_list.max_size() << std::endl;
	cout << "mylist.max_size(): " << mylist.max_size() << std::endl;
	cout << std::endl;

	compareList("list.empty()", mylist, ft_list);
	compareList("list.size()", mylist, ft_list);

	//list.pop_back(); --> if empty list segfault
	// mylist.pop_back();
	compareList("list.pop_back()", mylist, ft_list);
	//list.pop_front(); --> if empty list segfault
	// mylist.pop_front();
	compareList("list.pop_front()", mylist, ft_list);

	for(int i = 0; i < 5; i++)
	{
		ft_list.push_back(i);
		mylist.push_back(i);
		string thing = "list.push_back(" + to_string(i) + ")";
		compareList(thing, mylist, ft_list);
	}
	
	compareList("list.empty()", mylist, ft_list);
	compareList("list.size()", mylist, ft_list);

	ft_list.push_front(-1);
	mylist.push_front(-1);
	compareList("list.push_front(-1)", mylist, ft_list);

	ft_list.pop_back();
	mylist.pop_back();
	compareList("list.pop_back()", mylist, ft_list);

	ft_list.pop_back();
	mylist.pop_back();
	ft_list.pop_back();
	mylist.pop_back();
	ft_list.pop_back();
	mylist.pop_back();
	ft_list.pop_back();
	mylist.pop_back();
	ft_list.pop_back();
	mylist.pop_back();
	compareList("list.pop_back() x5", mylist, ft_list);

	//list.pop_back(); --> if empty list segfault
	// mylist.pop_back();
	compareList("list.pop_back()", mylist, ft_list);

	ft_list.assign((size_t)10, 6);
	mylist.assign((size_t)10, 6);
	compareList("list.assign(10, 6)", mylist, ft_list);

	ft_list.pop_front();
	mylist.pop_front();
	compareList("list.pop_front()", mylist, ft_list);
	
	ft_list.unique();
	mylist.unique();
	compareList("list.unique()", mylist, ft_list);
	
	ft_list.clear();
	mylist.clear();
	compareList("list.clear()", mylist, ft_list);

	cout << _YELLOW <<  "/* ********************************************************************** */" << std::endl;
	cout << "/*                        "<< _WHITE << "ADVANCED TESTS" << _YELLOW << "                                  */" << std::endl;
	cout << "/* ********************************************************************** */" << _END << std::endl;
	cout << std::endl;
	int n;

	cout << _WHITE << "// EMPTY LIST" << _END << std::endl;
	ft_list.reverse();
	mylist.reverse();
	compareList("list.reverse()", mylist, ft_list);
	ft_list.sort();
	mylist.sort();
	compareList("list.sort()", mylist, ft_list);
	ft_list.remove(-1);
	mylist.remove(-1);
	compareList("list.remove(-1)", mylist, ft_list);

	cout << _WHITE << "// 1 ELEMENT LIST" << _END << std::endl;
	srand(time(NULL));
	ft_list.push_back(-1);
	mylist.push_back(-1);
	compareList("list.push_back(-1)", mylist, ft_list);
	ft_list.reverse();
	mylist.reverse();
	compareList("list.reverse()", mylist, ft_list);
	ft_list.sort();
	mylist.sort();
	compareList("list.sort()", mylist, ft_list);
	ft_list.remove(-1);
	mylist.remove(-1);
	compareList("list.remove(-1)", mylist, ft_list);
	cout << _WHITE << "// MULTIPLE ELEMENTS LIST" << _END << std::endl;
	for(int i = 0; i < 5; i++)
	{
		n = rand() % 1000;
		ft_list.push_back(n);
		mylist.push_back(n);
		string thing = "list.push_back(" + to_string(n) + ")";
		compareList(thing, mylist, ft_list);
	}
	ft_list.sort();
	mylist.sort();
	compareList("list.sort()", mylist, ft_list);

	mylist.sort();
	compareList("list.sort()", mylist, ft_list);

	ft_list.sort(std::greater<int>());
	mylist.sort(std::greater<int>());
	compareList("list.sort(std::greater<int>())", mylist, ft_list);

	ft_list.reverse();
	mylist.reverse();
	compareList("list.reverse()", mylist, ft_list);
	ft_list.remove(n);
	mylist.remove(n);
	compareList("list.remove(" + to_string(n) + ")", mylist, ft_list);
	ft_list.remove(-1);
	mylist.remove(-1);
	compareList("list.remove(-1)", mylist, ft_list);


	list<int> mylist2 = list<int>((size_t)5, 500);
	list<int> list2 = list<int>((size_t)5, 500);
	
	cout << "list<" << _PURPLE << "int" << _END << "> mylist2 = list<" << _PURPLE << "int" << _END << ">(5, 500);" << std::endl;
	cout << "list<" << _PURPLE << "int" << _END << "> list2 = list<" << _PURPLE << "int" << _END << ">(5, 500);" << std::endl;
	cout << std::endl;

	ft_list.swap(list2);
	mylist.swap(mylist2);
	compareList("list.swap(list2)", mylist, ft_list);
	ft_list.resize(10, 6);
	mylist.resize(10, 6);
	compareList("list.resize(10, 6)", mylist, ft_list);
	ft_list.resize(1);
	mylist.resize(1);
	compareList("list.resize(1)", mylist, ft_list);
	ft_list.resize(0);
	mylist.resize(0);
	compareList("list.resize(0)", mylist, ft_list);
	ft_list.merge(list2);
	mylist.merge(mylist2);
	compareList("list.merge(list2)", mylist, ft_list);
	ft_list.resize(3, 6);
	mylist.resize(3, 6);
	compareList("list.resize(3, 6)", mylist, ft_list);
	ft_list.merge(list2);
	mylist.merge(mylist2);
	compareList("list.merge(list2)", mylist, ft_list);
	swap<int>(mylist, mylist2);
	swap<int>(ft_list, list2);
	compareList("swap(list, list2)", mylist, ft_list);
	swap<int>(mylist, mylist2);
	swap<int>(ft_list, list2);
	compareList("swap(list, list2)", mylist, ft_list);
	mylist2 = mylist;
	list2 = ft_list;
	compareList("mylist2 = mylist", mylist2, list2);

	return 0;
}
