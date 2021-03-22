/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_main.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/18 16:03:42 by hbaudet          ###   ########.fr       */
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
	list<string> JOHN;
	list<string> BOB(5, "Hello");
	cout << "BOB(5, 8) : ";
	print(BOB);
	list<string> MIKE(BOB);

	// CTORs
	cout << "\nCTORS\n";
	cout << "Empty is empty ? " << std::boolalpha << JOHN.empty() << '\n';
	cout << "BOB is empty? " << BOB.empty() << '\n';

	cout << "Size of JOHN " << JOHN.size() << std::endl;
	cout << "Size of BOB " << BOB.size() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;

	print(MIKE);
	print(JOHN);
	print(BOB);


	// RESIZE
	size_t	bob_resize = 2;
	cout << "\nRESIZE\n";
	BOB.resize(bob_resize);
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	cout << "Size of BOB " << BOB.size() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;

	size_t	mike_resize = 9;
	bob_resize = 0;
	
	BOB.resize(bob_resize);
	cout << "BOB is empty now ? " << BOB.empty() << '\n';
	print(MIKE);
	print(JOHN);
	print(BOB);
	MIKE.resize(mike_resize, "juste some random string");
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	cout << "Size of BOB " << BOB.size() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	print(MIKE);
	print(JOHN);
	print(BOB);

	// FRONT / BACK
	cout << "\nFRONT / BACK\n";
	cout << "front() of MIKE : " << MIKE.front() << '\n';
	cout << "back() of MIKE : " << MIKE.back() << '\n';

	//ASSIGN
	cout << "\nASSIGN\n";
	BOB.assign(42, "James BOND");
	print(MIKE);
	print(JOHN);
	print(BOB);

	//ASSIGN RANGE
	cout << "\nASSIGN RANGE\n";
	list<string>	assign_range;
	assign_range.assign(8, "Covfefe");
	assign_range.assign(BOB.begin(), BOB.end());
	print(MIKE);
	print(JOHN);
	print(BOB);

	//EMPTY
	cout << "\nEMPTY\n";
	cout << "BOB is empty ? " << BOB.empty() << '\n';
	print(MIKE);
	print(JOHN);
	print(BOB);

	//PUSH/POP_BACK
	cout << "\nPUSH/POP_BACK\n";
	BOB.push_back("My name is Bond");
	cout << "last elem of BOB : " << BOB.back() << '\n';
	BOB.pop_back();
	cout << "last elem of BOB : " << BOB.back() << '\n';
	print(MIKE);
	print(JOHN);
	print(BOB);

	//INSERT
	cout << "\nINSERT\n";
	list<string>	insert_in_me;
	for (size_t i = 0; i < 15; i++)
		insert_in_me.push_back(ft::to_string(i) + " I love hbaudet\n");
	cout << "after push_back, before at\n";

	list<string>::iterator	tmp;
	tmp = insert_in_me.begin();
	insert_in_me.insert(tmp, 8, "Norminet");
	print(insert_in_me);
	list<string>::const_iterator const_it(insert_in_me.begin());
	cout << "Const it : " << std::endl;
	cout << *const_it << '\n';
//	*const_it = 89; // Does not compile because it's a const_iterator


	//INSERT
	cout << "\nINSERT\n";
	list<string>	std_insert_in_me;
	for (size_t i = 0; i < 15; i++)
		std_insert_in_me.push_back(ft::to_string(i) + " 42 ");

	print(std_insert_in_me);
	list<string>::iterator	std_tmp;
	std_tmp = std_insert_in_me.begin();
	std_insert_in_me.insert(std_tmp, 8, "Why are you reading this!?");
	print(std_insert_in_me);


	//INSERT RANGE
	cout << "\nINSERT RANGE\n";
	list<string>	insert_bis;
	for (size_t i = 0; i < 7; i++)
		insert_bis.push_back(ft::to_string(3 * i));
	print(insert_bis);

	insert_bis.insert(insert_bis.begin(), insert_in_me.begin(), insert_in_me.end());


	//ERASE
	cout << "\nERASE\n";
	list<string>	erase_in_me;
	for (size_t i = 0; i < 15; i++)
		erase_in_me.push_back(ft::to_string(2 * i));
	cout << '\n';

	erase_in_me.erase(erase_in_me.begin());

	erase_in_me.erase(erase_in_me.begin(), erase_in_me.begin());
	cout << '\n';

	//SWAP
	cout << "\nSWAP\n";
	BOB.swap(MIKE);
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	cout << "Size of BOB " << BOB.size() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	print(MIKE);
	print(JOHN);
	print(BOB);

	MIKE.swap(JOHN);
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	cout << "Size of BOB " << BOB.size() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	print(MIKE);
	print(JOHN);
	print(BOB);

	//CLEAR
	cout << "\nCLEAR\n";
	JOHN.clear();
	MIKE.clear();
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	cout << "Size of BOB " << BOB.size() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	print(MIKE);
	print(JOHN);
	print(BOB);

	//NON MEMBER Functions
	cout << "\nNON MEMBER functions\n";
	swap(BOB, MIKE);
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	cout << "Size of BOB " << BOB.size() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	print(MIKE);
	print(JOHN);
	print(BOB);
	
	//RELATIONAL OPERATORS
	cout << "\nRELATIONAL OPERATORS\n";
	list<string> MIKE_2(MIKE);
	cout << "MIKE and BOB are equal ? " << (MIKE == BOB) << '\n';
	cout << "MIKE and MIKE_2 are equal ? " << (MIKE == MIKE_2) << '\n';
	print(MIKE);
	print(JOHN);
	print(BOB);

	list<string> real;
	real.assign(5, "foo");
	for (list<string>::iterator it = real.begin(); it != real.end(); it++)
		cout << *it << " ";
	cout << '\n';

	cout << std::endl;
	return (0);
}
