/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:36:11 by pauberna          #+#    #+#             */
/*   Updated: 2025/01/23 12:29:09 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <climits>
# include <fstream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
public:
	Ice();
	~Ice();
	Ice(const Ice &copy);
	Ice	&operator=(const Ice &copy);
	Ice	*clone() const;
	void	use(ICharacter &target);
};

#endif