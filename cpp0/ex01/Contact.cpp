#include "PhoneBook.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void		Contact::set_first_name(std::string _first)
{
	this->_first_name = _first;
}

void		Contact::set_last_name(std::string _last)
{
	this->_last_name = _last;
}

void		Contact::set_nickname(std::string _nick)
{
	this->_nickname = _nick;
}

void		Contact::set_phone_number(std::string _number)
{
	this->_phone_number = _number;
}

void		Contact::set_darkest_secret(std::string _secret)
{
	this->_darkest_secret = _secret;
}

std::string	Contact::get_first_name()
{
	return (this->_first_name);
}

std::string	Contact::get_last_name()
{
	return(this->_last_name);
}

std::string	Contact::get_nickname()
{
	return(this->_nickname);
}

std::string	Contact::get_phone_number()
{
	return(this->_phone_number);
}

std::string	Contact::get_darkest_secret()
{
	return(this->_darkest_secret);
}