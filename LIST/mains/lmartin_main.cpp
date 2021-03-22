/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmartin_main.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 04:32:26 by lmartin           #+#    #+#             */
/*   Updated: 2021/01/20 13:23:55 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"
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


int	main(void)
{
	cout << _WHITE << "# test_list" << _END << std::endl;
	cout << _YELLOW <<  "/* ********************************************************************** */" << std::endl;
	cout << "/*                          "<< _WHITE << "BASIC TESTS" << _YELLOW << "                                   */" << std::endl;
	cout << "/* ********************************************************************** */" << _END << std::endl;
	cout << std::endl;
	list<int> mylist;

	cout << "list<" << _PURPLE << "int" << _END << "> mylist = list<" << _PURPLE << "int" << _END << ">();" << std::endl;
	cout << std::endl;

	cout << "mylist.max_size(): " << (mylist.max_size() > 10000) << std::endl;
	cout << std::endl;

	//list.pop_back(); --> if empty list segfault
	// mylist.pop_back();
	//list.pop_front(); --> if empty list segfault
	// mylist.pop_front();

	print(mylist);

	for(int i = 0; i < 5; i++)
	{
		mylist.push_back(i);
	print(mylist);
	}
	

	mylist.push_front(-1);
	print(mylist);

	mylist.pop_back();
	print(mylist);

	mylist.pop_back();
	print(mylist);
	mylist.pop_back();
	print(mylist);
	mylist.pop_back();
	print(mylist);
	mylist.pop_back();
	print(mylist);
	mylist.pop_back();
	print(mylist);

	//list.pop_back(); --> if empty list segfault
	// mylist.pop_back();

	mylist.assign((size_t)10, 6);

	print(mylist);
	mylist.pop_front();
	
	print(mylist);
	mylist.unique();
	
	print(mylist);
	mylist.clear();

	cout << _YELLOW <<  "/* ********************************************************************** */" << std::endl;
	cout << "/*                        "<< _WHITE << "ADVANCED TESTS" << _YELLOW << "                                  */" << std::endl;
	cout << "/* ********************************************************************** */" << _END << std::endl;
	cout << std::endl;
	int n;

	cout << _WHITE << "// EMPTY LIST" << _END << std::endl;
	print(mylist);
	cout << _WHITE << "reverse" << _END << std::endl;
	mylist.reverse();
	print(mylist);
	cout << _WHITE << "sort" << _END << std::endl;
	mylist.sort();
	print(mylist);
	cout << _WHITE << "remove -1" << _END << std::endl;
	mylist.remove(-1);

	cout << _WHITE << "// 1 ELEMENT LIST" << _END << std::endl;
	print(mylist);
	mylist.push_back(-1);
	print(mylist);
	mylist.reverse();
	print(mylist);
	mylist.sort();
	print(mylist);
	mylist.remove(-1);
	cout << _WHITE << "// MULTIPLE ELEMENTS LIST" << _END << std::endl;
	for(int i = 0; i < 5; i++)
	{
		n = (i * 6578 + 56) + 3 * i / 4 - 6 + i;
	print(mylist);
		mylist.push_back(n);
	}
	print(mylist);
	mylist.sort();

	print(mylist);
	mylist.sort();

	print(mylist);
	mylist.sort(std::greater<int>());

	print(mylist);
	mylist.reverse();
	print(mylist);
	mylist.remove(n);
	print(mylist);
	mylist.remove(-1);


	list<int> mylist2 = list<int>((size_t)5, 500);
	
	cout << "list<" << _PURPLE << "int" << _END << "> mylist2 = list<" << _PURPLE << "int" << _END << ">(5, 500);" << std::endl;
	cout << "list<" << _PURPLE << "int" << _END << "> list2 = list<" << _PURPLE << "int" << _END << ">(5, 500);" << std::endl;
	cout << std::endl;

	print(mylist);
	print(mylist2);
	mylist.swap(mylist2);
	print(mylist);
	print(mylist2);
	mylist.resize(10, 6);
	print(mylist);
	print(mylist2);
	mylist.resize(1);
	print(mylist);
	print(mylist2);
	mylist.resize(0);
	print(mylist);
	print(mylist2);
	mylist.merge(mylist2);
	print(mylist);
	print(mylist2);
	mylist.resize(3, 6);
	print(mylist);
	print(mylist2);
	mylist.merge(mylist2);
	print(mylist);
	print(mylist2);
	swap<int>(mylist, mylist2);
	print(mylist);
	print(mylist2);
	swap<int>(mylist, mylist2);
	print(mylist);
	print(mylist2);
	mylist2 = mylist;
	print(mylist);
	print(mylist2);

	return 0;
}
