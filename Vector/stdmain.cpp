/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdmain.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2020/12/08 16:26:54 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include <vector>

int main()
{
	std::vector<int> empty;
	std::vector<int> fill(5, 8);
	std::cout << "fill(5, 8) : ";
	for (size_t i = 0; i < fill.size(); i++)
		std::cout << fill[i] << ' ';
	std::cout << '\n';
	std::vector<int> copy(fill);
	std::vector<int> test;

	// CTORs
	std::cout << "\nCTORS\n";
	std::cout << "Empty is empty ? " << std::boolalpha << empty.empty() << '\n';
	std::cout << "fill is empty? " << fill.empty() << '\n';

	std::cout << "Size of empty " << empty.size() << std::endl;
	std::cout << "Size of fill " << fill.size() << std::endl;
	std::cout << "Size of copy " << copy.size() << std::endl;

	std::cout << "Max size of a real vector " << test.max_size()
		<< " " << (float)test.max_size() / (float)empty.max_size()
		<< " time more than std::vector" << std::endl;
	std::cout << "Max size of empty " << empty.max_size() << std::endl;
	std::cout << "Max size of fill " << fill.max_size() << std::endl;
	std::cout << "Max size of copy " << copy.max_size() << std::endl;


	// RESIZE
	std::cout << "\nRESIZE\n";
	fill.resize(2);
	std::cout << "Size of empty " << empty.size() << std::endl;
	std::cout << "Capacity of empty " << empty.capacity() << std::endl;
	std::cout << "Size of fill " << fill.size() << std::endl;
	std::cout << "Capacity of fill " << fill.capacity() << std::endl;
	std::cout << "Size of copy " << copy.size() << std::endl;
	std::cout << "Capacity of copy " << copy.capacity() << std::endl;

	fill.resize(0);
	std::cout << "fill is empty now ? " << fill.empty() << '\n';
	copy.resize(9, 3);
	std::cout << "Size of empty " << empty.size() << std::endl;
	std::cout << "Capacity of empty " << empty.capacity() << std::endl;
	std::cout << "Size of fill " << fill.size() << std::endl;
	std::cout << "Capacity of fill " << fill.capacity() << std::endl;
	std::cout << "Size of copy " << copy.size() << std::endl;
	std::cout << "Capacity of copy " << copy.capacity() << std::endl;
	for (size_t i = 0; i < copy.size(); i++)
		std::cout << copy[i] << ' ';
	std::cout << std::endl;


	// RESERVE
	std::cout << "\nRESERVE\n";
	empty.reserve(5);
	fill.reserve(3);
	copy.reserve(83);
	std::cout << "Size of empty " << empty.size() << std::endl;
	std::cout << "Capacity of empty " << empty.capacity() << std::endl;
	std::cout << "Size of fill " << fill.size() << std::endl;
	std::cout << "Capacity of fill " << fill.capacity() << std::endl;
	std::cout << "Size of copy " << copy.size() << std::endl;
	std::cout << "Capacity of copy " << copy.capacity() << std::endl;
	for (size_t i = 0; i < copy.size(); i++)
		std::cout << copy[i] << ' ';
	std::cout << std::endl;

	//AT
	std::cout << "\nAT\n";
	try
	{
		std::cout << copy.at(2) << '\n';
		std::cout << copy.at(87) << '\n';
	}
	catch (std::out_of_range& oor)
	{
		std::cout << oor.what();
	}

	// FRONT / BACK
	std::cout << "\nFRONT / BACK\n";
	std::cout << "front() of copy : " << copy.front() << '\n';
	std::cout << "back() of copy : " << copy.back() << '\n';

	//ASSIGN
	std::cout << "\nASSIGN\n";
	fill.assign(42, 7);

	//ASSIGN RANGE
	std::cout << "\nASSIGN RANGE\n";
	std::vector<int>	assign_range;
	assign_range.assign(8, 5);
	assign_range.assign(fill.begin() + 1, fill.end() - 2);

	//EMPTY
	std::cout << "\nEMPTY\n";
	std::cout << "fill is empty ? " << fill.empty() << '\n';
	std::cout << "fill at(41) : " << fill.at(41) << '\n';

	//PUSH/POP_BACK
	std::cout << "\nPUSH/POP_BACK\n";
	fill.push_back(53);
	std::cout << "last elem of fill : " << fill.back() << '\n';
	fill.pop_back();
	std::cout << "last elem of fill : " << fill.back() << '\n';

	//INSERT
	std::cout << "\nINSERT\n";
	std::vector<int>	insert_in_me;
	for (int i = 0; i < 15; i++)
		insert_in_me.push_back(i);
	for (size_t i = 0; i < insert_in_me.size(); i++)
		std::cout << insert_in_me.at(i) << ' ';
	std::cout << '\n';

	std::vector<int>::iterator	tmp;
	tmp = insert_in_me.begin() + 4;
	insert_in_me.insert(tmp, 8, 42);
	for (size_t i = 0; i < insert_in_me.size(); i++)
		std::cout << insert_in_me.at(i) << ' ';
	std::cout << '\n';

	std::vector<int>::const_iterator const_it(insert_in_me.begin());

	int			j = 14;

	int*		ptr = &j;
	const int*	p(ptr);

	std::cout << "test : " << *p << '\n';

	//STD::INSERT
	std::cout << "\nSTD::INSERT\n";
	std::vector<int>	std_insert_in_me;
	for (int i = 0; i < 15; i++)
		std_insert_in_me.push_back(i);
	for (size_t i = 0; i < std_insert_in_me.size(); i++)
		std::cout << std_insert_in_me.at(i) << ' ';
	std::cout << '\n';

	std::vector<int>::iterator	std_tmp;
	std_tmp = std_insert_in_me.begin() + 4;
	std_insert_in_me.insert(std_tmp, 8, 42);
	for (size_t i = 0; i < std_insert_in_me.size(); i++)
		std::cout << std_insert_in_me.at(i) << ' ';
	std::cout << '\n';

	std::vector<int>::const_iterator std_const_it(std_insert_in_me.begin());
	std::cout << "std::const it : " << *std_const_it << '\n';
//	*std_const_it = 48; // does not compile

	//INSERT RANGE
	std::cout << "\nINSERT RANGE\n";
	std::vector<int>	insert_bis;
	for (int i = 0; i < 7; i++)
		insert_bis.push_back(3 * i);
	for (size_t i = 0; i < insert_bis.size(); i++)
		std::cout << insert_bis[i] << ' ';
	std::cout << '\n';

	insert_bis.insert(insert_bis.begin() + 5, insert_in_me.begin(), insert_in_me.end());
	for (size_t i = 0; i < insert_bis.size(); i++)
		std::cout << insert_bis[i] << ' ';
	std::cout << '\n';


	//ERASE
	std::cout << "\nERASE\n";
	std::vector<int>	erase_in_me;
	for (int i = 0; i < 15; i++)
		erase_in_me.push_back(2 * i);
	for (size_t i = 0; i < erase_in_me.size(); i++)
	{
		if (erase_in_me[i] < 10)
			std::cout << ' ';
		std::cout << erase_in_me.at(i) << ' ';
	}
	std::cout << '\n';

	erase_in_me.erase(erase_in_me.begin() + 7);
	for (size_t i = 0; i < erase_in_me.size(); i++)
	{
		if (erase_in_me[i] < 10)
			std::cout << ' ';
		std::cout << erase_in_me.at(i) << ' ';
	}
	std::cout << '\n';

	erase_in_me.erase(erase_in_me.begin() + 2, erase_in_me.begin() + 6);
	for (size_t i = 0; i < erase_in_me.size(); i++)
	{
		if (erase_in_me[i] < 10)
			std::cout << ' ';
		std::cout << erase_in_me.at(i) << ' ';
	}
	std::cout << '\n';

	//SWAP
	std::cout << "\nSWAP\n";
	fill.swap(copy);
	std::cout << "Size of fill " << fill.size() << std::endl;
	std::cout << "Capacity of fill " << fill.capacity() << std::endl;
	std::cout << "Size of copy " << copy.size() << std::endl;
	std::cout << "Capacity of copy " << copy.capacity() << std::endl;
	for (size_t i = 0; i < copy.size(); i++)
		std::cout << copy[i] << ' ';
	std::cout << std::endl;

	copy.swap(empty);
	std::cout << "Size of empty " << empty.size() << std::endl;
	std::cout << "Capacity of empty " << empty.capacity() << std::endl;
	std::cout << "Size of copy " << copy.size() << std::endl;
	std::cout << "Capacity of copy " << copy.capacity() << std::endl;
	for (size_t i = 0; i < copy.size(); i++)
		std::cout << copy[i] << ' ';
	std::cout << std::endl;

	//CLEAR
	std::cout << "\nCLEAR\n";
	empty.clear();
	copy.clear();
	std::cout << "Size of empty " << empty.size() << std::endl;
	std::cout << "Capacity of empty " << empty.capacity() << std::endl;
	std::cout << "Size of copy " << copy.size() << std::endl;
	std::cout << "Capacity of copy " << copy.capacity() << std::endl;
	for (size_t i = 0; i < copy.size(); i++)
		std::cout << copy[i] << ' ';
	std::cout << std::endl;

	//NON MEMBER Functions
	std::cout << "\nNON MEMBER functions\n";
	std::swap(fill, copy);
	std::cout << "Size of fill " << fill.size() << std::endl;
	std::cout << "Capacity of fill " << fill.capacity() << std::endl;
	std::cout << "Size of copy " << copy.size() << std::endl;
	std::cout << "Capacity of copy " << copy.capacity() << std::endl;
	for (size_t i = 0; i < copy.size(); i++)
		std::cout << copy[i] << ' ';
	std::cout << std::endl;
	
	//RELATIONAL OPERATORS
	std::cout << "\nRELATIONAL OPERATORS\n";
	std::vector<int> copy_2(copy);
	std::cout << "copy and fill are equal ? " << (copy == fill) << '\n';
	std::cout << "copy and copy_2 are equal ? " << (copy == copy_2) << '\n';

	std::cout << "\nReal Vector\n";
	std::vector<int> real;
	real.assign(5, 7);
	for (std::vector<int>::iterator it = real.begin(); it != real.end(); it++)
		std::cout << *it << " ";
	std::cout << '\n';

	std::cout << std::endl;
	return (0);
}
