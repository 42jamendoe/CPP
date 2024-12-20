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
#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./btc <file>." << std::endl;
		return (-1);
	}
	BitcoinExchange info;
	if (info.init_db(DB_HISTORIC, false))
		return (-1);
	if (info.init_db(argv[1], true))
		return (-1);
	return 0;
}
