/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseIterator_main.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/18 16:01:20 by hbaudet          ###   ########.fr       */
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

int main()
{
	deque<float> lst;

	for (int i = 0; i < 7; i++)
		lst.push_back(i * 3.75f);

	deque<float>::reverse_iterator	rit(lst.begin());
	deque<float>::reverse_iterator	rit2(lst.end());

	rit--;
	rit2--;
	while (rit != rit2)
	{
		std::cout << *rit << ' ' << '\n';
		--rit;
	}



	return (0);
}
