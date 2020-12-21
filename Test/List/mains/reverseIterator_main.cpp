/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseIterator_main.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2020/12/18 19:22:26 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIST.HPP"
#include <list>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

int main()
{
	list<float> lst;

	for (int i = 0; i < 7; i++)
		lst.push_back(i * 3.75f);

	list<float>::reverse_iterator	rit(lst.begin());
	list<float>::reverse_iterator	rit2(lst.end());

	rit--;
	rit2--;
	while (rit != rit2)
	{
		std::cout << *rit << ' ' << '\n';
		--rit;
	}



	return (0);
}