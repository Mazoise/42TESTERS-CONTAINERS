/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:03:49 by hbaudet           #+#    #+#             */
/*   Updated: 2020/10/19 10:05:29 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Stack.hpp"

Stack::Stack()
{
	if (PRINT)
		std::cout << "Constructor called";
}

Stack::~Stack()
{
	if (PRINT)
		std::cout << "Destructor called";
}

Stack::Stack(const Stack& obj)
{
	if (PRINT)
		std::cout << "Copy Constructor called";
	*this = obj;
}

Stack&	Stack::operator=(const Stack& obj)
{
	if (PRINT)
		std::cout << "Assignation operator called";
	return *this;
}

