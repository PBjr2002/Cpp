/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:50:24 by pauberna          #+#    #+#             */
/*   Updated: 2025/01/21 14:14:07 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int	main(void)
{
	Animal	*animals[] =
	{
		new Dog(),
		new Dog(),
		new Cat(),
		new Cat(),
	};
	for (int i = 0; i < 4; i++)
	{
		delete animals[i];
	}
	Dog	*dog = new Dog();
	Cat	*cat = new Cat();
	dog->printIdeas();
	cat->printIdeas();
	dog->setIdeas("yey my human!!!");
	cat->setIdeas("eewww my human...");
	dog->printIdeas();
	cat->printIdeas();
	delete dog;
	delete cat;
	return (0);
}