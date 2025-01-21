/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:04:15 by pauberna          #+#    #+#             */
/*   Updated: 2025/01/21 12:36:43 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <climits>
# include <fstream>

class WrongAnimal
{
protected:
	std::string	_type;
public:
	WrongAnimal();
	virtual	~WrongAnimal();
	WrongAnimal(WrongAnimal &copy);
	WrongAnimal	&operator=(WrongAnimal &copy);
	std::string		getType() const;
	void	makeSound() const;
};

#endif
