/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:08:09 by pauberna          #+#    #+#             */
/*   Updated: 2025/01/21 14:53:14 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <climits>
# include "Animal.hpp"
# include "Brain.hpp"
# include "AAnimal.hpp"

class Dog : public AAnimal
{
private:
	Brain	*_brain;
public:
	Dog();
	~Dog();
	Dog(Dog &copy);
	Dog	&operator=(Dog &copy);
	void	makeSound() const;
	void	setIdeas(std::string idea);
	void	printIdeas();
};

#endif