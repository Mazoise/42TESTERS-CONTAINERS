/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_main.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/18 16:07:02 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"
#include "VECTOR_UC.HPP"
#include <vector>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

int main()
{
	vector<string> JOHN;
	vector<string> BOB(5, "Hello");
	cout << "BOB(5, 8) : ";
	for (size_t i = 0; i < BOB.size(); i++)
		cout << BOB[i] << ' ';
	cout << '\n';
	vector<string> MIKE(BOB);

	// CTORs
	cout << "\nCTORS\n";
	cout << "Empty is empty ? " << std::boolalpha << JOHN.empty() << '\n';
	cout << "BOB is empty? " << BOB.empty() << '\n';

	cout << "Size of JOHN " << JOHN.size() << std::endl;
	cout << "Size of BOB " << BOB.size() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;


	// RESIZE
	size_t	bob_resize = 2;
	cout << "\nRESIZE\n";
	BOB.resize(bob_resize);
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 53\n";
	cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_resize)
		cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 58\n";
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 63\n";

	size_t	mike_resize = 9;
	bob_resize = 0;
	
	BOB.resize(bob_resize);
	cout << "BOB is empty now ? " << BOB.empty() << '\n';
	MIKE.resize(mike_resize, "juste some random string");
	/*
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	cout << "Capacity of JOHN " << JOHN.capacity() << std::endl;
	cout << "Size of BOB " << BOB.size() << std::endl;
	cout << "Capacity of BOB " << BOB.capacity() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	cout << "Capacity of MIKE " << MIKE.capacity() << std::endl;
	*/
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 86\n";
	cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_resize)
		cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 91\n";
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= mike_resize)
		cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 96\n";
	for (size_t i = 0; i < MIKE.size(); i++)
		cout << MIKE[i] << ' ';
	cout << std::endl;

	// RESERVE
	cout << "\nRESERVE\n";

	size_t	john_reserve = 5;
	size_t	bob_reserve = 3;
	size_t	mike_reserve = 83;

	JOHN.reserve(john_reserve);
	BOB.reserve(bob_reserve);
	MIKE.reserve(mike_reserve);
	/*
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	cout << "Capacity of JOHN " << JOHN.capacity() << std::endl;
	cout << "Size of BOB " << BOB.size() << std::endl;
	cout << "Capacity of BOB " << BOB.capacity() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	cout << "Capacity of MIKE " << MIKE.capacity() << std::endl;
	*/
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= john_reserve)
		cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 120\n";
	cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_reserve)
		cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 125\n";
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= mike_reserve)
		cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 130\n";
	for (size_t i = 0; i < MIKE.size(); i++)
		cout << MIKE[i] << ' ';
	cout << std::endl;

	//AT
	cout << "\nAT\n";
	try
	{
		cout << MIKE.at(2) << '\n';
		cout << MIKE.at(87) << '\n';
	}
	catch (std::out_of_range& oor)
	{
		(void)oor;
		cout << "OOR error caught\n";
	}

	// FRONT / BACK
	cout << "\nFRONT / BACK\n";
	cout << "front() of MIKE : " << MIKE.front() << '\n';
	cout << "back() of MIKE : " << MIKE.back() << '\n';

	//ASSIGN
	cout << "\nASSIGN\n";
	BOB.assign(42, "James BOND");

	//ASSIGN RANGE
	cout << "\nASSIGN RANGE\n";
	vector<string>	assign_range;
	assign_range.assign(8, "Covfefe");
	assign_range.assign(BOB.begin() + 1, BOB.end() - 2);

	//EMPTY
	cout << "\nEMPTY\n";
	cout << "BOB is empty ? " << BOB.empty() << '\n';
	cout << "BOB at(41) : " << BOB.at(41) << '\n';

	//PUSH/POP_BACK
	cout << "\nPUSH/POP_BACK\n";
	BOB.push_back("My name is Bond");
	cout << "last elem of BOB : " << BOB.back() << '\n';
	BOB.pop_back();
	cout << "last elem of BOB : " << BOB.back() << '\n';

	//INSERT
	cout << "\nINSERT\n";
	vector<string>	insert_in_me;
	for (size_t i = 0; i < 15; i++)
		insert_in_me.push_back(ft::to_string(i) + " I love hbaudet\n");
	cout << "after push_back, before at\n";
	for (size_t i = 0; i < insert_in_me.size(); i++)
		cout << insert_in_me.at(i) << ' ';
	cout << '\n';

	vector<string>::iterator	tmp;
	tmp = insert_in_me.begin() + 4;
	insert_in_me.insert(tmp, 8, "Norminet");
	for (size_t i = 0; i < insert_in_me.size(); i++)
		cout << insert_in_me.at(i) << ' ';
	cout << '\n';

	vector<string>::const_iterator const_it(insert_in_me.begin());
	cout << "Const it : " << std::endl;
	cout << *const_it << '\n';
