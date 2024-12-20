/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:32:43 by jamendoe          #+#    #+#             */
/*   Updated: 2024/06/10 09:33:10 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "RPN.hpp"

int main(int argc, char** argv)
{
	(void)argv;
	if (argc != 2 || argv[1][0] == '\0')
	{
		std::cout << "Usage: ./RPN <arg>." << std::endl;
		return -1;
	}
    try
    {
    	RPN var;
		var.parse_arg(argv[1]);
    }
    catch (std::exception& e)
    {
      std::cerr << e.what() << std::endl;
    }
	return 0;
}
