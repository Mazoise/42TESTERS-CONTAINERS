/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boolSwap_main.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/18 16:07:36 by hbaudet          ###   ########.fr       */
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
   vector<bool> foo;
   vector<bool> bar;

  foo.push_back(false);
  foo.push_back(true);
  foo.push_back(false);

  bar.push_back(true);
  bar.push_back(false);

  foo.swap (foo[0], foo[1]);
  bar.swap (bar.front(), bar.back());

  foo.swap(bar);

   cout <<  std::boolalpha;
   cout << "foo contains:";
  for (unsigned i=0; i<foo.size(); i++)  cout << ' ' << foo[i];
   cout << "\nbar contains:";
  for (unsigned i=0; i<bar.size(); i++)  cout << ' ' << bar[i];
   cout << '\n';

  return 0;
}
