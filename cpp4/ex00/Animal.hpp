/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:51:05 by pauberna          #+#    #+#             */
/*   Updated: 2025/01/21 12:02:20 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <climits>
# include <fstream>

class Animal
{
protected:
	std::string	_type;
public:
	Animal();
	virtual ~Animal();
	Animal(Animal &copy);
	Animal	&operator=(Animal &copy);
	std::string	getType() const;
	virtual void	makeSound() const;
};

#endif