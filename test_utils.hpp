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

#ifndef TEST_UTILS_HPP
# define TEST_UTILS_HPP

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


# ifndef TO_STRING
#  define TO_STRING
	string	to_string(size_t n)
	{
		std::stringstream tmp;

		tmp << n;

		return tmp.str();
	}
# endif
}

#endif