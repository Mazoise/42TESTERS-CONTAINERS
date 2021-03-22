/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unique_main.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/18 16:03:37 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"
#include "LIST_UC.HPP"
#include <list>
#include <cmath>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

template <class T>
void	print(list<T>& lst)
{
	for (typename list<T>::iterator it = lst.begin(); it != lst.end(); it++)
		cout << *it << " ";
	cout << '\n';
}


// a predicate implemented as a function:
bool single_digit (const int& value) { return (value < 10); }
bool too_high (const int& value) { return (value > 2147483647); }
bool first_b (const string& value) { return (value[0] == 'b'); }

// a predicate implemented as a class:
struct is_odd {
  bool operator() (const int& value) { return (value % 2) == 1; }
};

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
  bool operator() (double first, double second)
  { return (fabs(first-second)<5.0); }
};

int main ()
{
  double mydoubles[]={ 12.15,  2.72, 73.0,  12.77,  3.14,
                       12.77, 73.35, 72.25, 15.3,  72.25 };
  list<double> mylist (mydoubles,mydoubles+10);
  
  cout << "Sort :\n";
  mylist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
                             // 15.3,  72.25, 72.25, 73.0,  73.35
  cout << "unique() :\n";
  mylist.unique();           //  2.72,  3.14, 12.15, 12.77
                             // 15.3,  72.25, 73.0,  73.35
  cout <<  "unique(pred_function) :\n";
  mylist.unique(same_integral_part);  //  2.72,  3.14, 12.15
                                       // 15.3,  72.25, 73.0

  cout << "uniuqe(pred_struct) :\n";
  mylist.unique (is_near());           //  2.72, 12.15, 72.25

  cout << "mylist contains:";
  for (list<double>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    cout << ' ' << *it;
  cout << '\n';

  return 0;
}
