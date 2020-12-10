/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:03:48 by hbaudet           #+#    #+#             */
/*   Updated: 2020/12/10 12:11:20 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "../ReverseIterator.hpp"
#include "../enable_if.hpp"

#ifdef DEBUG
# define PRINT 1
#else
# define PRINT 0
#endif

namespace ft
{
	static std::ostream& cout = std::cout;

	typedef std::string			string;
	typedef	std::endl			endl;
	typedef	std::boolalpha		boolalpha;

	class Map
	{
			private:

			public:
				Map();
				Map(const Map&);
				~Map();
				Map&	operator=(const Map&);
	};
}