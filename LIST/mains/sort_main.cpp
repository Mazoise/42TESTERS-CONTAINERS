/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/18 16:03:48 by hbaudet          ###   ########.fr       */
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

#include <cctype>

// comparison, not case sensitive.
bool compare_nocase (const string& first, const string& second)
{
  unsigned int i=0;
  while ( (i<first.length()) && (i<second.length()) )
  {
    if (tolower(first[i])<tolower(second[i])) return true;
    else if (tolower(first[i])>tolower(second[i])) return false;
    ++i;
  }
  return ( first.length() < second.length() );
}

int main ()
{
  list<string> mylist;
  list<string>::iterator it;
  mylist.push_back ("one");
  mylist.push_back ("two");
  mylist.push_back ("Three");

  mylist.sort();

  cout << "mylist contains:";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    cout << ' ' << *it;
  cout << '\n';

  mylist.sort(compare_nocase);

  cout << "mylist contains:";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    cout << ' ' << *it;
  cout << '\n';

  mylist.reverse();
  cout << "mylist contains:";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    cout << ' ' << *it;
  cout << '\n';

  mylist.sort();
   cout << "mylist contains:";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    cout << ' ' << *it;
  cout << '\n';


	list<double>	lst;
	list<double>::iterator	it2;

	for (double i = 1.5; i < 14.7; i *= -2.3)
	{
		lst.push_front(i * - 3.8);
		lst.push_back(lst.front() * 14.2);
	}

	cout << "lst contains:";
  for (it2 = lst.begin(); it2 != lst.end(); ++it2)
    cout << ' ' << *it2;
  cout << '\n';

	list<double>	lst2(lst);
	lst2.sort();
	cout << "lst2 contains:";
  for (it2 = lst2.begin(); it2 != lst2.end(); ++it2)
    cout << ' ' << *it2;
  cout << '\n';
	lst.reverse();
	cout << "lst contains:";
  for (it2 = lst.begin(); it2 != lst.end(); ++it2)
    cout << ' ' << *it2;
  cout << '\n';
	lst.sort();
	cout << "lst contains:";
  for (it2 = lst.begin(); it2 != lst.end(); ++it2)
    cout << ' ' << *it2;
  cout << '\n';
	lst.reverse();
	cout << "lst contains:";
  for (it2 = lst.begin(); it2 != lst.end(); ++it2)
    cout << ' ' << *it2;
  cout << '\n';
	lst.sort();
	cout << "lst contains:";
  for (it2 = lst.begin(); it2 != lst.end(); ++it2)
    cout << ' ' << *it2;
  cout << '\n';


  return 0;
}
