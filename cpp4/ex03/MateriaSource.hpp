/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:34:54 by pauberna          #+#    #+#             */
/*   Updated: 2025/01/23 14:46:46 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <climits>
# include <fstream>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria	*_materia[4];
public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(MateriaSource &copy);
	MateriaSource	&operator=(MateriaSource &copy);
	void	learnMateria(AMateria*);
	AMateria*	createMateria(std::string const & type);
};

#endif