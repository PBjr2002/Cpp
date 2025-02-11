/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-11 17:49:29 by pauberna          #+#    #+#             */
/*   Updated: 2025-02-11 17:49:29 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data	*data = new Data;
	data->name = "bob";
	uintptr_t	ptr = Serializer::serialize(data);
	Data		*sData = Serializer::deserialize(ptr);

	std::cout<<"data name: "<<data->name<<std::endl;
	std::cout<<"data ptr: "<<data<<std::endl;
	std::cout<<"ptr: "<<ptr<<std::endl;
	std::cout<<"sData ptr: "<<sData<<std::endl;
	std::cout<<"sData name: "<<sData->name<<std::endl;

	delete data;

	return (0);
}
