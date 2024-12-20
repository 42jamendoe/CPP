/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe& copy)
{
	vector_array = copy.vector_array;
	deque_array = copy.deque_array;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this == &other)
		return (*this);
	vector_array = other.vector_array;
	deque_array = other.deque_array;
	return (*this);
}

PmergeMe::~PmergeMe()
{

}

void PmergeMe::printArrayBefore(const bool& type) const
{
	size_t i;

	i = 0;
	if (!type)
	{
		while (i < vector_before.size() - 1)
		{
			std::cout << vector_before[i] << " ";
			i++;
		}
		std::cout << vector_before[i] << std::endl;
	}
	else
	{
		while (i < deque_before.size() - 1)
		{
			std::cout << deque_before[i] << " ";
			i++;
		}
		std::cout << deque_before[i] << std::endl;
	}
}

void PmergeMe::printArray(const bool& type) const
{
	size_t i;

	i = 0;
	if (!type)
	{
		while (i < vector_array.size() - 1)
		{
			std::cout << vector_array[i] << " ";
			i++;
		}
		std::cout << vector_array[i] << std::endl;
	}
	else
	{
		while (i < deque_array.size() - 1)
		{
			std::cout << deque_array[i] << " ";
			i++;
		}
		std::cout << deque_array[i] << std::endl;
	}
}

bool ComparePair(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
	return (a.second < b.second);
}

void DequeSortAlgorithm(std::deque<int>& low_unsorted, std::deque<int>& high_sorted, const std::deque<int>& jac_numbers)
{
	int inserted = 0;
	int to_ins = 1;
	int n;
	int j = 0;
	int k = 0;
	int low_size;

	low_size = static_cast<int>(low_unsorted.size());
	std::deque<int>::iterator place;
	n = jac_numbers[j] - 1;
	while (true)
	{
		k = 0;
		while (to_ins > 0)
		{
			place = std::lower_bound(high_sorted.begin(), high_sorted.begin() + inserted, low_unsorted[n - k]);
			high_sorted.insert(place, low_unsorted[n - k]);
			k++;
			inserted++;
			to_ins--;
			low_size--;
		}
		if (low_size == 0)
			break;
		j++;
		to_ins = jac_numbers[j] - jac_numbers[j - 1];
		inserted += to_ins;
		n = jac_numbers[j] - 1;
	}
}

std::deque<int> DequeCreateJac(int size)
{
	int next_jn;
	size_t n = 2;

	std::deque<int> jac_numbers;
	jac_numbers.push_back(1);
	if (size == 2)
		jac_numbers.push_back(2);
	else if (size == 3)
		jac_numbers.push_back(3);
	else if (size > 3)
	{
		jac_numbers.push_back(3);
		while (true)
		{
			next_jn = jac_numbers[n - 2] * 2 + jac_numbers[n - 1];
			if (size < next_jn)
			{
				jac_numbers.push_back(size);
				return jac_numbers;
			}
			jac_numbers.push_back(next_jn);
			n++;
		}
	}
	return jac_numbers;
}

std::deque< std::pair<int, int> > DequeCreatePairs(std::deque<int> deque_array)
{
	size_t i;
	i = 0;
	std::deque< std::pair<int, int> > pairs;
	while (i < (deque_array.size() - 1))
	{
		if (deque_array[i] <= deque_array[i + 1])
			pairs.push_back(std::pair<int, int>(deque_array[i], deque_array[i + 1]));
		else if (deque_array[i] > deque_array[i + 1])
			pairs.push_back(std::pair<int, int>(deque_array[i + 1], deque_array[i]));
		i += 2;
	}
	
	std::sort(pairs.begin(), pairs.end(), ComparePair);
	return pairs;
}

void PmergeMe::DequeFordJohnsonMergeInsert()
{
	std::deque<std::pair<int, int> > pairs;
	std::deque<int> low_unsorted;
	std::deque<int> high_sorted;
	std::deque<int> jac_numbers;

	pairs = DequeCreatePairs(deque_array);
	int low_size;
	size_t i;

	i = 0;
	while (i < pairs.size())
	{
		low_unsorted.push_back(pairs[i].first);
		high_sorted.push_back(pairs[i].second);
		i++;
	}
	if (deque_array.size() % 2 == 1)
		low_unsorted.push_back(deque_array.back());
	low_size = static_cast<int>(low_unsorted.size());
	jac_numbers = DequeCreateJac(low_size);
	DequeSortAlgorithm(low_unsorted, high_sorted, jac_numbers);
	deque_array = high_sorted;
}

void VectorSortAlgorithm(std::vector<int>& low_unsorted, std::vector<int>& high_sorted, const std::vector<int>& jac_numbers)
{
	int inserted = 0;
	int to_ins = 1;
	int n;
	int j = 0;
	int k = 0;
	int low_size;

	low_size = static_cast<int>(low_unsorted.size());
	std::vector<int>::iterator place;
	n = jac_numbers[j] - 1;
	while (true)
	{
		k = 0;
		while (to_ins > 0)
		{
			place = std::lower_bound(high_sorted.begin(), high_sorted.begin() + inserted, low_unsorted[n - k]);
			high_sorted.insert(place, low_unsorted[n - k]);
			k++;
			inserted++;
			to_ins--;
			low_size--;
		}
		if (low_size == 0)
			break;
		j++;
		to_ins = jac_numbers[j] - jac_numbers[j - 1];
		inserted += to_ins;
		n = jac_numbers[j] - 1;
	}
}

