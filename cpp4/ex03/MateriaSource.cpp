/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:35:06 by pauberna          #+#    #+#             */
/*   Updated: 2025/01/23 15:00:48 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout<<"\033[1m\033[32mMateriaSource Default constructor called\033[0m"<<std::endl;
	for (int i = 0; i < 4; i++)
		_materia[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	std::cout<<"\033[1m\033[31mMateriaSource Destructor called\033[0m"<<std::endl;
	for (int i = 0; i < 4; i++)
		if (_materia[i])
			delete _materia[i];
}

MateriaSource::MateriaSource(MateriaSource &copy)
{
	std::cout<<"\033[1m\033[33mMateriaSource Copy constructor called\033[0m"<<std::endl;
	*this = copy;
}

MateriaSource	&MateriaSource::operator=(MateriaSource &copy)
{
	std::cout<<"\033[1m\033[33mMateriaSource Copy assignment operator called\033[0m"<<std::endl;
	if (this != &copy)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_materia[i])
				delete _materia[i];
			if (copy._materia[i])
				_materia[i] = copy._materia[i]->clone();
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
	{
		std::cout<<"There is no AMateria to learn"<<std::endl;
		return ;
	}
	int	i = 0;
	while (i < 4 && _materia[i])
		i++;
	if (i < 4)
	{
		_materia[i] = m;
		std::cout<<"Learned "<<_materia[i]->getType()<<std::endl;
	}
	else
		std::cout<<"There is no more space to learn AMaterias"<<std::endl;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materia[i] && _materia[i]->getType() == type)
		{
			std::cout<<"Created "<<_materia[i]->getType()<<std::endl;
			return (_materia[i]->clone());
		}
	}
	std::cout<<"That AMateria type is unknown"<<std::endl;
	return (0);
}
