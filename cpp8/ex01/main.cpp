/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-18 11:00:30 by pauberna          #+#    #+#             */
/*   Updated: 2025-03-18 11:00:30 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	srand(time(NULL));
	Span	sp = Span(20);

	sp.fillSpan();
	std::cout<<std::endl;
	try
	{
		std::cout<<"ShortestSpan: "<<sp.shortestSpan()<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout<<"LongestSpan: "<<sp.longestSpan()<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
