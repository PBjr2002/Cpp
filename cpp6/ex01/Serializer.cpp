/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-11 15:19:04 by pauberna          #+#    #+#             */
/*   Updated: 2025-02-11 15:19:04 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout<<GREEN"Serializer Default constructor called" RESET<<std::endl;
}

Serializer::Serializer(Serializer &copy)
{
	std::cout<<YELLOW"Serializer Copy constructor called" RESET<<std::endl;
	*this = copy;
}

Serializer::~Serializer()
{
	std::cout<<RED"Serializer destructor called" RESET<<std::endl;
}

Serializer&	Serializer::operator=(Serializer &copy)
{
	std::cout<<YELLOW"Serializer Copy assignment operator called" RESET<<std::endl;
	(void)copy;
	return (*this);
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data		*Serializer::deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data*>(raw));
}
