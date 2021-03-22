/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/18 16:04:18 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"
#include "LIST_UC.HPP"
#include <list>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

// compare only integral part:
bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

int main ()
{
  list<double> first, second;

  first.push_back (3.1);
  first.push_back (2.2);
  first.push_back (2.9);

  second.push_back (3.7);
  second.push_back (7.1);
  second.push_back (1.4);

  first.sort();
  second.sort();


  cout << "first contains:";
  for (list<double>::iterator it=first.begin(); it!=first.end(); ++it)
    cout << ' ' << *it;
  cout << '\n';

  first.merge(second);


  cout << "first contains:";
  for (list<double>::iterator it=first.begin(); it!=first.end(); ++it)
    cout << ' ' << *it;
  cout << '\n';
  // (second is now empty)

  second.push_back (2.1);

  first.merge(second,mycomparison);

  cout << "first contains:";
  for (list<double>::iterator it=first.begin(); it!=first.end(); ++it)
    cout << ' ' << *it;
  cout << '\n';

  return 0;
}
