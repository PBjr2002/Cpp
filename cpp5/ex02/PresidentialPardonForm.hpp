/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-05 16:27:00 by pauberna          #+#    #+#             */
/*   Updated: 2025-02-05 16:27:00 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include <cstring>
# include <math.h>
# include <cmath>
# include <fstream>
# include "AForm.hpp"


class PresidentialPardonForm : public AForm
{

private:


protected:


public:
	PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm &copy);
	PresidentialPardonForm& operator=(PresidentialPardonForm &copy);
	~PresidentialPardonForm();
};

#endif
