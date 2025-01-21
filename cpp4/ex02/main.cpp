/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:50:24 by pauberna          #+#    #+#             */
/*   Updated: 2025/01/21 15:00:36 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "AAnimal.hpp"

int	main(void)
{
	Animal	*normal = new Animal();
	AAnimal *abstract = new Cat();
	//AAnimal	*errado = new AAnimal();
	normal->makeSound();
	abstract->makeSound();
	delete normal;
	delete abstract;
	return (0);
}