//	*const_it = 89; // Does not compile because it's a const_iterator


	//INSERT
	cout << "\nINSERT\n";
	vector<string>	std_insert_in_me;
	for (size_t i = 0; i < 15; i++)
		std_insert_in_me.push_back(ft::to_string(i) + " 42 ");
	for (size_t i = 0; i < std_insert_in_me.size(); i++)
		cout << std_insert_in_me.at(i) << ' ';
	cout << '\n';

	vector<string>::iterator	std_tmp;
	std_tmp = std_insert_in_me.begin() + 4;
	std_insert_in_me.insert(std_tmp, 8, "Why are you reading this!?");
	for (size_t i = 0; i < std_insert_in_me.size(); i++)
		cout << std_insert_in_me.at(i) << ' ';
	cout << '\n';


	//INSERT RANGE
	cout << "\nINSERT RANGE\n";
	vector<string>	insert_bis;
	for (size_t i = 0; i < 7; i++)
		insert_bis.push_back(ft::to_string(3 * i));
	for (size_t i = 0; i < insert_bis.size(); i++)
		cout << insert_bis[i] << ' ';
	cout << '\n';

	insert_bis.insert(insert_bis.begin() + 5, insert_in_me.begin(), insert_in_me.end());
	for (size_t i = 0; i < insert_bis.size(); i++)
		cout << insert_bis[i] << ' ';
	cout << '\n';


	//ERASE
	cout << "\nERASE\n";
	vector<string>	erase_in_me;
	for (size_t i = 0; i < 15; i++)
		erase_in_me.push_back(ft::to_string(2 * i));
	for (size_t i = 0; i < erase_in_me.size(); i++)
	{
//		if (erase_in_me[i] < 10)
//			cout << ' ';
		cout << erase_in_me.at(i) << ' ';
	}
	cout << '\n';

	erase_in_me.erase(erase_in_me.begin() + 7);
	for (size_t i = 0; i < erase_in_me.size(); i++)
	{
//		if (erase_in_me[i] < 10)
//			cout << ' ';
		cout << erase_in_me.at(i) << ' ';
	}
	cout << '\n';

	erase_in_me.erase(erase_in_me.begin() + 2, erase_in_me.begin() + 6);
	for (size_t i = 0; i < erase_in_me.size(); i++)
	{
//		if (erase_in_me[i] < 10)
//			cout << ' ';
		cout << erase_in_me.at(i) << ' ';
	}
	cout << '\n';

	//SWAP
	cout << "\nSWAP\n";
	BOB.swap(MIKE);
	/*
	cout << "Size of BOB " << BOB.size() << std::endl;
	cout << "Capacity of BOB " << BOB.capacity() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	cout << "Capacity of MIKE " << MIKE.capacity() << std::endl;
	*/
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 272\n";
	cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 277\n";
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 282\n";
	for (size_t i = 0; i < MIKE.size(); i++)
		cout << MIKE[i] << ' ';
	cout << std::endl;

	MIKE.swap(JOHN);
	/*
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	cout << "Capacity of JOHN " << JOHN.capacity() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	cout << "Capacity of MIKE " << MIKE.capacity() << std::endl;
	*/
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 298\n";
	cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 303\n";
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 308\n";
	for (size_t i = 0; i < MIKE.size(); i++)
		cout << MIKE[i] << ' ';
	cout << std::endl;

	//CLEAR
	cout << "\nCLEAR\n";
	JOHN.clear();
	MIKE.clear();
	/*
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	cout << "Capacity of JOHN " << JOHN.capacity() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	cout << "Capacity of MIKE " << MIKE.capacity() << std::endl;
	*/
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 327\n";
	cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 332\n";
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 337\n";
	for (size_t i = 0; i < MIKE.size(); i++)
		cout << MIKE[i] << ' ';
	cout << std::endl;

	//NON MEMBER Functions
	cout << "\nNON MEMBER functions\n";
	swap(BOB, MIKE);
	/*
	cout << "Size of BOB " << BOB.size() << std::endl;
	cout << "Capacity of BOB " << BOB.capacity() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	cout << "Capacity of MIKE " << MIKE.capacity() << std::endl;
	*/
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 355\n";
	cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 360\n";
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 365\n";
	for (size_t i = 0; i < MIKE.size(); i++)
		cout << MIKE[i] << ' ';
	cout << std::endl;
	
	//RELATIONAL OPERATORS
	cout << "\nRELATIONAL OPERATORS\n";
	vector<string> MIKE_2(MIKE);
	cout << "MIKE and BOB are equal ? " << (MIKE == BOB) << '\n';
	cout << "MIKE and MIKE_2 are equal ? " << (MIKE == MIKE_2) << '\n';

	vector<string> real;
	real.assign(5, "foo");
	for (vector<string>::iterator it = real.begin(); it != real.end(); it++)
		cout << *it << " ";
	cout << '\n';

	cout << std::endl;
	return (0);
}
