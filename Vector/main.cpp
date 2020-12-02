/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2020/12/02 18:17:09 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include <vector>

int main()
{
	ft::vector<int> empty;
	ft::vector<int> fill(5, 8);
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
	copy.reserve(42);
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
	//assign range
	std::cout << "fill is empty ? " << fill.empty() << '\n';
	std::cout << "fill at(41) : " << fill.at(41) << '\n';

	//PUSH/POP_BACK
	std::cout << "\nPUSH/POP_BACK\n";
	fill.push_back(53);
	std::cout << "last elem of fill : " << fill.back() << '\n';
	fill.pop_back();
	std::cout << "last elem of fill : " << fill.back() << '\n';

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
	

	std::cout << std::endl;
	return (0);
}
