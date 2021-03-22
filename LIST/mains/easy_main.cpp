/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 08:48:03 by user42            #+#    #+#             */
/*   Updated: 2021/01/18 16:04:33 by hbaudet          ###   ########.fr       */
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

# define RED "\033[0;31m"
# define CRED std::cout << "\033[0;31m"
# define GREEN "\033[0;92m"
# define CGREEN std::cout << "\033[0;92m"
# define MAG "\033[0;95m"
# define CMAG std::cout << "\033[0;95m"
# define CYAN "\033[0;96m"
# define CCYAN std::cout << "\033[0;96m"
# define BLUE "\033[0;94m"
# define CBLUE std::cout << "\033[0;94m"
# define YELLOW "\033[0;93m"
# define CYELLOW std::cout << "\033[0;93m"
# define GREY "\033[0;90m"
# define CGREY std::cout << "\033[0;90m"
# define END "\033[0m"
# define ENDL "\033[0m" << std::endl

void print_list(list<int>& v)
{
	list<int>::iterator it1;
	list<int>::iterator it2;

	it1 = v.begin();
	it2 = v.end();

	CCYAN << "List=[";
	while (it1 != it2)
	{
		CYELLOW << *it1;
		CBLUE << ", ";
		it1++;
	}
	CCYAN << "]" << ENDL;
}

int main()
{
	CGREEN << "INITIALIZATION" << ENDL;
	CMAG << "operations..." << ENDL;
	list<int> fill(10, 42);
	list<int> tmp;
	list<int>::iterator it1;
	list<int>::iterator it2;
	CMAG << "print..." << ENDL;
	print_list(fill);

	CGREEN << "ERASE" << ENDL;
	CMAG << "operations..." << ENDL;
	it1 = fill.begin();
	for (int i = 0; i < 5; i++)
		it1 ++;
	it2 = fill.end();
	for (int i = 0; i < 5; i++)
		it2 --;

	fill.erase(it1, it2);
	CMAG << "print..." << ENDL;
	print_list(fill);

	CGREEN << "POP_BACK/PUSH_BACK" << ENDL;
	CMAG << "operations..." << ENDL;
	fill.pop_back();
	fill.push_back(13);
	fill.push_back(69);
	CMAG << "print..." << ENDL;
	print_list(fill);

	CGREEN << "OPERATOR[]" << ENDL;
	CMAG << "operations..." << ENDL;
	it1 = fill.begin();
	for (int i = 0; i < 3; i++)
		it1 ++;
	*it1 = -13;
	it1 = fill.begin();
	for (int i = 0; i < 5; i++)
		it1 ++;
	*it1 = 123456789;
	CMAG << "print..." << ENDL;
	print_list(fill);
	
	CGREEN << "SWAP" << ENDL;
	CMAG << "operations..." << ENDL;
	fill.swap(tmp);
	fill.swap(tmp);
	CMAG << "print..." << ENDL;
	print_list(fill);

	CGREEN << "FRONT/BACK/AT" << ENDL;
	CMAG << "operations..." << ENDL;
	fill.front() = -42;
	fill.back() /= -2;
	it1 = fill.begin();
	*it1 = -1;
	CMAG << "print..." << ENDL;
	print_list(fill);

	CGREEN << "INSERT" << ENDL;
	CMAG << "operations..." << ENDL;
	it1 = fill.begin();
	it1 ++;
	it1 ++;

	fill.insert(it1, 3, 987654321);
	CMAG << "print..." << ENDL;
	print_list(fill);


	CGREEN << "RESIZE" << ENDL;
	CMAG << "operations..." << ENDL;
	fill.resize(20);
	fill.resize(13);
	CMAG << "print..." << ENDL;
	print_list(fill);
	return (0);
}
