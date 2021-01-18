/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flip_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/18 16:07:27 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hbaudet_utils.hpp"
#include "VECTOR_UC.HPP"
#include <vector>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

template <class T>
void	print(vector<vector<T> >& lst)
{
	for (typename vector<vector<T> >::iterator it = lst.begin(); it != lst.end(); it++)
	{
		for (typename vector<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
			cout << *it2 << ' ';
		cout << '\n';
	}
}

template <class T>
void	print(vector<T>& lst)
{
	for (typename vector<T>::iterator it = lst.begin(); it != lst.end(); it++)
		cout << *it << ' ';
	cout << '\n';
}

int main ()
{
  vector<bool> mask;

  mask.push_back(true);
  mask.push_back(false);
  mask.push_back(false);
  mask.push_back(true);

  mask.flip();

  cout << boolalpha;
  cout << "mask contains:";
  for (unsigned i=0; i<mask.size(); i++)
    cout << ' ' << mask.at(i);
  cout << '\n';

  return 0;
}