std::vector<int> VectorCreateJac(int size)
{
	int next_jn;
	size_t n = 2;

	std::vector<int> jac_numbers;
	jac_numbers.push_back(1);
	if (size == 2)
		jac_numbers.push_back(2);
	else if (size == 3)
		jac_numbers.push_back(3);
	else if (size > 3)
	{
		jac_numbers.push_back(3);
		while (true)
		{
			next_jn = jac_numbers[n - 2] * 2 + jac_numbers[n - 1];
			if (size < next_jn)
			{
				jac_numbers.push_back(size);
				return jac_numbers;
			}
			jac_numbers.push_back(next_jn);
			n++;
		}
	}
	return jac_numbers;
}

std::vector< std::pair<int, int> > VectorCreatePairs(std::vector<int> vector_array)
{
	size_t i;
	i = 0;
	std::vector< std::pair<int, int> > pairs;
	while (i < (vector_array.size() - 1))
	{
		if (vector_array[i] <= vector_array[i + 1])
			pairs.push_back(std::pair<int, int>(vector_array[i], vector_array[i + 1]));
		else if (vector_array[i] > vector_array[i + 1])
			pairs.push_back(std::pair<int, int>(vector_array[i + 1], vector_array[i]));
		i += 2;
	}
	std::sort(pairs.begin(), pairs.end(), ComparePair);
	return pairs;
}

void PmergeMe::VectorFordJohnsonMergeInsert()
{
	std::vector<std::pair<int, int> > pairs;
	std::vector<int> low_unsorted;
	std::vector<int> high_sorted;
	std::vector<int> jac_numbers;

	pairs = VectorCreatePairs(vector_array);
	int low_size;
	size_t i;

	i = 0;
	while (i < pairs.size())
	{
		low_unsorted.push_back(pairs[i].first);
		high_sorted.push_back(pairs[i].second);
		i++;
	}
	if (vector_array.size() % 2 == 1)
		low_unsorted.push_back(vector_array.back());
	low_size = static_cast<int>(low_unsorted.size());
	jac_numbers = VectorCreateJac(low_size);
	VectorSortAlgorithm(low_unsorted, high_sorted, jac_numbers);
	vector_array = high_sorted;
}

bool PmergeMe::addArg(char** arg)
{
	std::string arg_text;
	size_t i;
	long to_test;
	int value;

	i = 1;
	while (arg[i])
	{
		arg_text = arg[i];
		if (arg_text.empty() || arg_text.size() > 10)
		{
			std::cerr << "Error" << std::endl;
			return true;
		}
		std::string::size_type invalid = arg_text.find_first_not_of("0123456789");
		if (invalid != std::string::npos)
		{
			std::cerr << "Error" << std::endl;
			return true;
		}
		to_test = std::atol(arg[i]);
        if (to_test > INT_MAX || to_test < 0)
        {
           	std::cerr << "Error" << std::endl;
            return true;
        }
		value = static_cast<int>(to_test);
		vector_before.push_back(value);
		vector_array.push_back(value);
		deque_before.push_back(value);
		deque_array.push_back(value);
		i++;
	}
	return false;
}

void PmergeMe::start_algorithm()
{
	std::clock_t start_vector = std::clock();
	VectorFordJohnsonMergeInsert();
	std::clock_t end_vector = std::clock();
	double time_vector = (static_cast<double>(end_vector) - static_cast<double>(start_vector)) * 1000 / CLOCKS_PER_SEC;
	std::clock_t start_deque = std::clock();
	DequeFordJohnsonMergeInsert();
	std::clock_t end_deque = std::clock();
	double time_deque = (static_cast<double>(end_deque) - static_cast<double>(start_deque)) * 1000 / CLOCKS_PER_SEC;

	std::cout << "#####VECTOR#####" << std::endl;
	std::cout << "Before: ";
	printArrayBefore(false);
	std::cout << "After: ";
	printArray(false);
	std::cout << "Time to process a range of " << vector_array.size() << " elements with std::vector<int> : " << time_vector << " milliseconds" << std::endl;
	std::cout << "Time to process a range of " << vector_array.size() << " elements with std::deque<int> : " << time_deque << " milliseconds" << std::endl;
	std::cout << std::endl << "#####DEQUE#####" << std::endl;
	std::cout << "Before: ";
	printArrayBefore(true);
	std::cout << "After: ";
	printArray(true);
	std::cout << "Time to process a range of " << vector_array.size() << " elements with std::vector<int> : " << time_vector << " milliseconds" << std::endl;
	std::cout << "Time to process a range of " << vector_array.size() << " elements with std::deque<int> : " << time_deque << " milliseconds" << std::endl;
}
