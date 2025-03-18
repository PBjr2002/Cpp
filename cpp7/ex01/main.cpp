/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-17 11:31:19 by pauberna          #+#    #+#             */
/*   Updated: 2025-03-17 11:31:19 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	ftToLower(char &array)
{
	array = std::tolower(static_cast<unsigned int>(array));
}

void	ftToUpper(char &array)
{
	array = std::toupper(static_cast<unsigned int>(array));
}

void	increment(int &array)
{
	array = array + 1;
}

void	decrement(int &array)
{
	array = array - 1;
}

template<typename T>
void	change(T &something)
{
	something = 65;
}

int	main(void)
{
	char	chArr[] = {'A', 'B', 'C'};
	char	*empty = NULL;
	int		intArr[] = {0, 1, 2};

	std::cout<<RED<<"Empty array testing"<<RESET<<std::endl;
	::iter(empty, 0, ftToLower);

	std::cout<<GREEN<<"chArr testing"<<RESET<<std::endl;
	std::cout<<"chArr[0]: "<<chArr[0]<<std::endl;
	std::cout<<"chArr[1]: "<<chArr[1]<<std::endl;
	std::cout<<"chArr[2]: "<<chArr[2]<<std::endl;
	std::cout<<YELLOW<<"tolower on chArr"<<RESET<<std::endl;
	::iter(chArr, 3, ftToLower);
	std::cout<<"chArr[0]: "<<chArr[0]<<std::endl;
	std::cout<<"chArr[1]: "<<chArr[1]<<std::endl;
	std::cout<<"chArr[2]: "<<chArr[2]<<std::endl;
	std::cout<<YELLOW<<"toupper on chArr"<<RESET<<std::endl;
	::iter(chArr, 3, ftToUpper);
	std::cout<<"chArr[0]: "<<chArr[0]<<std::endl;
	std::cout<<"chArr[1]: "<<chArr[1]<<std::endl;
	std::cout<<"chArr[2]: "<<chArr[2]<<std::endl;
	std::cout<<YELLOW<<"change on chArr"<<RESET<<std::endl;
	::iter(chArr, 3, change<char>);
	std::cout<<"chArr[0]: "<<chArr[0]<<std::endl;
	std::cout<<"chArr[1]: "<<chArr[1]<<std::endl;
	std::cout<<"chArr[2]: "<<chArr[2]<<std::endl;

	std::cout<<GREEN<<"intArr testing"<<RESET<<std::endl;
	std::cout<<"intArr[0]: "<<intArr[0]<<std::endl;
	std::cout<<"intArr[1]: "<<intArr[1]<<std::endl;
	std::cout<<"intArr[2]: "<<intArr[2]<<std::endl;
	std::cout<<YELLOW<<"increment on intArr"<<RESET<<std::endl;
	::iter(intArr, 3, increment);
	std::cout<<"intArr[0]: "<<intArr[0]<<std::endl;
	std::cout<<"intArr[1]: "<<intArr[1]<<std::endl;
	std::cout<<"intArr[2]: "<<intArr[2]<<std::endl;
	std::cout<<YELLOW<<"decrement on intArr"<<RESET<<std::endl;
	::iter(intArr, 3, decrement);
	std::cout<<"intArr[0]: "<<intArr[0]<<std::endl;
	std::cout<<"intArr[1]: "<<intArr[1]<<std::endl;
	std::cout<<"intArr[2]: "<<intArr[2]<<std::endl;
	std::cout<<YELLOW<<"change on intArr"<<RESET<<std::endl;
	::iter(intArr, 3, change<int>);
	std::cout<<"intArr[0]: "<<intArr[0]<<std::endl;
	std::cout<<"intArr[1]: "<<intArr[1]<<std::endl;
	std::cout<<"intArr[2]: "<<intArr[2]<<std::endl;

	return (0);
}
