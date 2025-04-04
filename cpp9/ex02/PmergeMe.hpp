/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-02 16:39:26 by pauberna          #+#    #+#             */
/*   Updated: 2025-04-02 16:39:26 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <cstring>
# include <math.h>
# include <cmath>
# include <fstream>
# include <climits>
# include <list>
# include <vector>
# include <stack>
# include <map>
# include <algorithm>
# include <sys/time.h>  

# define RESET "\033[0m"
# define GREEN "\033[1m\033[32m"
# define RED "\033[1m\033[31m"
# define YELLOW "\033[1m\033[33m"

class PmergeMe
{
	private:
		std::vector<unsigned int>	_vector;
		std::list<unsigned int>		_list;
		long						_vectorTimer;
		long						_listTimer;
	public:
		PmergeMe();
		PmergeMe(int ac, char **av);
		PmergeMe(const PmergeMe &copy);
		PmergeMe	&operator=(const PmergeMe &copy);
		~PmergeMe();
		long	getVectorTimer();
		long	getListTimer();
		bool	checkIfIsDigit(char *str);
		void	binaryInsertionForVector(std::vector<unsigned int> &vector, unsigned int left, unsigned int right, unsigned int number);
		void	binaryInsertionForList(std::list<unsigned int> &list, unsigned int left, unsigned int right, unsigned int number);
		void	fordJonhsonSortForVector(std::vector<unsigned int> &vector, unsigned int left, unsigned int right);
		void	fordJonhsonSortForList(std::list<unsigned int> &list, unsigned int left, unsigned int right);
		void	sort();
		void	checkIfSorted();
		class	InvalidInputException : public std::runtime_error
		{
			public:
				InvalidInputException();
		};
		class	NotOrderedVectorException : public std::runtime_error
		{
			public:
				NotOrderedVectorException();
		};
		class	NotOrderedListException : public std::runtime_error
		{
			public:
				NotOrderedListException();
		};
};

#endif
