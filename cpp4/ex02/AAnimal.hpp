/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:45:01 by pauberna          #+#    #+#             */
/*   Updated: 2025/01/21 14:59:47 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <climits>
# include <fstream>

class AAnimal
{
protected:
	std::string	_type;
public:
	AAnimal();
	virtual ~AAnimal() = 0;
	AAnimal(AAnimal &copy);
	AAnimal	&operator=(AAnimal &copy);
	std::string	getType() const;
	virtual void	makeSound() const = 0;
};

#endif