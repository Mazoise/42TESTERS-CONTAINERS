/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .empty_main.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/18 16:04:59 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hbaudet_utils.hpp"
#include "MAP_UC.HPP"
#include <map>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

template <class Key, class T>
void	print(map<Key, T>& lst)
{
	for (typename map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		cout << it->first << " => " << it->second << '\n';
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
