/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inception_main.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/18 16:02:00 by hbaudet          ###   ########.fr       */
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
void	print(deque<deque<T> >& lst)
{
	for (typename deque<deque<T> >::iterator it = lst.begin(); it != lst.end(); it++)
	{
		for (typename deque<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
			cout << *it2 << ' ';
		cout << '\n';
	}
}

template <class T>
void	print(deque<T>& lst)
{
	for (typename deque<T>::iterator it = lst.begin(); it != lst.end(); it++)
		cout << *it << ' ';
	cout << '\n';
}

int main()
{
	deque<int>			test(3, 3);


	deque<deque<int> > JOHN;
	deque<deque<int> > BOB(5, test);
	cout << "BOB(5, test(test, 5)) : \n";
	deque<deque<int> > MIKE(BOB);
	print(JOHN);
	print(BOB);
	print(MIKE);
	print(test);

	// CTORs
	cout << "\nCTORS\n";
	cout << "Empty is empty ? " << std::boolalpha << JOHN.empty() << '\n';
	cout << "BOB is empty? " << BOB.empty() << '\n';

	cout << "Size of JOHN " << JOHN.size() << std::endl;
	cout << "Size of BOB " << BOB.size() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;

	print(JOHN);
	print(BOB);
	print(MIKE);
	print(test);

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
	print(test);

	size_t	mike_resize = 9;
	bob_resize = 0;
	
	BOB.resize(bob_resize);
	cout << "BOB is empty now ? " << BOB.empty() << '\n';
	MIKE.resize(mike_resize, test);
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	cout << "Size of BOB " << BOB.size() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	print(JOHN);
	print(BOB);
	print(MIKE);
	print(test);

	// FRONT / BACK
	cout << "\nFRONT / BACK\n";
	cout << "front() of MIKE : " << MIKE.front().front() << '\n';
	cout << "back() of MIKE : " << MIKE.back().back() << '\n';

	//ASSIGN
	cout << "\nASSIGN\n";
	test.assign(3, 17);
	BOB.assign(3, test);
	print(JOHN);
	print(BOB);
	print(MIKE);
	print(test);

	//ASSIGN RANGE
	cout << "\nASSIGN RANGE\n";
	deque<deque<int> >	assign_range;
	assign_range.assign(8, test);
	assign_range.assign(BOB.begin(), BOB.end());
	print(assign_range);

	//EMPTY
	cout << "\nEMPTY\n";
	cout << "BOB is empty ? " << BOB.empty() << '\n';

	//PUSH/POP_BACK
	cout << "\nPUSH/POP_BACK\n";
	test.assign(2, 42);
	BOB.push_back(test);
	cout << "last elem of BOB : " << BOB.back().back() << '\n';
	BOB.pop_back();
	cout << "last elem of BOB : " << BOB.back().back() << '\n';
	print(JOHN);
	print(BOB);
	print(MIKE);
	print(test);

	//INSERT
	cout << "\nINSERT\n";
	deque<deque<int> >	insert_in_me;
	for (int i = 0; i < 15; i++)
	{
		deque<int>	j(2, i);
		insert_in_me.push_back(j);
	}
	print(insert_in_me);

	deque<deque<int> >::iterator	tmp;
	test.assign(23, 19);
	tmp = insert_in_me.begin();
	insert_in_me.insert(tmp, 8, test);
	print(test);
	print(insert_in_me);

	deque<deque<int> >::const_iterator const_it(insert_in_me.begin());
	cout << "Const it.front() : " << std::endl;
	cout << (*const_it).front() << '\n';


	//INSERT
	cout << "\nINSERT\n";
	deque<deque<int> >	std_insert_in_me;
	for (int i = 0; i < 15; i++)
		std_insert_in_me.push_back(test);
	print(insert_in_me);

	deque<deque<int> >::iterator	std_tmp;
	std_tmp = std_insert_in_me.begin();
	std_insert_in_me.insert(std_tmp, 8, test);
	print(std_insert_in_me);

	//INSERT RANGE
	cout << "\nINSERT RANGE\n";
	deque<deque<int> >	insert_bis;
	for (int i = 0; i < 7; i++)
	{
		deque<int>	j(2, i * 3);
		insert_bis.push_back(j);
	}
	print(insert_bis);

	insert_bis.insert(insert_bis.begin(), insert_in_me.begin(), insert_in_me.end());
	print(insert_bis);


	//ERASE
	cout << "\nERASE\n";
	deque<deque<int> >	erase_in_me;
	for (int i = 0; i < 15; i++)
	{
		deque<int>	j(1, i);
		erase_in_me.push_back(j);
	}
	print(erase_in_me);

	erase_in_me.erase(erase_in_me.begin());
	print(erase_in_me);
	erase_in_me.erase(erase_in_me.begin(), ++(erase_in_me.begin()));
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
	print(test);

	MIKE.swap(JOHN);
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	cout << "Size of BOB " << BOB.size() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	print(JOHN);
	print(BOB);
	print(MIKE);
	print(test);

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
	print(test);

	//NON MEMBER Functions
	cout << "\nNON MEMBER functions\n";
	swap(BOB, MIKE);
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	cout << "Size of BOB " << BOB.size() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	print(JOHN);
	print(BOB);
	print(MIKE);
	print(test);
	
	//RELATIONAL OPERATORS
	cout << "\nRELATIONAL OPERATORS\n";
	deque<deque<int> > MIKE_2(MIKE);
	cout << "MIKE and BOB are equal ? " << (MIKE == BOB) << '\n';
	cout << "MIKE and MIKE_2 are equal ? " << (MIKE == MIKE_2) << '\n';
	print(JOHN);
	print(BOB);
	print(MIKE);
	print(test);

	deque<deque<int> > real;
	real.assign(5, test);
	print(real);
	
	cout << std::endl;
	return (0);
}

