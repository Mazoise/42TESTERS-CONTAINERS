/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hbaudet_utils.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:20:31 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/18 15:54:58 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HBAUDET_UTILS_HPP
# define HBAUDET_UTILS_HPP

# include <iostream>
# include <string>
# include <sstream>

# ifdef DEBUG
#  define PRINT 1
#  else
#  define PRINT 0
# endif


namespace ft
{
	static std::ostream& 									cout = std::cout;
	typedef std::string										string;


	string	to_string(size_t n)
	{
		std::stringstream tmp;

		tmp << n;

		return tmp.str();
	}

	template <bool flag, class IsTrue, class IsFalse>
		struct choose;

	template <class IsTrue, class IsFalse>
		struct choose<true, IsTrue, IsFalse>
		{
			typedef IsTrue type;
		};

	template <class IsTrue, class IsFalse>
		struct choose<false, IsTrue, IsFalse>
		{
			typedef IsFalse type;
		};

	template<bool B, class T = void>
		struct enable_if {};

	template<class T>
		struct enable_if<true, T> { typedef T type; };

	
}

#endif