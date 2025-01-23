/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:31:43 by pauberna          #+#    #+#             */
/*   Updated: 2025/01/23 15:07:59 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <climits>
# include <fstream>
# include "AMateria.hpp"
# include "ICharacter.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

class Character : public ICharacter
{
private:
	std::string	_name;
	AMateria	*_inv[4];
public:
	Character();
	Character(std::string name);
	~Character();
	Character(Character &copy);
	Character	&operator=(Character &copy);
	std::string const	&getName() const;
	void	equip(AMateria *m);
	void	unequip(int idx);
	void	use(int idx, ICharacter& target);
};

#endif