/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/18 16:01:51 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"
#include "DEQUE_UC.HPP"
#include <deque>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

template <class T>
void	print(deque<T>& lst)
{
	for (typename deque<T>::iterator it = lst.begin(); it != lst.end(); it++)
		cout << *it << " ";
	cout << '\n';
}

int main()
{
	deque<int> JOHN;
	deque<int> BOB(5, 8);
	cout << "BOB(5, 8) : ";
	print(BOB);
	deque<int> MIKE(BOB);

	// CTORs
	cout << "\nCTORS\n";
	cout << "JOHN is empty ? " << std::boolalpha << JOHN.empty() << '\n';
	cout << "BOB is empty? " << BOB.empty() << '\n';

	cout << "Size of JOHN " << JOHN.size() << std::endl;
	cout << "Size of BOB " << BOB.size() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;

	print(JOHN);
	print(BOB);
	print(MIKE);


	// RESIZE
	size_t	bob_resize = 2;
	cout << "\nRESIZE\n";
	BOB.resize(bob_resize);
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	cout << "Size of BOB " << BOB.size() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	print(JOHN);
	print(BOB);
	print(MIKE);

	size_t	mike_resize = 9;
	bob_resize = 0;
	
	BOB.resize(bob_resize);
	cout << "BOB is empty now ? " << BOB.empty() << '\n';
	MIKE.resize(mike_resize, 3);

	cout << "Size of JOHN " << JOHN.size() << std::endl;
	cout << "Size of BOB " << BOB.size() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	print(JOHN);
	print(BOB);
	print(MIKE);

	// FRONT / BACK
	cout << "\nFRONT / BACK\n";
	cout << "front() of MIKE : " << MIKE.front() << '\n';
	cout << "back() of MIKE : " << MIKE.back() << '\n';

	//ASSIGN
	cout << "\nASSIGN\n";
	BOB.assign(42, 7);
	print(JOHN);
	print(BOB);
	print(MIKE);

	//ASSIGN RANGE
	cout << "\nASSIGN RANGE\n";
	deque<int>	assign_range;
	assign_range.assign(8, 5);
	assign_range.assign(BOB.begin(), BOB.end());
	print(JOHN);
	print(BOB);
	print(MIKE);

	//EMPTY
	cout << "\nEMPTY\n";
	cout << "BOB is empty ? " << BOB.empty() << '\n';

	//PUSH/POP_BACK
	cout << "\nPUSH/POP_BACK\n";
	BOB.push_back(53);
	cout << "last elem of BOB : " << BOB.back() << '\n';
	BOB.pop_back();
	cout << "last elem of BOB : " << BOB.back() << '\n';
	print(JOHN);
	print(BOB);
	print(MIKE);

	//INSERT
	cout << "\nINSERT\n";
	deque<int>	insert_in_me;
	for (int i = 0; i < 15; i++)
		insert_in_me.push_back(i);
	print(insert_in_me);

	deque<int>::iterator	tmp;
	tmp = insert_in_me.begin();
	insert_in_me.insert(tmp, 8, 42);
	print(insert_in_me);

	deque<int>::const_iterator const_it(insert_in_me.begin());
	cout << "Const it : " << std::endl;
	cout << *const_it << '\n';
//	*const_it = 89; // Does not compile because it's a const_iterator

	//INSERT
	cout << "\nINSERT\n";
	deque<int>	std_insert_in_me;
	for (int i = 0; i < 15; i++)
		std_insert_in_me.push_back(i);
	print(insert_in_me);

	deque<int>::iterator	std_tmp;
	std_tmp = std_insert_in_me.begin();
	std_insert_in_me.insert(std_tmp, 8, 42);
	print(insert_in_me);


	//INSERT RANGE
	cout << "\nINSERT RANGE\n";
	deque<int>	insert_bis;
	for (int i = 0; i < 7; i++)
		insert_bis.push_back(3 * i);
	print(insert_bis);

	insert_bis.insert(insert_bis.begin(), insert_in_me.begin(), insert_in_me.end());
	print(insert_bis);


	//ERASE
	cout << "\nERASE\n";
	deque<int>	erase_in_me;
	for (int i = 0; i < 15; i++)
		erase_in_me.push_back(2 * i);
	print(erase_in_me);

	erase_in_me.erase(erase_in_me.begin());
	print(erase_in_me);

	erase_in_me.erase(erase_in_me.begin(), erase_in_me.begin());
	print(erase_in_me);

	//SWAP
	cout << "\nSWAP\n";
	BOB.swap(MIKE);
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	cout << "Size of BOB " << BOB.size() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	print(JOHN);
	print(BOB);
	print(MIKE);

	MIKE.swap(JOHN);
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	cout << "Size of BOB " << BOB.size() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	print(JOHN);
	print(BOB);
	print(MIKE);

	//CLEAR
	cout << "\nCLEAR\n";
	JOHN.clear();
	MIKE.clear();
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	cout << "Size of BOB " << BOB.size() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	print(JOHN);
	print(BOB);
	print(MIKE);

	//NON MEMBER Functions
	cout << "\nNON MEMBER functions\n";
	swap(BOB, MIKE);
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	cout << "Size of BOB " << BOB.size() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	print(JOHN);
	print(BOB);
	print(MIKE);
	
	//RELATIONAL OPERATORS
	cout << "\nRELATIONAL OPERATORS\n";
	deque<int> MIKE_2(MIKE);
	cout << "MIKE and BOB are equal ? " << (MIKE == BOB) << '\n';
	cout << "MIKE and MIKE_2 are equal ? " << (MIKE == MIKE_2) << '\n';

	deque<int> real;
	real.assign(5, 7);
	for (deque<int>::iterator it = real.begin(); it != real.end(); it++)
		cout << *it << " ";
	cout << '\n';

	cout << std::endl;
	return (0);
}
