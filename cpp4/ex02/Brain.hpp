/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:23:47 by pauberna          #+#    #+#             */
/*   Updated: 2025/01/21 14:12:12 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <climits>
# include <fstream>

# define NUM 2

class Brain
{
private:
	std::string	_ideas[NUM];
public:
	Brain();
	~Brain();
	Brain(Brain &copy);
	Brain	&operator=(Brain &copy);
	void	setIdeas(std::string idea);
	void	printIdeas();
};

#endif