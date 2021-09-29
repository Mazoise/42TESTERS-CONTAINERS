/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmartin_main.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/09/29 19:34:44 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "STACK_UC.HPP"
#include <vector>
#include "test_utils.hpp"
#include "VECTOR_UC.HPP"
#include <stack>

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

int	main(void)
{
	cout << _WHITE << "# test_stack" << _END << std::endl;
	cout << _YELLOW <<  "/* ********************************************************************** */" << std::endl;
	cout << "/*                          "<< _WHITE << "BASIC TESTS" << _YELLOW << "                                   */" << std::endl;
	cout << "/* ********************************************************************** */" << _END << std::endl;
	stack<int> mystack;

	cout << "stack<" << _PURPLE << "int" << _END << "> mystack" << std::endl;
	cout << std::endl;


	cout << _WHITE << "# empty" << _END << std::endl;
	cout << "mystack.empty(): " <<  mystack.empty() << std::endl;
	cout << "mystack.size(): " << mystack.size() << std::endl;
	cout << _WHITE << "# one element" << _END << std::endl;
	mystack.push(42);
	cout << "mystack.push(42)" << std::endl;
	cout << "mystack.empty(): " <<  mystack.empty() << std::endl;
	cout << "mystack.size(): " << mystack.size() << std::endl;
	cout << "mystack.top(): " << mystack.top() << std::endl;
	cout << _WHITE << "# two element" << _END << std::endl;
	mystack.push(2);
	cout << "mystack.push(2)" << std::endl;
	cout << "mystack.size(): " << mystack.size() << std::endl;
	cout << "mystack.top(): " << mystack.top() << std::endl;
	cout << _WHITE << "# pop element" << _END << std::endl;
	mystack.pop();
	cout << "mystack.pop()" << std::endl;
	cout << "mystack.size(): " << mystack.size() << std::endl;
	cout << "mystack.top(): " << mystack.top() << std::endl;
	cout << std::endl;

	stack<int, ft::vector<int> > mystack2;

	cout << "stack<" << _PURPLE << "int" << _END << ", " << _PURPLE << "ft::vector" << _END << "> mystack2" << std::endl;
	cout << std::endl;


	cout << _WHITE << "# empty" << _END << std::endl;
	cout << "mystack2.empty(): " <<  mystack2.empty() << std::endl;
	cout << "mystack2.size(): " << mystack2.size() << std::endl;
	cout << _WHITE << "# one element" << _END << std::endl;
	mystack2.push(42);
	cout << "mystack2.push(42)" << std::endl;
	cout << "mystack2.empty(): " <<  mystack2.empty() << std::endl;
	cout << "mystack2.size(): " << mystack2.size() << std::endl;
	cout << "mystack2.top(): " << mystack2.top() << std::endl;
	cout << _WHITE << "# two element" << _END << std::endl;
	mystack2.push(2);
	cout << "mystack2.push(2)" << std::endl;
	cout << "mystack2.size(): " << mystack2.size() << std::endl;
	cout << "mystack2.top(): " << mystack2.top() << std::endl;
	cout << _WHITE << "# pop element" << _END << std::endl;
	mystack2.pop();
	cout << "mystack2.pop()" << std::endl;
	cout << "mystack2.size(): " << mystack2.size() << std::endl;
	cout << "mystack2.top(): " << mystack2.top() << std::endl;
	cout << std::endl;

	cout << _WHITE << "# test cpy and equality" << _END << std::endl;
	stack<int>	cpystack = mystack;
	cout << "stack<" << _PURPLE << "int" << _END << "> cpystack = mystack" << std::endl;
	cout << std::endl;

	cout << "cpystack == mystack:" << (cpystack == mystack) << std::endl;
	cpystack.push(7);
	cout << "cpystack.push(7)" << std::endl;
	cout << "cpystack == mystack:" << (cpystack == mystack) << std::endl;

	return 0;
}
