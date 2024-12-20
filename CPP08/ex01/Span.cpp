/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Span.hpp"

Span::Span(){}

Span::Span(const Span &copy) : array(copy.array), limit(copy.limit)
{

}

Span& Span::operator=(const Span &other)
{
	if (this == &other)
		return (*this);
	this->array = other.array;
	this->limit = other.limit;
	return (*this);
}

Span::~Span(){}

Span::Span(unsigned int N)
{
	limit = N;
}

void Span::addNumber(int x)
{
	if (array.size() >= limit)
		throw LimitReached();
	array.push_back(x);
}


int Span::shortestSpan()
{
	int i;

	i = 1;
	if (array.size() < 2)
		throw SizeException();
	std::sort(array.begin(), array.end());
	int min = array.at(1) - array.at(0);
	while ((array.begin() + i + 1) < array.end())
	{
		int tmp = array.at(i + 1) - array.at(i);
		if (tmp < min)
			min = tmp;
		i++;
	}
	return min;
}

int Span::longestSpan()
{
	if (array.size() < 2)
		throw SizeException();
	int i_min = *std::min_element(array.begin(), array.end());
	int i_max = *std::max_element(array.begin(), array.end());

	return (i_max - i_min);
}

void Span::aut_addNumber(const std::vector<int>& to_span)
{
	std::vector<int>::difference_type dimension = std::distance(to_span.begin(), to_span.end());
	if ((static_cast<int>(dimension) + array.size()) > limit)
		throw LimitReached();
	array.insert(array.end(), to_span.begin(), to_span.end());
}

const char* SizeException::SizeException::what() const throw()
{
	return ("Can't calculate the shortest span because there's less than 2 numbers!");
}

const char* LimitReached::LimitReached::what() const throw()
{
	return ("You can't add more numbers than the limit!");
}