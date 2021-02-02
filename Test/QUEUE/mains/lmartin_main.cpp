/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aaalmartin_main.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/20 21:44:13 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <queue>
#include <list>
#include "test_utils.hpp"
#include "QUEUE_UC.HPP"
#include "LIST_UC.HPP"

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
void	print(queue<queue<T> >& lst)
{
	for (typename queue<queue<T> >::iterator it = lst.begin(); it != lst.end(); it++)
	{
		for (typename queue<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
			cout << *it2 << ' ';
		cout << '\n';
	}
}

template <class T>
void	print(queue<T>& lst)
{
	for (typename queue<T>::iterator it = lst.begin(); it != lst.end(); it++)
		cout << *it << ' ';
	cout << '\n';
}

int	main(void)
{
	cout << _WHITE << "# test_queue" << _END << std::endl;
	cout << _YELLOW <<  "/* ********************************************************************** */" << std::endl;
	cout << "/*                          "<< _WHITE << "BASIC TESTS" << _YELLOW << "                                   */" << std::endl;
	cout << "/* ********************************************************************** */" << _END << std::endl;
	queue<int> myqueue;

	cout << "queue<" << _PURPLE << "int" << _END << "> myqueue" << std::endl;
	cout << std::endl;


	cout << _WHITE << "# empty" << _END << std::endl;
	cout << "myqueue.empty(): " <<  myqueue.empty() << std::endl;
	cout << "myqueue.size(): " << myqueue.size() << std::endl;
	cout << _WHITE << "# one element" << _END << std::endl;
	myqueue.push(42);
	cout << "myqueue.push(42)" << std::endl;
	cout << "myqueue.empty(): " <<  myqueue.empty() << std::endl;
	cout << "myqueue.size(): " << myqueue.size() << std::endl;
	cout << "myqueue.back(): " << myqueue.back() << std::endl;
	cout << "myqueue.front(): " << myqueue.front() << std::endl;
	cout << _WHITE << "# two element" << _END << std::endl;
	myqueue.push(2);
	cout << "myqueue.push(2)" << std::endl;
	cout << "myqueue.size(): " << myqueue.size() << std::endl;
	cout << "myqueue.back(): " << myqueue.back() << std::endl;
	cout << "myqueue.front(): " << myqueue.front() << std::endl;
	cout << _WHITE << "# pop element" << _END << std::endl;
	myqueue.pop();
	cout << "myqueue.pop()" << std::endl;
	cout << "myqueue.size(): " << myqueue.size() << std::endl;
	cout << "myqueue.back(): " << myqueue.back() << std::endl;
	cout << "myqueue.front(): " << myqueue.front() << std::endl;
	cout << std::endl;

	queue<int, list<int> > myqueue2;

	cout << "queue<" << _PURPLE << "int" << _END << ", " << _PURPLE << "list" << _END << "> myqueue2" << std::endl;
	cout << std::endl;


	cout << _WHITE << "# empty" << _END << std::endl;
	cout << "myqueue2.empty(): " <<  myqueue2.empty() << std::endl;
	cout << "myqueue2.size(): " << myqueue2.size() << std::endl;
	cout << _WHITE << "# one element" << _END << std::endl;
	myqueue2.push(42);
	cout << "myqueue2.push(42)" << std::endl;
	cout << "myqueue2.empty(): " <<  myqueue2.empty() << std::endl;
	cout << "myqueue2.size(): " << myqueue2.size() << std::endl;
	cout << "myqueue.back(): " << myqueue.back() << std::endl;
	cout << "myqueue2.front(): " << myqueue2.front() << std::endl;
	cout << _WHITE << "# two element" << _END << std::endl;
	myqueue2.push(2);
	cout << "myqueue2.push(2)" << std::endl;
	cout << "myqueue2.size(): " << myqueue2.size() << std::endl;
	cout << "myqueue.back(): " << myqueue.back() << std::endl;
	cout << "myqueue2.front(): " << myqueue2.front() << std::endl;
	cout << _WHITE << "# pop element" << _END << std::endl;
	myqueue2.pop();
	cout << "myqueue2.pop()" << std::endl;
	cout << "myqueue2.size(): " << myqueue2.size() << std::endl;
	cout << "myqueue.back(): " << myqueue.back() << std::endl;
	cout << "myqueue2.front(): " << myqueue2.front() << std::endl;
	cout << std::endl;

	cout << _WHITE << "# test cpy and equality" << _END << std::endl;
	queue<int>	cpyqueue = myqueue;
	cout << "queue<" << _PURPLE << "int" << _END << "> cpyqueue = myqueue" << std::endl;
	cout << std::endl;

	cout << "cpyqueue == myqueue:" << (cpyqueue == myqueue) << std::endl;
	cpyqueue.push(7);
	cout << "cpyqueue.push(7)" << std::endl;
	cout << "cpyqueue == myqueue:" << (cpyqueue == myqueue) << std::endl;

	return 0;
}
