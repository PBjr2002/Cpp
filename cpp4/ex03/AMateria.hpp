/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:19:40 by pauberna          #+#    #+#             */
/*   Updated: 2025/01/23 15:08:57 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <climits>
# include <fstream>
# include "ICharacter.hpp"

class AMateria
{
protected:
	std::string	_type;
public:
	AMateria();
	AMateria(std::string const &type);
	virtual ~AMateria() = 0;
	AMateria(AMateria &copy);
	AMateria	&operator=(AMateria &copy);
	std::string const	&getType() const;
	virtual AMateria*	clone() const = 0;
	virtual void	use(ICharacter &target);
};

#endif