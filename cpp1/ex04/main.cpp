#include <iostream>
#include <fstream>
#include <string>

std::string	replace_line(std::string line, std::string s1, std::string s2)
{
	for (int _start = line.find(s1);  _start != -1; _start = line.find(s1))
	{
		line.erase(_start, s1.length());
		line.insert(_start, s2);
	}
	return(line);
}

int	check_strings(std::string s1, std::string s2)
{
	if (s1.empty() || s2.empty())
	{
		std::cout<<"Neither of the strings can be empty"<<std::endl;
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout<<"Invalid number of arguments"<<std::endl;
		return (1);
	}
	std::ifstream	_in(av[1]);
	std::string		_content;
	if (_in.is_open())
	{
		std::string		_thing(".replace");
		std::string		_name(av[1] + _thing);
		std::ofstream	_out(_name.c_str());
		if (_out.is_open())
		{
			if (check_strings(av[2], av[3]) == 0)
			{
				while (getline(_in, _content))
				{
					_content = replace_line(_content, av[2], av[3]);
					_out<<_content<<std::endl;
				}
			}
			_in.close();
			_out.close();
		}
		else
		{
			std::cout<<"There was an error openning the outfile"<<std::endl;
			_in.close();
		}
	}
	else
		std::cout<<"There was a problem openning the infile"<<std::endl;
	return (0);
}