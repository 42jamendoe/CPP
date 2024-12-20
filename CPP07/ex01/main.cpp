/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:32:43 by jamendoe          #+#    #+#             */
/*   Updated: 2024/06/10 09:33:10 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "iter.hpp"

int main( void ) {

	std::cout << "1. string array" << std::endl;
	std::string words[] = {"jamendoe", "42", "Porto", "CPP07", "core"};
	size_t len;
	len = sizeof (words) / sizeof (words[0]);
	iter(words, len, printElement<std::string>);

	std::cout << std::endl << "2. int array" << std::endl;
	int numbers[] = {5, 4, 3, 2, 1};
	size_t len_int;
	len_int = sizeof (numbers) / sizeof (numbers[0]);
	iter(numbers, len_int, printElement<int>);

	std::cout << std::endl << "3. double array" << std::endl;
	double doubles_nbr[] = {100.5, 200.1, 300.15, 400.2, 500.25};
	size_t len_doubles_nbr;
	len_doubles_nbr = sizeof (doubles_nbr) / sizeof (doubles_nbr[0]);
	iter(doubles_nbr, len_doubles_nbr, printElement<double>);
	return 0;
}