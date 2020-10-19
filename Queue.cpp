/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:03:50 by hbaudet           #+#    #+#             */
/*   Updated: 2020/10/19 10:05:10 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Queue.hpp"

Queue::Queue()
{
	if (PRINT)
		std::cout << "Constructor called";
}

Queue::~Queue()
{
	if (PRINT)
		std::cout << "Destructor called";
}

Queue::Queue(const Queue& obj)
{
	if (PRINT)
		std::cout << "Copy Constructor called";
	*this = obj;
}

Queue&	Queue::operator=(const Queue& obj)
{
	if (PRINT)
		std::cout << "Assignation operator called";
	return *this;
}

