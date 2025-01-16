#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_index = 0;
	_number_of_contacts = 0;
}

PhoneBook::~PhoneBook()
{
}

void	safe_getline(std::string *input)
{
	getline(std::cin, *input);
	if (std::cin.eof())
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX);
		return ;
	}
}

int	PhoneBook::add_contact()
{
	Contact		tmp;
	std::string	_first;
	std::string	_last;
	std::string	_nick;
	std::string	_number;
	std::string	_secret;

	while (_first == "\0")
	{
		std::cout<<"First Name : ";
		safe_getline(&_first);
		if (_first.empty())
			return (1);
		else if (_first == "\0")
			std::cout<<BOLDRED"Empty inputs are not valid"RESET<<std::endl;
	}
	tmp.set_first_name(_first);
	while (_last == "\0")
	{
		std::cout<<"Last Name : ";
		safe_getline(&_last);
		if (_last.empty())
			return (1);
		else if (_last == "\0")
			std::cout<<BOLDRED"Empty inputs are not valid"RESET<<std::endl;
	}
	tmp.set_last_name(_last);
	while (_nick == "\0")
	{
		std::cout<<"Nickname : ";
		safe_getline(&_nick);
		if (_nick.empty())
			return (1);
		else if (_nick == "\0")
			std::cout<<BOLDRED"Empty inputs are not valid"RESET<<std::endl;
	}
	tmp.set_nickname(_nick);
	while (_number == "\0")
	{
		std::cout<<"Phone Number : ";
		safe_getline(&_number);
		if (_number.empty())
			return (1);
		else if (_number == "\0")
			std::cout<<BOLDRED"Empty inputs are not valid"RESET<<std::endl;
	}
	tmp.set_phone_number(_number);
	while (_secret == "\0")
	{
		std::cout<<"Whats your darkest secret ?: ";
		safe_getline(&_secret);
		if (_secret.empty())
			return (1);
		else if (_secret == "\0")
			std::cout<<BOLDRED"Empty inputs are not valid"RESET<<std::endl;
	}
	tmp.set_darkest_secret(_secret);
	this->_contacts[_number_of_contacts % NUM] = tmp;
	if (this->_number_of_contacts < NUM)
		this->_number_of_contacts++;
	if (this->_number_of_contacts <= NUM)
		this->_index = this->_number_of_contacts;
	std::cout<<BOLDGREEN"Contact added successfully"RESET<<std::endl;
	return (0);
}

std::string	adjust(std::string text)
{
	if (text.length() > 10)
	{
		text.erase(text.begin() + 9, text.end());
		text.append(".");
	}
	return (text);
}

void	PhoneBook::show_list()
{
	std::cout<<"|  Index   |First Name|Last  Name| Nickname |"<<std::endl;
	for (int i = 0; i < this->_index; i++)
	{
		std::cout<<"|"<<std::setw(10)<<i;
		std::cout<<"|"<<std::setw(10)<<adjust(_contacts[i].get_first_name());
		std::cout<<"|"<<std::setw(10)<<adjust(_contacts[i].get_last_name());
		std::cout<<"|"<<std::setw(10)<<adjust(_contacts[i].get_nickname());
		std::cout<<"|"<<std::endl;
	}
}

int	PhoneBook::search_contact()
{
	int			n;
	std::string	num;

	while (1)
	{
		if (this->_number_of_contacts == 0)
		{
			std::cout<<BOLDYELLOW"The Phonebook is still empty"RESET<<std::endl;
			break;
		}
		show_list();
		std::cout<<"Whats the number of the contact you wish to search ?"<<std::endl;
		std::cout<<"> ";
		safe_getline(&num);
		if (num.empty())
			return (1);
		if (num == "\0")
		{
			std::cout<<BOLDRED"Invalid input please try again"RESET<<std::endl;
			continue;
		}
		std::stringstream ss(num);
		ss>>n;
		if (n >= 0 && n < this->_number_of_contacts)
		{
			std::cout<<"First Name : "<<_contacts[n].get_first_name()<<std::endl;
			std::cout<<"Last Name : "<<_contacts[n].get_last_name()<<std::endl;
			std::cout<<"Nickname : "<<_contacts[n].get_nickname()<<std::endl;
			std::cout<<"Phone Number : "<<_contacts[n].get_phone_number()<<std::endl;
			std::cout<<"Whats your darkest secret ?: "<<_contacts[n].get_darkest_secret()<<std::endl;
			break;
		}
		else
			std::cout<<BOLDRED"Number outside of the range of contacts please try again"RESET<<std::endl;
	}
	return (0);
}

void	options()
{
	std::cout<<" -----Valid Command----- "<<std::endl;
	std::cout<<"|                       |"<<std::endl;
	std::cout<<"|         ADD           |"<<std::endl;
	std::cout<<"|         SEARCH        |"<<std::endl;
	std::cout<<"|         EXIT          |"<<std::endl;
	std::cout<<"|                       |"<<std::endl;
	std::cout<<" ----------------------- "<<std::endl;
}

int	main(void)
{
	PhoneBook	phonebook;
	std::string	cmd;
	
	while (1)
	{
		options();
		std::cout<<"Input your command: ";
		safe_getline(&cmd);
		if (cmd.empty())
			break ;
		if (cmd == "ADD")
		{
			if (phonebook.add_contact() == 1)
				break ;
		}
		else if (cmd == "SEARCH")
		{
			if (phonebook.search_contact() == 1)
				break ;
		}
		else if (cmd == "EXIT")
		{
			std::cout<<BOLDYELLOW"All contacts lost forever"RESET<<std::endl;
			break ;
		}
		else
			std::cout<<BOLDRED"Wrong command please try again"RESET<<std::endl;
	}
	return (0);
}
