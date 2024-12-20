/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <iostream>
# include <string>
# include <vector>
# include <iterator>


class Span
{
private:
	std::vector<int> array;
	unsigned int limit;
public:
	Span();
	Span(const Span &copy);
	Span &operator=(const Span &other);
	~Span();
	Span(unsigned int N);
	void addNumber(int x);
	int shortestSpan();
	int longestSpan();
	void aut_addNumber(const std::vector<int>& to_span);
};

class SizeException : public std::exception
{
public:
	virtual const char* what() const throw();
};

class LimitReached : public std::exception
{
public:
	virtual const char* what() const throw();
};

#endif
