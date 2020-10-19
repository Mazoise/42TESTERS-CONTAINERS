/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:03:49 by hbaudet           #+#    #+#             */
/*   Updated: 2020/10/19 10:04:53 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Map.hpp"

Map::Map()
{
	if (PRINT)
		std::cout << "Constructor called";
}

Map::~Map()
{
	if (PRINT)
		std::cout << "Destructor called";
}

Map::Map(const Map& obj)
{
	if (PRINT)
		std::cout << "Copy Constructor called";
	*this = obj;
}

Map&	Map::operator=(const Map& obj)
{
	if (PRINT)
		std::cout << "Assignation operator called";
	return *this;
}

