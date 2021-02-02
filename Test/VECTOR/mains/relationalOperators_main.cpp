/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relationalOperators_main.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/18 16:07:08 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"
#include "VECTOR_UC.HPP"
#include <vector>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

int main ()
{
  vector<int> foo (3,100);   // three ints with a value of 100
  vector<int> bar (2,200);   // two ints with a value of 200

  if (foo==bar) cout << "foo and bar are equal\n";
  if (foo!=bar) cout << "foo and bar are not equal\n";
  if (foo< bar) cout << "foo is less than bar\n";
  if (foo> bar) cout << "foo is greater than bar\n";
  if (foo<=bar) cout << "foo is less than or equal to bar\n";
  if (foo>=bar) cout << "foo is greater than or equal to bar\n";

  return 0;
}
