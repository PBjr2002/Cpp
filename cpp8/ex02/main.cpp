/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-19 10:56:10 by pauberna          #+#    #+#             */
/*   Updated: 2025-03-19 10:56:10 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout<<YELLOW<<"1st element of mstack using top: "<<RESET<<mstack.top()<<std::endl;
	mstack.pop();
	std::cout<<YELLOW<<"Size of mstack after using pop: "<<RESET<<mstack.size()<<std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout<<YELLOW<<"Testing the iterators"<<RESET<<std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout<<"mstack: "<<*it<< std::endl;
		++it;
	}
	std::cout<<YELLOW<<"Testing the reverse iterators"<<RESET<<std::endl;
	MutantStack<int>::reverse	rit = mstack.rbegin();
	MutantStack<int>::reverse	rite = mstack.rend();
	while (rit != rite)
	{
		std::cout<<"mstack: "<<*rit<<std::endl;
		++rit;
	}
	std::stack<int> s(mstack);
	return (0);
}
