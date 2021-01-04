/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:07:47 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/04 13:19:26 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Map.hpp"

#ifdef STD
# define NAMESPACE std
#else
# define NAMESPACE ft
#endif

using namespace NAMESPACE;

int main()
{
	pair<string, int>	my_pair("salut", 42);
	map<string, int>	test(my_pair);

	cout << test.getMember().getMember().first << " " << test.getMember().getMember().second << '\n';
}