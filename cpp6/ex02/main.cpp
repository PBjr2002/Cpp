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

}

void	identify(Base &p)
{

}

int	main(void)
{
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		Base	*ptr = generate();
		Base	&ref = *ptr;
		identify(ptr);
		identify(ref);
		delete ptr;
	}
	return (0);
}
