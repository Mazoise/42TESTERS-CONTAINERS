/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .empty_main.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/18 15:57:42 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DEQUE_UC.HPP"
#include "hbaudet_utils.hpp"
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
	/* THIS IS A TEMPLATE MAIN
	** WRITE ANY TEST YOU WANT TO PERFORM
	** SAVE IT UNDER 'something_main.cpp'
	** IT WILL BE RUN WITH FT::LIST AND STD::LIST
	** BOTH OUTPUTS WILL BE COMPARED
	*/

	return (0);
}
