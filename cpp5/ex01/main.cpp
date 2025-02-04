/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 10:49:04 by pauberna          #+#    #+#             */
/*   Updated: 2025-02-04 10:49:04 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	person1("General", 1);
	Bureaucrat	person2("Harl", 150);

	std::cout<<person1<<std::endl;
	std::cout<<person2<<std::endl<<std::endl;

	try
	{
		std::cout<<"Trying increment "<<person1.getName()<<" :"<<std::endl;
		person1.increment();
	}
	catch(const std::exception& e)
	{
		std::cerr<< YELLOW"Exception Caught : " << e.what() << "\n"RESET;
	}
	std::cout<<person1<<std::endl<<std::endl;

	try
	{
		std::cout<<"Trying decrement "<<person1.getName()<<" :"<<std::endl;
		person1.decrement();
	}
	catch(const std::exception& e)
	{
		std::cerr<< YELLOW"Exception Caught : " << e.what() << "\n"RESET;
	}
	std::cout<<person1<<std::endl<<std::endl;

	try
	{
		std::cout<<"Trying decrement "<<person2.getName()<<" :"<<std::endl;
		person2.decrement();
	}
	catch(const std::exception& e)
	{
		std::cerr<< YELLOW"Exception Caught : " << e.what() << "\n"RESET;
	}
	std::cout<<person2<<std::endl<<std::endl;

	try
	{
		std::cout<<"Trying increment "<<person2.getName()<<" :"<<std::endl;
		person2.increment();
	}
	catch(const std::exception& e)
	{
		std::cerr<< YELLOW"Exception Caught : " << e.what() << "\n"RESET;
	}
	std::cout<<person2<<std::endl;

	try
	{
		Bureaucrat	wrong("Wrong", -1);
	}
	catch(const std::exception& e)
	{
		std::cerr << YELLOW"Exception Caught :" << e.what() << "\n"RESET;
	}

	try
	{
		Bureaucrat	wrong2("Wrong2", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << YELLOW"Exception Caught :" << e.what() << "\n"RESET;
	}
	
	return (0);
}
