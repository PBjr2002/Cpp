/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-05 14:35:12 by pauberna          #+#    #+#             */
/*   Updated: 2025-02-05 14:35:12 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default")
{
	std::cout<<GREEN"ShrubberyCreationForm Default constructor called" RESET<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout<<GREEN"ShrubberyCreationForm Target constructor called" RESET<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &copy) : AForm(copy)
{
	std::cout<<YELLOW"ShrubberyCreationForm Copy constructor called" RESET<<std::endl;
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout<<RED"ShrubberyCreationForm destructor called" RESET<<std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm &copy)
{
	std::cout<<YELLOW"ShrubberyCreationForm Copy assignment operator called" RESET<<std::endl;
	if (this != &copy)
		_target = copy._target;
	return (*this);
}

void	ShrubberyCreationForm::executeForm() const
{
	std::ofstream	out((_target + "_shrubbery").c_str());

	if (out)
	{
		out<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣤⣦⣤⣤⣄⣀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
		out<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⠟⡍⢆⡱⠌⢥⠋⡝⣩⢋⠛⡿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
		out<<"⠀⠀⠀⠀⠀⠀⠀⢀⣤⣴⣶⠾⢏⡜⠰⡡⢆⠹⡠⢋⠔⡢⢌⠓⡤⢛⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
		out<<"⠀⠀⠀⠀⠀⢀⣾⠟⣩⠒⢤⡉⠦⢌⠣⡑⠬⣑⠢⢍⡒⠥⢊⡑⢆⠣⢿⡷⢶⣤⡀⠀⠀⠀⠀⠀⠀\n";
		out<<"⠀⠀⠀⠀⠀⢸⡟⡘⢤⡉⠦⣘⠡⢎⡡⢍⠲⢄⡋⠴⡘⠬⡑⡌⢎⠒⡅⢎⢢⡙⣷⡀⠀⠀⠀⠀⠀\n";
		out<<"⠀⠀⠀⠀⣠⣼⡿⠘⣄⠸⢃⡄⡛⠤⣀⠇⠼⢠⡘⢣⡘⢣⠸⢠⠜⢣⠸⢄⣃⠸⣻⣇⠀⠀⠀⠀⠀\n";
		out<<"⠀⢀⣴⡿⢋⡕⢢⡙⠤⣉⠖⡰⢉⡒⡡⢎⢡⢃⠬⡡⠜⡡⢎⠡⢎⡡⠚⢤⢂⡓⣘⠛⠿⣶⣄⠀⠀\n";
		out<<"⠀⣾⢏⡰⢃⠜⡰⢌⡒⡡⠎⡔⠣⣌⠱⢌⢢⡉⠦⣑⢡⠣⢌⡃⠦⣑⠩⡒⠬⡰⢡⡉⢖⡰⢹⣷⠀\n";
		out<<"⠸⣿⢂⠦⣉⠲⠡⢆⡑⢆⠓⠬⡑⠤⠓⡌⢆⠜⡡⢆⠣⠜⢢⠜⡡⢆⠣⢅⡓⡰⢡⢊⡒⢌⠆⣿⡇\n";
		out<<"⠀⠻⣧⡒⡡⢎⡑⢎⠰⡊⢍⡒⢩⠜⣵⡘⠬⡘⡔⢊⡌⢣⣃⡜⢰⢊⠱⡌⠴⣁⠣⢆⡉⠖⣸⡿⠀\n";
		out<<"⠀⢰⡿⢡⡑⠦⡘⡌⡱⢘⢢⢉⠖⣸⣿⣿⣦⡱⠌⣥⣼⣾⣿⢃⠣⡌⢣⢘⠒⡌⡱⢂⣭⣾⠟⠁⠀\n";
		out<<"⠀⢸⣷⠡⠜⢢⠱⣌⡑⠎⡤⢃⢮⣿⣿⣿⣿⡟⡿⣿⣿⣿⣿⡌⡱⢌⣑⣊⠱⣘⠰⢃⣿⡇⠀⠀⠀\n";
		out<<"⠀⠀⠻⣷⣭⣆⣣⠛⠿⣿⣶⠿⣿⣟⢿⣿⣿⡟⡜⣿⣿⣿⡿⠿⣿⡿⡛⣃⢣⣼⣦⣷⠟⠁⠀⠀⠀\n";
		out<<"⠀⠀⠀⠀⠉⠉⠻⢿⣴⣢⣄⣯⣾⢿⣮⡽⢿⡟⡸⢿⣟⢫⣜⣷⡿⣷⡇⣦⣿⠋⠁⠀⠀⠀⠀⠀⠀\n";
		out<<"⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠉⠉⠀⠀⠙⣿⣆⠳⣩⠖⣸⣶⡿⠛⠛⠿⠛⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀\n";
		out<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢼⣧⠛⣤⠛⣼⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
		out<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡗⡏⣆⢏⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
		out<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡿⡱⢜⣊⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
		out<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣟⡥⠳⣌⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
		out<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣯⠖⡹⢤⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
		out<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡷⣋⠵⣃⢾⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
		out<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣯⡕⣮⢱⣾⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
		out<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣯⡕⢬⣃⢿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
		out<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣗⠮⡱⣌⠾⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
		out<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣾⣏⣶⡱⡜⡸⢽⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
		out<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⣏⣿⡿⠛⣷⣭⣽⣷⣾⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
		out<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠁⠀⠀⠈⠛⠛⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
	}
	else
		throw FileNotOpenException();
	out.close();
}

const char	*ShrubberyCreationForm::FileNotOpenException::what() const throw()
{
	return ("Error opening the file");
}
