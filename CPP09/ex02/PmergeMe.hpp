/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <ctime>
# include <climits>

class PmergeMe
{
private:
	std::vector<int> vector_array;
	std::vector<int> vector_before;
	std::deque<int> deque_array;
	std::deque<int> deque_before;
public:
	PmergeMe();
	PmergeMe(const PmergeMe& copy);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();
	void VectorFordJohnsonMergeInsert();
	void DequeFordJohnsonMergeInsert();
	void printArray(const bool& type) const;
	void printArrayBefore(const bool& type) const;
	bool addArg(char** arg);
	void start_algorithm();
};

#endif