/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aaalmartin_main.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/21 13:27:34 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"
#include "VECTOR_UC.HPP"
#include <vector>
#include <iostream>
#include <iomanip>
#include <limits>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;


template <class T>
void	print(std::vector<std::vector<T> >& lst)
{
	for (typename std::vector<std::vector<T> >::iterator it = lst.begin(); it != lst.end(); it++)
	{
		for (typename std::vector<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
			cout << *it2 << ' ';
		cout << '\n';
	}
}

template <class T>
void	print(std::vector<T>& lst)
{
	for (typename std::vector<T>::iterator it = lst.begin(); it != lst.end(); it++)
		cout << *it << ' ';
	cout << '\n';
}

int main()
{
	std::vector<int>	myv;

	cout << "myv.max_size(): " << (myv.max_size() > 10000) << std::endl;

	try
	{
		myv.front();
	}
	catch (std::exception &e)
	{
		cout << "Catching exception myv: " << e.what() << std::endl;
	}

	myv.back();
	
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
	cout << "myv.capacity(): " << myv.capacity() << std::endl;
	cout << std::endl;

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
	cout << "myv.capacity(): " << myv.capacity() << std::endl;
	myv.erase(myv.begin());

	cout << "# launching clear twice" << std::endl;
	myv.clear();
	myv.clear();
	cout << "myv.capacity(): " << myv.capacity() << std::endl;


	myv.assign((size_t)10, 8);
	myv.assign(myv.begin(), myv.begin() + 4); // wtf that works

	std::vector<int> myv2;
	myv.swap(myv2);
	myv.swap(myv2);
	myv.erase(myv.begin() + 2);
	myv2 = myv;
	myv.at(2) = 1;
	myv[1] = 0;

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
