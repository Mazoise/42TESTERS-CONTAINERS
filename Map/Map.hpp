/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:03:48 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/04 13:20:00 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "../utils.hpp"
#include "NodeIterator.hpp"
#include "Node_pair.hpp"

#ifdef DEBUG
# define PRINT 1
#else
# define PRINT 0
#endif

namespace ft
{
	template <class K, class V>
	class map
	{
			private:
				node_pair<K, V>	root;

			public:
				map();
				map(const node_pair<K, V>& node): root(node) {}
				map(const pair<K, V>& pair)
				{
					node_pair<K, V>	tmp(pair);
					this->root = tmp;
				}
				map(const map&);
				~map() {};
				map&	operator=(const map&);
				node_pair<K, V>&	getMember()
				{
					return this->root;
				}
				const node_pair<K, V>&	getMember() const
				{
					return this->root;
				}
	};
}
