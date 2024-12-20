/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:34:15 by jamendoe          #+#    #+#             */
/*   Updated: 2024/06/13 09:34:19 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Harl.hpp"

int main(void)
{
	Harl harl;

	std::cout << "Testing DEBUG level:" << std::endl;
	harl.complain("DEBUG");

	std::cout << std::endl << "Testing INFO level:" << std::endl;
	harl.complain("INFO");

	std::cout << std::endl << "Testing WARNING level:" << std::endl;
	harl.complain("WARNING");

	std::cout << std::endl << "Testing ERROR level:" << std::endl;
	harl.complain("ERROR");

	std::cout << std::endl << "Testing invalid level:" << std::endl;
	harl.complain("INVALID");

	return 0;
}
