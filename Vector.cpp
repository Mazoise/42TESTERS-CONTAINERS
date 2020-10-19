/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:03:48 by hbaudet           #+#    #+#             */
/*   Updated: 2020/10/19 10:05:56 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"

Vector::Vector()
{
	if (PRINT)
		std::cout << "Constructor called";
}

Vector::~Vector()
{
	if (PRINT)
		std::cout << "Destructor called";
}

Vector::Vector(const Vector& obj)
{
	if (PRINT)
		std::cout << "Copy Constructor called";
	*this = obj;
}

Vector&	Vector::operator=(const Vector& obj)
{
	if (PRINT)
		std::cout << "Assignation operator called";
	return *this;
}

