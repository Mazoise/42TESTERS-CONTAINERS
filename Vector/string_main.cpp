/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_main.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2020/12/10 17:30:37 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include <vector>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

int main()
{
	vector<string> empty;
	vector<string> fill(5, "forty_two");
	cout << "fill(5, forty_two) : ";
	for (size_t i = 0; i < fill.size(); i++)
		cout << fill[i] << ' ';
	cout << '\n';
	vector<string> copy(fill);
	std::vector<string> test;

	// CTORs
	cout << "\nCTORS\n";
	cout << "Empty is empty ? " << std::boolalpha << empty.empty() << '\n';
	cout << "fill is empty? " << fill.empty() << '\n';

	cout << "Size of empty " << empty.size() << std::endl;
	cout << "Size of fill " << fill.size() << std::endl;
	cout << "Size of copy " << copy.size() << std::endl;

	cout << "Max size of a real vector " << test.max_size()
		<< " " << (float)test.max_size() / (float)empty.max_size()
		<< " time more than vector" << std::endl;
	cout << "Max size of empty " << empty.max_size() << std::endl;
	cout << "Max size of fill " << fill.max_size() << std::endl;
	cout << "Max size of copy " << copy.max_size() << std::endl;


	// RESIZE
	cout << "\nRESIZE\n";
	fill.resize(2);
	cout << "Size of empty " << empty.size() << std::endl;
	cout << "Capacity of empty " << empty.capacity() << std::endl;
	cout << "Size of fill " << fill.size() << std::endl;
	cout << "Capacity of fill " << fill.capacity() << std::endl;
	cout << "Size of copy " << copy.size() << std::endl;
	cout << "Capacity of copy " << copy.capacity() << std::endl;

	fill.resize(0);
	cout << "fill is empty now ? " << fill.empty() << '\n';
	copy.resize(9, "more_strings");
	cout << "Size of empty " << empty.size() << std::endl;
	cout << "Capacity of empty " << empty.capacity() << std::endl;
	cout << "Size of fill " << fill.size() << std::endl;
	cout << "Capacity of fill " << fill.capacity() << std::endl;
	cout << "Size of copy " << copy.size() << std::endl;
	cout << "Capacity of copy " << copy.capacity() << std::endl;
	for (size_t i = 0; i < copy.size(); i++)
		cout << copy[i] << ' ';
	cout << std::endl;

	// RESERVE
	cout << "\nRESERVE\n";
	empty.reserve(5);
	fill.reserve(3);
	copy.reserve(83);
	cout << "Size of empty " << empty.size() << std::endl;
	cout << "Capacity of empty " << empty.capacity() << std::endl;
	cout << "Size of fill " << fill.size() << std::endl;
	cout << "Capacity of fill " << fill.capacity() << std::endl;
	cout << "Size of copy " << copy.size() << std::endl;
	cout << "Capacity of copy " << copy.capacity() << std::endl;
	for (size_t i = 0; i < copy.size(); i++)
		cout << copy[i] << ' ';
	cout << std::endl;

	//AT
	cout << "\nAT\n";
	try
	{
		cout << copy.at(2) << '\n';
		cout << copy.at(87) << '\n';
	}
	catch (std::out_of_range& oor)
	{
		cout << oor.what();
	}

	// FRONT / BACK
	cout << "\nFRONT / BACK\n";
	cout << "front() of copy : " << copy.front() << '\n';
	cout << "back() of copy : " << copy.back() << '\n';

	//ASSIGN
	cout << "\nASSIGN\n";
	fill.assign(42, "42");
	for (size_t i = 0; i < fill.size(); i++)
		cout << fill.at(i) << ' ';
	cout << '\n';
	cout << "Size of fill " << fill.size() << std::endl;
	cout << "Capacity of fill " << fill.capacity() << std::endl;

	//ASSIGN RANGE
	cout << "\nASSIGN RANGE\n";
	vector<string>	assign_range;
	assign_range.assign(8, "Hello");
	for (size_t i = 0; i < assign_range.size(); i++)
		cout << assign_range.at(i) << ' ';
	cout << '\n';
	assign_range.assign(fill.begin() + 1, fill.end() - 2);
	for (size_t i = 0; i < assign_range.size(); i++)
		cout << assign_range.at(i) << ' ';
	cout << '\n';

	//EMPTY
	cout << "\nEMPTY\n";
	cout << "fill is empty ? " << fill.empty() << '\n';
	cout << "fill at(41) : " << fill.at(41) << '\n';

	//PUSH/POP_BACK
	cout << "\nPUSH/POP_BACK\n";
	fill.push_back("Again");
	cout << "last elem of fill : " << fill.back() << '\n';
	fill.pop_back();
	cout << "last elem of fill : " << fill.back() << '\n';

	//INSERT
	cout << "\nINSERT\n";
	vector<string>	insert_in_me;
	for (int i = 0; i < 15; i++)
		insert_in_me.push_back(std::to_string(i));
	for (size_t i = 0; i < insert_in_me.size(); i++)
		cout << insert_in_me.at(i) << ' ';
	cout << '\n';

	vector<string>::iterator	tmp;
	tmp = insert_in_me.begin() + 4;
	insert_in_me.insert(tmp, 8, "world");
	for (size_t i = 0; i < insert_in_me.size(); i++)
		cout << insert_in_me.at(i) << ' ';
	cout << '\n';

	vector<string>::const_iterator const_it(insert_in_me.begin());
	cout << "Const it : " << std::endl;
	cout << *const_it << '\n';
//	*const_it = 89;


	//INSERT RANGE
	cout << "\nINSERT RANGE\n";
	vector<string>	insert_bis;
	for (int i = 0; i < 7; i++)
		insert_bis.push_back(std::to_string(3 * i));
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
	for (int i = 0; i < 15; i++)
		erase_in_me.push_back(std::to_string(2 * i));
	for (size_t i = 0; i < erase_in_me.size(); i++)
	{
		cout << erase_in_me.at(i) << ' ';
	}
	cout << '\n';

	erase_in_me.erase(erase_in_me.begin() + 7);
	for (size_t i = 0; i < erase_in_me.size(); i++)
	{
		cout << erase_in_me.at(i) << ' ';
	}
	cout << '\n';

	erase_in_me.erase(erase_in_me.begin() + 2, erase_in_me.begin() + 6);
	for (size_t i = 0; i < erase_in_me.size(); i++)
	{
		cout << erase_in_me.at(i) << ' ';
	}
	cout << '\n';

	//SWAP
	cout << "\nSWAP\n";
	cout << "Size of fill " << fill.size() << std::endl;
	cout << "Capacity of fill " << fill.capacity() << std::endl;
	cout << "Size of copy " << copy.size() << std::endl;
	cout << "Capacity of copy " << copy.capacity() << std::endl;
	std::cout << "fill.swap(copy)\n";
	fill.swap(copy);
	cout << "Size of fill " << fill.size() << std::endl;
	cout << "Capacity of fill " << fill.capacity() << std::endl;
	cout << "Size of copy " << copy.size() << std::endl;
	cout << "Capacity of copy " << copy.capacity() << std::endl;
	std::cout << "copy:\n";
	for (size_t i = 0; i < copy.size(); i++)
		cout << copy[i] << ' ';
	cout << std::endl;

	cout << "Size of empty " << empty.size() << std::endl;
	cout << "Capacity of empty " << empty.capacity() << std::endl;
	std::cout << "copy.swap(empty)\n";
	copy.swap(empty);
	cout << "Size of empty " << empty.size() << std::endl;
	cout << "Capacity of empty " << empty.capacity() << std::endl;
	cout << "Size of copy " << copy.size() << std::endl;
	cout << "Capacity of copy " << copy.capacity() << std::endl;
	for (size_t i = 0; i < copy.size(); i++)
		cout << copy[i] << ' ';
	cout << std::endl;

	//CLEAR
	cout << "\nCLEAR\n";
	empty.clear();
	copy.clear();
	cout << "Size of empty " << empty.size() << std::endl;
	cout << "Capacity of empty " << empty.capacity() << std::endl;
	cout << "Size of copy " << copy.size() << std::endl;
	cout << "Capacity of copy " << copy.capacity() << std::endl;
	for (size_t i = 0; i < copy.size(); i++)
		cout << copy[i] << ' ';
	cout << std::endl;

	//NON MEMBER Functions
	cout << "\nNON MEMBER functions\n";
	swap(fill, copy);
	cout << "Size of fill " << fill.size() << std::endl;
	cout << "Capacity of fill " << fill.capacity() << std::endl;
	cout << "Size of copy " << copy.size() << std::endl;
	cout << "Capacity of copy " << copy.capacity() << std::endl;
	for (size_t i = 0; i < copy.size(); i++)
		cout << copy[i] << ' ';
	cout << std::endl;
	
	//RELATIONAL OPERATORS
	cout << "\nRELATIONAL OPERATORS\n";
	vector<string> copy_2(copy);
	cout << "copy and fill are equal ? " << (copy == fill) << '\n';
	cout << "copy and copy_2 are equal ? " << (copy == copy_2) << '\n';

	cout << "\nReal Vector\n";
	vector<string> real;
	real.assign(5, "bar");
	for (vector<string>::iterator it = real.begin(); it != real.end(); it++)
		cout << *it << " ";
	cout << '\n';

	cout << std::endl;
	return (0);
}
