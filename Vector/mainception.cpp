/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2020/12/08 14:33:27 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include <vector>

int main()
{
	ft::vector<int> empty;
	ft::vector<int> fill(5, 8);
	std::cout << "fill(5, 8) : ";
	for (size_t i = 0; i < fill.size(); i++)
		std::cout << fill[i] << ' ';
	std::cout << '\n';
	ft::vector<int> copy(fill);
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
		<< " time more than ft::vector" << std::endl;
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
	ft::vector<int>	assign_range;
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
	ft::vector<int>	insert_in_me;
	for (int i = 0; i < 15; i++)
		insert_in_me.push_back(i);
	for (size_t i = 0; i < insert_in_me.size(); i++)
		std::cout << insert_in_me.at(i) << ' ';
	std::cout << '\n';

	ft::VectorIterator<int>	tmp;
	tmp = insert_in_me.begin() + 4;
	insert_in_me.insert(tmp, 8, 42);
	for (size_t i = 0; i < insert_in_me.size(); i++)
		std::cout << insert_in_me.at(i) << ' ';
	std::cout << '\n';


	//INSERT RANGE
	std::cout << "\nINSERT RANGE\n";
	ft::vector<int>	insert_bis;
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
	ft::vector<int>	erase_in_me;
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
	ft::swap(fill, copy);
	std::cout << "Size of fill " << fill.size() << std::endl;
	std::cout << "Capacity of fill " << fill.capacity() << std::endl;
	std::cout << "Size of copy " << copy.size() << std::endl;
	std::cout << "Capacity of copy " << copy.capacity() << std::endl;
	for (size_t i = 0; i < copy.size(); i++)
		std::cout << copy[i] << ' ';
	std::cout << std::endl;
	
	//RELATIONAL OPERATORS
	std::cout << "\nRELATIONAL OPERATORS\n";
	ft::vector<int> copy_2(copy);
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
