/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/18 16:03:39 by hbaudet          ###   ########.fr       */
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

int main ()
{
  list<int> first (3,100);   // three ints with a value of 100
  list<int> second (5,200);  // five ints with a value of 200

  first.swap(second);

  cout << "first contains:";
  for (list<int>::iterator it=first.begin(); it!=first.end(); it++)
    cout << ' ' << *it;
  cout << '\n';

  cout << "second contains:";
  for (list<int>::iterator it=second.begin(); it!=second.end(); it++)
    cout << ' ' << *it;
  cout << '\n';

  return 0;
}
