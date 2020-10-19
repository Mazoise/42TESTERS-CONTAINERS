/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:03:48 by hbaudet           #+#    #+#             */
/*   Updated: 2020/10/19 10:04:33 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "List.hpp"

List::List()
{
	if (PRINT)
		std::cout << "Constructor called";
}

List::~List()
{
	if (PRINT)
		std::cout << "Destructor called";
}

List::List(const List& obj)
{
	if (PRINT)
		std::cout << "Copy Constructor called";
	*this = obj;
}

List&	List::operator=(const List& obj)
{
	if (PRINT)
		std::cout << "Assignation operator called";
	return *this;
}

