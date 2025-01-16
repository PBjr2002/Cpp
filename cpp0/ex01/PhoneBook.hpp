#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <sstream>
# include <string>
# include <iomanip>
# include <climits>
# include <cstdlib>
# include "colors.hpp"
# include "Contact.hpp"

# define NUM 8

class PhoneBook
{
private:
	Contact		_contacts[NUM];
	int			_index;
	int			_number_of_contacts;
public:
	PhoneBook();
	~PhoneBook();
	int		add_contact();
	int		search_contact();
	void	show_list();
};


#endif