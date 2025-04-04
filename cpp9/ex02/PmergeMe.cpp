/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-02 16:39:28 by pauberna          #+#    #+#             */
/*   Updated: 2025-04-02 16:39:28 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	std::cout<<GREEN<<"Default constructor called"<<RESET<<std::endl;
}

PmergeMe::PmergeMe(int ac, char **av)
{
	std::cout<<GREEN<<"PmergeMe constructor called"<<RESET<<std::endl;
	this->_vector.reserve(ac - 1);
	unsigned int	number;
	for (int i = 1; av[i]; i++)
	{
		if (!this->checkIfIsDigit(av[i]))
			throw InvalidInputException();
		number = strtoul(av[i], NULL, 10);
		if (number < 0 || number > UINT_MAX)
			throw InvalidInputException();
		this->_vector.insert(this->_vector.end(), number);
		this->_list.insert(this->_list.end(), number);
	}
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	std::cout<<YELLOW<<"Copy constructor called"<<RESET<<std::endl;
	*this = copy;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &copy)
{
	std::cout<<YELLOW<<"Copy assignment operator called"<<RESET<<std::endl;
	if (this != &copy)
	{
		this->_vector = copy._vector;
		this->_list = copy._list;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
	std::cout<<RED<<"Destructor called"<<RESET<<std::endl;
}

long	PmergeMe::getVectorTimer()
{
	return (this->_vectorTimer);
}

long	PmergeMe::getListTimer()
{
	return (this->_listTimer);
}

bool	PmergeMe::checkIfIsDigit(char *str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

void	PmergeMe::binaryInsertionForVector(std::vector<unsigned int> &vector, unsigned int left, unsigned int right, unsigned int number)
{
	vector.insert(std::lower_bound(vector.begin() + left, vector.begin() + right, number), number);
}

void	PmergeMe::binaryInsertionForList(std::list<unsigned int> &list, unsigned int left, unsigned int right, unsigned int number)
{
	std::list<unsigned int>::iterator	it = list.begin();
	std::advance(it, left);
	std::list<unsigned int>::iterator	end = list.begin();
	std::advance(end, right);
	while (it != end && *it < number)
		it++;
	list.insert(it, number);
}

void	PmergeMe::fordJonhsonSortForVector(std::vector<unsigned int> &vector, unsigned int left, unsigned int right)
{
	if (right - left <= 1)
		return ;
	//separating the larger elements from the smaller ones
	std::vector<unsigned int> largerElements;
	for (unsigned int i = left; i < right - 1; i += 2)
		largerElements.push_back(std::max(vector[i], vector[i + 1]));
	this->fordJonhsonSortForVector(largerElements, 0, largerElements.size());

	//inserting the smaller elements
	std::vector<unsigned int>	mainChain = largerElements;
	for (unsigned int i = left; i < right - 1; i += 2)
		this->binaryInsertionForVector(mainChain, 0, mainChain.size(), std::min(vector[i], vector[i + 1]));
	if ((right - left) % 2 != 0)
		this->binaryInsertionForVector(mainChain, 0, mainChain.size(), vector[right - 1]);

	//inserting the ordenated numbers to the main vector
	for (unsigned int i = 0; i < mainChain.size(); i++)
		vector[left + i] = mainChain[i];
}

void	PmergeMe::fordJonhsonSortForList(std::list<unsigned int> &list, unsigned int left, unsigned int right)
{
	if (right - left <= 1)
		return ;
	//separating the larger elements from the smaller ones
	std::list<unsigned int> largerElements;
	std::list<unsigned int>::iterator	it = list.begin();
	std::advance(it, left);
	unsigned int n;
	unsigned int a;
	for (unsigned int i = left; i < right - 1; i += 2)
	{
		n = *it;
		it++;
		a = *it;
		largerElements.push_back(std::max(n, a));
		it++;
	}
	this->fordJonhsonSortForList(largerElements, 0, largerElements.size());

	//inserting the smaller elements
	std::list<unsigned int>	mainChain = largerElements;
	it = list.begin();
	std::advance(it, left);
	for (unsigned int i = left; i < right - 1; i += 2)
	{
		n = *it;
		it++;
		a = *it;
		this->binaryInsertionForList(mainChain, 0, mainChain.size(), std::min(n, a));
		it++;
	}
	if ((right - left) % 2 != 0)
	{
		it = list.begin();
		std::advance(it, right - 1);
		this->binaryInsertionForList(mainChain, 0, mainChain.size(), *it);
	}

	//inserting the ordenated numbers to the main list
	it = list.begin();
	std::advance(it, left);
	std::list<unsigned int>::iterator	mainIt = mainChain.begin();
	while (mainIt != mainChain.end())
	{
		*it = *mainIt;
		it++;
		mainIt++;
	}
}

void	PmergeMe::sort()
{
	struct timeval	start;
	struct timeval	end;
	std::cout<<"Before: ";
	for (unsigned int i = 0; i < this->_vector.size(); i++)
		std::cout<<this->_vector[i]<<" ";
	std::cout<<std::endl;

	gettimeofday(&start, NULL);
	this->fordJonhsonSortForVector(this->_vector, 0, this->_vector.size());
	gettimeofday(&end, NULL);
	this->_vectorTimer = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
	gettimeofday(&start, NULL);
	this->fordJonhsonSortForList(this->_list, 0, this->_list.size());
	gettimeofday(&end, NULL);
	this->_listTimer = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
	this->checkIfSorted();

	std::cout<<"After: ";
	for (unsigned int i = 0; i < this->_vector.size(); i++)
		std::cout<<this->_vector[i]<<" ";
	std::cout<<std::endl;

	std::cout<<"Time to process a range of "<<this->_vector.size()<<" elements with std::vector : "<<this->_vectorTimer<<" μs"<<std::endl;
	std::cout<<"Time to process a range of "<<this->_list.size()<<" elements with std::list : "<<this->_listTimer<<" μs"<<std::endl;
}

void	PmergeMe::checkIfSorted()
{
	std::vector<unsigned int>::iterator	vectorIt = this->_vector.begin();
	std::list<unsigned int>::iterator	listIt = this->_list.begin();
	unsigned int lastNumber;

	lastNumber = *vectorIt;
	vectorIt++;
	while (vectorIt != this->_vector.end())
	{
		if (*vectorIt < lastNumber)
			throw NotOrderedVectorException();
		lastNumber = *vectorIt;
		vectorIt++;
	}
	lastNumber = *listIt;
	listIt++;
	while (listIt != this->_list.end())
	{
		if (*listIt < lastNumber)
			throw NotOrderedListException();
		lastNumber = *listIt;
		listIt++;
	}
}

PmergeMe::InvalidInputException::InvalidInputException():
std::runtime_error("Error") {}

PmergeMe::NotOrderedVectorException::NotOrderedVectorException():
std::runtime_error("Error: Numbers in the vector are not ordered") {}

PmergeMe::NotOrderedListException::NotOrderedListException():
std::runtime_error("Error: Numbers in the list are not ordered") {}
