/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 11:59:22 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/06 11:59:25 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>

#include "PhoneBook.hpp"

int main ()
{
	PhoneBook book;
	std::string command;

	std::cout << "Wellcome to this old PhoneBook!" << std::endl;
	while (true)
	{
		std::cout << "Enter a valid command (ADD, SEARCH or EXIT):" << std::endl;
		std::getline (std::cin, command);
		if (command == "ADD")
			book.addContact ();
		else if (command == "SEARCH")
			book.searchContact ();
		else if (command == "EXIT")
			break;
		else
			std::cout << "You entered an invalid command <" << command << ">. Please, try again." << std::endl;
	}
	std::cout << "Thank you!" << std::endl;
	return (0);
}
