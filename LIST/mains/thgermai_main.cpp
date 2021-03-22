/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thgermai_main.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/02/05 16:33:26 by hbaudet          ###   ########.fr       */
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

template <class T>
void	print(list<list<T> >& lst)
{
	for (typename list<list<T> >::iterator it = lst.begin(); it != lst.end(); it++)
	{
		for (typename list<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
			cout << *it2 << ' ';
		cout << '\n';
	}
}

template <class T>
void	print(list<T>& lst)
{
	for (typename list<T>::iterator it = lst.begin(); it != lst.end(); it++)
		cout << *it << ' ';
	cout << '\n';
}

static void			assignment_test()
{
	list<int>			l;
	list<int>			l2((size_t)10, 42);
	list<int>			cpy = l;
	print(cpy);
	print(l2);
	cpy = l2;
	print(cpy);
	cout << std::endl;
}

static void			begin_rbegin_test()
{
	list<int>		l;
	l.push_back(5);
	while (l.back())
	{
		l.push_back(l.back() - 1);
	}
	print(l);
	cout << "Create list<int>::iterator it = begin() and compare with real" << std::endl;
	list<int>::iterator		it = l.begin();
	cout << *it << '\n';
	list<int>::reverse_iterator		rit = l.rbegin();
	cout << *rit << '\n';
}

static void			end_rend_test()
{
	list<int>		l;
	l.push_back(5);
	while (l.back())
		l.push_back(l.back() - 1);
	print(l);
	cout << "Create list<int>::iterator it = end() and compare with real" << std::endl;
	list<int>::iterator		it = l.end();
	cout << *(--it) << '\n';

	list<int>::reverse_iterator		rit = l.rend();
	cout << *(--rit) << '\n';
	
}

static void			empty_size_test()
{
	list<int>			l;
	cout << "testing empty and size on empty list" << std::endl;
	cout << l.size() << '\n';
	cout << l.empty() << '\n';
	cout << "testing empty and size on a 15 element list" << std::endl;
	l.assign((size_t)15, 42);
	cout << l.size() << '\n';
	cout << l.empty() << '\n';
}

static void			assign_test()
{
	list<std::string>			l;
	l.assign((size_t)10, "salut");
	print(l);
	list<std::string>			l2;
	l2.assign(++l.begin(), --l.end());
	print(l2);
	cout << std::endl;
}

static void			push_pop_front_test()
{
	list<int>				l;
	cout << "Creating list by pushing front 10 and then pushing front() - 1 until front() == 0" << std::endl;
	l.push_front(10);
	while (l.front())
		l.push_front(l.front() - 1);
	print(l);
	cout << "Poping front 5 times for each list" << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		l.pop_front();
	}
	print(l);
	cout << std::endl;
}

static void			push_pop_back_test()
{
	list<int>				l;
	cout << "Creating list by pushing back 10 and then pushing back() - 1 until back() == 0" << std::endl;
	l.push_back(10);
	while (l.back())
		l.push_back(l.back() - 1);
	print(l);
	cout << "Poping back 5 times for each list" << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		l.pop_back();
	}
	print(l);
	cout << std::endl;
}

static void			insert_test()
{
	list<int>		l;

	l.insert(l.begin(), 42);
	print(l);
	l.push_back(10);
	while (l.back())
		l.push_back(l.back() - 1);
	list<int>::iterator		it = l.begin();
	for (int i = 0; i < 5; ++i)
	{
		++it;
	}
	l.insert(it, 42);
	print(l);
	l.insert(it, (size_t)5, 21);
	print(l);
	cout << std::endl;
}

static void			erase_test()
{
	list<int>			l;
	l.push_back(10);
	while (l.back())
		l.push_back(l.back() - 1);
	list<int>::iterator			it = l.begin();
	for (int i = 0; i < 4; ++i)
	{
		++it;
	}
	l.erase(it);
	print(l);
	l.erase(l.begin(), l.end());
	print(l);
}

static void			swap_test()
{
	list<int>			l;
	list<int>			l2;
	l.push_back(10);
	while (l.back())
	{
		l.push_back(l.back() - 1);
	}
	l2.push_front(4);
	while (l2.front())
	{
		l2.push_front(l2.front() - 1);
	}
	l.swap(l2);
	print(l);
	swap(l2, l);
	print(l2);
	cout << std::endl;
}

static void			resize_test()
{
	list<int>		l;
	l.push_back(10);
	while (l.back())
	{
		l.push_back(l.back() - 1);
	}
	l.resize(15);
	print(l);
	l.resize(5);
	print(l);
	l.resize(10, 42);
	print(l);
	cout << std::endl;
}

static void			clear_test()
{
	list<int>		l;
	l.push_back(10);
	while (l.back())
	{
		l.push_back(l.back() - 1);
	}
	l.clear();
	print(l);
	l.clear();
	print(l);
	cout << std::endl;
}

static void			splice_test()
{
	list<int>		l;
	list<int>		l2;
	l.push_back(10);
	l2.push_back(30);
	while (l.back())
	{
		l.push_back(l.back() - 1);
	}
	while (l2.front())
	{
		l2.push_front(l2.front() - 3);
	}
	list<int>::iterator			it = l.begin();
	for (int i = 0; i < 3; ++i)
	{
		++it;
	}
	list<int>		l3(l);
	l.splice(it, l2);
	print(l);
	list<int>::iterator			it2 = l3.begin();
	for (int i = 0; i < 3; ++i)
	{
		++it2;
	}
	l.splice(it, l3, it2);
	print(l);
	l.splice(l.begin(), l3, l3.begin(), l3.end());
	print(l);
	cout << std::endl;
}

static void			remove_test()
{
	list<int>		l;
	l.push_back(10);
	while (l.back())
	{
		l.push_back(l.back() - 1);
		l.insert(--l.end(), 42);
	}
	l.remove(42);
	print(l);
	cout << std::endl;
}

static bool 		comp(int a)
{
	return (a - 2 > 5);
}

static void			remove_if_test()
{
	list<int>		l;
	l.push_back(10);
	l.push_back(9);
	l.push_back(6);
	l.push_back(4);
	l.push_back(12);
	l.push_back(1);
	l.remove_if(comp);
	print(l);
	cout << std::endl;
}

static bool			comp2(int a, int b)
{
	return a < b;
}

static void			unique_sort_merge_reverse_test()
{
	list<int>		l;
	list<int>		l2;
	for (int i = 0; i < 30; ++i)
	{
		l.push_back(2147483647);
		l2.push_back(-2147483648);
	}
	l.sort();
	print(l);
	l2.sort(comp2);
	print(l2);
	l.merge(l2);
	print(l);
	l.unique();
	print(l);
	l.reverse();
	print(l);
	cout << std::endl;
}

int main()
{
	assignment_test();
	begin_rbegin_test();
	end_rend_test();
	empty_size_test();
	assign_test();
	push_pop_front_test();
	push_pop_back_test();
	insert_test();
	erase_test();
	swap_test();
	resize_test();
	clear_test();
	splice_test();
	remove_test();
	remove_if_test();
	unique_sort_merge_reverse_test();
	return 0;
}
