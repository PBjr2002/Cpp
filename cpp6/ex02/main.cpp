/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-11 18:20:30 by pauberna          #+#    #+#             */
/*   Updated: 2025-02-11 18:20:30 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	int	i = rand() % 3;
	switch (i)
	{
	case 0:
		return (new A);
	case 1:
		return (new B);
	default:
		return (new C);
	}
}

void	identify(Base *p)
{
	A	*a = dynamic_cast<A*>(p);
	if (a)
		std::cout<<"A"<<std::endl;
	B	*b = dynamic_cast<B*>(p);
	if (b)
		std::cout<<"B"<<std::endl;
	C	*c = dynamic_cast<C*>(p);
	if (c)
		std::cout<<"C"<<std::endl;
}

void	identify(Base &p)
{
	try
	{
		A	&a =dynamic_cast<A&>(p);
		std::cout<<"A"<<std::endl;
		(void)a;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		B	&b = dynamic_cast<B&>(p);
		std::cout<<"B"<<std::endl;
		(void)b;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		C	&c = dynamic_cast<C&>(p);
		std::cout<<"C"<<std::endl;
		(void)c;
	}
	catch(const std::exception& e)
	{
	}
}

int	main(void)
{
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		Base	*ptr = generate();
		Base	&ref = *ptr;
		std::cout<<"Executing identify ptr:"<<std::endl;
		identify(ptr);
		std::cout<<"Executing identify ref:"<<std::endl;
		identify(ref);
		delete ptr;
	}
	return (0);
}
