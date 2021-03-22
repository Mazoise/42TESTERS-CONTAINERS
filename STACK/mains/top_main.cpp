/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/18 16:49:07 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "STACK_UC.HPP"
#include <list>
#include "LIST_UC.HPP"
#include "test_utils.hpp"
#include <stack>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

int main ()
{
  stack<int> mystack;

  mystack.push(10);
  mystack.push(20);

  mystack.top() -= 5;

  cout << "mystack.top() is now " << mystack.top() << '\n';

  return 0;
}
