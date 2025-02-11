/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-10 14:32:38 by pauberna          #+#    #+#             */
/*   Updated: 2025-02-10 14:32:38 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout<<RED<<"Please insert only 1 char/int/float/double"<<RESET<<std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);
	return (0);
}
