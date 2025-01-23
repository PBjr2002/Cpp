/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:09:02 by pauberna          #+#    #+#             */
/*   Updated: 2025/01/23 12:29:46 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <climits>
# include <fstream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
public:
	Cure();
	~Cure();
	Cure(const Cure &copy);
	Cure	&operator=(const Cure &copy);
	Cure	*clone() const;
	void	use(ICharacter &target);
};

#endif