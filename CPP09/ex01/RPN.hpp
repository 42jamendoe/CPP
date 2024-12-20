/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <fstream>
# include <sstream>
# include <cstdlib>

class RPN
{
private:
	std::stack<int> values;
public:
	RPN();
	RPN(const RPN& copy);
	RPN& operator=(const RPN& other);
	~RPN();

	class RPN_error : public std::exception
	{
	public:
		const char* what() const throw ();
	};
	void handleOperations(std::string entry);
	void testInput(const std::string& line) const;
	void parse_arg(char* arg);
};

#endif