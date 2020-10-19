/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List_copy.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:03:47 by hbaudet           #+#    #+#             */
/*   Updated: 2020/10/19 10:03:48 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

#ifdef DEBUG
# define PRINT 1
#else
# define PRINT 0
#endif

class List
{
		private:

		public:
			List();
			List(const List&);
			~List();
			List&	operator=(const List&);
};
