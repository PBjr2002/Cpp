/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-02 16:39:28 by pauberna          #+#    #+#             */
/*   Updated: 2025-04-02 16:39:28 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	std::cout<<GREEN<<"Default constructor called"<<RESET<<std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	std::cout<<YELLOW<<"Copy constructor called"<<RESET<<std::endl;
	*this = copy;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &copy)
{
	std::cout<<YELLOW<<"Copy assignment operator called"<<RESET<<std::endl;
	if (this != &copy)
	{
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
	std::cout<<RED<<"Destructor called"<<RESET<<std::endl;
}
