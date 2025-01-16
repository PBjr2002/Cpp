#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <string>
# include <iomanip>
# include <climits>
# include "colors.hpp"

class Contact
{
private:
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_number;
	std::string	_darkest_secret;
public:
	Contact();
	~Contact();
	std::string	get_first_name();
	std::string	get_last_name();
	std::string	get_nickname();
	std::string	get_phone_number();
	std::string	get_darkest_secret();
	void		set_first_name(std::string _first);
	void		set_last_name(std::string _last);
	void		set_nickname(std::string _nick);
	void		set_phone_number(std::string _number);
	void		set_darkest_secret(std::string _secret);
};

#endif