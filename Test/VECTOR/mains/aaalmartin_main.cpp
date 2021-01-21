/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aaalmartin_main.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/20 22:03:48 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hbaudet_utils.hpp"
#include "VECTOR_UC.HPP"
#include <vector>
#include <iomanip>

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
void	print(vector<vector<T> >& lst)
{
	for (typename vector<vector<T> >::iterator it = lst.begin(); it != lst.end(); it++)
	{
		for (typename vector<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
			cout << *it2 << ' ';
		cout << '\n';
	}
}

template <class T>
void	print(vector<T>& lst)
{
	for (typename vector<T>::iterator it = lst.begin(); it != lst.end(); it++)
		cout << *it << ' ';
	cout << '\n';
}

int main()
{
	cout << _WHITE << "# test_vector" << _END << std::endl;
	cout << _YELLOW <<  "/* ********************************************************************** */" << std::endl;
	cout << "/*                          "<< _WHITE << "BASIC TESTS" << _YELLOW << "                                   */" << std::endl;
	cout << "/* ********************************************************************** */" << _END << std::endl;
	cout << std::endl;

	vector<int>	myv;

	cout << "vector<" << _PURPLE << "int" << _END << "> myv;" << std::endl;

	cout << std::endl;
	cout << "myv.max_size(): " << (myv.max_size() > 10000) << std::endl;
	cout << std::endl;

	try
	{
		myv.pop_back();
	}
	catch (std::exception &e)
	{
		cout << "Catching exception myv: " << e.what() << std::endl;
	}
	try
	{
		myv.front();
	}
	catch (std::exception &e)
	{
		cout << "Catching exception myv: " << e.what() << std::endl;
	}

	myv.back();
	
	cout << _WHITE << "# testing out_of_range exception" << _END << std::endl;
	cout << "myv.at(0):" << std::endl;
	try
	{
		myv.at(0);
	}
	catch (std::exception &e)
	{
		cout << "Catching exception myv: " << e.what() << std::endl;
	}
	cout << std::endl;

	cout << "myv.capacity(): " << myv.capacity() << std::endl;
	myv.reserve(0);
	cout << "myv.reserve(0);" << std::endl;
	cout << "myv.capacity(): " << myv.capacity() << std::endl;
	try
	{
		myv.reserve(1);
	}
	catch (std::exception& e)
	{
		cout << "caught : " << e.what() << std::endl;
	}
	cout << "myv.reserve(1);" << std::endl;
	cout << "myv.capacity(): " << myv.capacity() << std::endl;
	cout << std::endl;

	cout << _WHITE << "# testing reserve exception" << _END << std::endl;
	cout << "myv.reserve(" << std::numeric_limits<size_t>::max() << ");" << std::endl;
	try
	{
		myv.reserve(std::numeric_limits<size_t>::max());
	}
	catch (std::exception &e)
	{
		cout << "Catching exception myv: " << e.what() << std::endl;
	}

	myv.resize(8);
	cout << "myv.capacity(): " << myv.capacity() << std::endl;

	myv.push_back(4);
	cout << _WHITE << "# vector resize more on push_back but both works" << _END << std::endl;
	cout << "myv.capacity(): " << myv.capacity() << std::endl;
	myv.erase(myv.begin());

	cout << _WHITE << "# launching clear twice" << _END << std::endl;
	myv.clear();
	myv.clear();
	cout << "myv.capacity(): " << myv.capacity() << std::endl;


	cout << _YELLOW <<  "/* ********************************************************************** */" << std::endl;
	cout << "/*                        "<< _WHITE << "ADVANCED TESTS" << _YELLOW << "                                  */" << std::endl;
	cout << "/* ********************************************************************** */" << _END << std::endl;
	cout << std::endl;
	myv.assign((size_t)10, 8);
	myv.assign(myv.begin(), myv.begin() + 4); // wtf that works

	vector<int> myv2;
	cout << "vector<" << _PURPLE << "int" << _END << "> myv2;" << std::endl;
	myv.swap(myv2);
	myv.swap(myv2);
	myv.erase(myv.begin() + 2);
	myv2 = myv;
	myv.at(2) = 1;
	myv[1] = 0;

	cout << _WHITE << "# comparaisons tests" << _END << std::endl;
	cout << std::setw(30) << "myv < myv2: " << (myv < myv2) << std::endl;
	cout << std::endl;
	cout << std::setw(30) << "myv > myv2: " << (myv > myv2) << std::endl;
	cout << std::endl;
	cout << std::setw(30) << "myv == myv2: " << (myv == myv2) << std::endl;
	cout << std::endl;
	cout << std::setw(30) << "myv != myv2: " << (myv == myv2) << std::endl;
	cout << std::endl;
	cout << std::setw(30) << "myv <= myv2: " << (myv <= myv2) << std::endl;
	cout << std::endl;
	cout << std::setw(30) << "myv >= myv2: " << (myv >= myv2) << std::endl;

	return 0;
}
