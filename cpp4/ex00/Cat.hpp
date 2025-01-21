/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:08:26 by pauberna          #+#    #+#             */
/*   Updated: 2025/01/21 11:59:41 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <climits>
# include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	~Cat();
	Cat(Cat &copy);
	Cat	&operator=(Cat &copy);
	void	makeSound() const;
};

#endif