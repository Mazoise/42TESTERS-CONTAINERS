/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/18 16:07:00 by hbaudet          ###   ########.fr       */
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
  vector<int> foo (3,100);   // three ints with a value of 100
  vector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  cout << "foo contains:";
  for (unsigned i=0; i<foo.size(); i++)
    cout << ' ' << foo[i];
  cout << '\n';

  cout << "bar contains:";
  for (unsigned i=0; i<bar.size(); i++)
    cout << ' ' << bar[i];
  cout << '\n';

{
	vector<int> foo,bar;

	foo.push_back(100);
	foo.push_back(200);

	bar.push_back(11);
	bar.push_back(22);
	bar.push_back(33);


	vector<int>::const_iterator tmp = foo.begin(); //tmp iterates through foo
	vector<int>::const_iterator tmp2 = bar.begin(); //tmp2 iterates through bar

	swap(bar, foo); //tmp iterates through bar
					//tmp2 iterates through foo


	vector<int>	other;

	other.push_back(73);
	other.push_back(173);
	other.push_back(763);
	other.push_back(73854);
	other.push_back(74683);
	other.push_back(753);

	vector<int>::const_iterator tmp3 = other.begin(); // tmp3 iterates through other

	cout << "foo contains:\n";
	for (vector<int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		cout << *it << '\n';

	cout << "bar contains:\n";
	for (vector<int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		cout << *it << '\n';

		while(tmp != bar.end())
		{
			cout << *tmp << '\n';
			tmp++;
		}
		tmp--;

		while(tmp2 != foo.end())
		{
			cout << *tmp2 << '\n';
			tmp2++;
		}
		tmp2--;

		swap(other, foo); //tmp2 iterates through other
						//tmp3 iterates throught foo
		print(other);
		print(foo);
		print(bar);
		while(tmp != bar.begin())
		{
			cout << *tmp << '\n';
			tmp--;
		}
		cout << *tmp << '\n';

		while(tmp2 != other.begin())
		{
			cout << *tmp2 << '\n';
			tmp2--;
		}
			cout << *tmp2 << '\n';

		while(tmp3 != foo.end())
		{
			cout << *tmp3 << '\n';
			tmp3++;
		}
		tmp3--;

		swap(bar, foo);
		swap(foo, bar);
		swap(bar, foo); //tmp3 iterates through bar
					//tmp iterates through foo

		print(other);
		print(foo);
		print(bar);

		while(tmp != foo.end())
		{
			cout << *tmp << '\n';
			tmp++;
		}

		while(tmp2 != other.end())
		{
			cout << *tmp2 << '\n';
			tmp2++;
		}

		while(tmp3 != bar.begin())
		{
			cout << *tmp3 << '\n';
			tmp3--;
		}
			cout << *tmp3 << '\n';
}

  return 0;
}
