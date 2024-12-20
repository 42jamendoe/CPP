/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 11:59:42 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/06 11:59:47 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <string>

void PhoneBook::addContact ()
{
	Contact NewContact;
	std::string data;

	std::cout << "Please, enter the First Name:" << std::endl;
	std::getline (std::cin, data);
	NewContact.setFirstName (data);
	std::cout << "Please, enter the Last Name:" << std::endl;
	std::getline (std::cin, data);
	NewContact.setLastName (data);
	std::cout << "Please, enter the Nick Name:" << std::endl;
	std::getline (std::cin, data);
	NewContact.setNickName (data);
	std::cout << "Please, enter the Phone Number:" << std::endl;
	std::getline (std::cin, data);
	NewContact.setPhoneNumber (data);
	std::cout << "Please, enter the Darkest Secret:" << std::endl;
	std::getline (std::cin, data);
	NewContact.setDarkestSecret (data);
	ListContacts[Index % 8] = NewContact;
	Index++;
}

std::string truncate (const std::string &complete)
{
	std::string truncated;

	if (complete.length () > 9)
		truncated = complete.substr (0, 9) + ".";
	else
		truncated = complete;
	return (truncated);
}

void PhoneBook::searchContact () const
{
	std::string indexDetail;

	std::cout << '|' << std::setw (10) << "Index" << '|'
			  << std::setw (10) << "First Name" << '|'
			  << std::setw (10) << "Last Name" << '|'
			  << std::setw (10) << "Nick Name" << '|'
			  << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << '|' << std::setw (10) << i + 1 << '|'
				  << std::setw (10) << truncate (ListContacts[i].getFirstName ()) << '|'
				  << std::setw (10) << truncate (ListContacts[i].getLastName ()) << '|'
				  << std::setw (10) << truncate (ListContacts[i].getNickName ()) << '|'
				  << std::endl;
	}
	std::cout << "Please, write the Index of the contact (1-8): " << std::endl;
	std::getline (std::cin, indexDetail);
	if (indexDetail.length () != 1 || indexDetail[0] < '1' || indexDetail[0] > '8')
		std::cout << "Invalid Index. Exiting search panel..." << std::endl;
	else if ((indexDetail[0] - '0' - 1) >= Index)
		std::cout << "Empty Index. Exiting search panel..." << std::endl;
	else
	{
		std::cout << std::setw (16) << "First Name    : " << ListContacts[(indexDetail[0] - '0' - 1)].getFirstName ()
				  << std::endl;
		std::cout << std::setw (16) << "Last Name     : " << ListContacts[(indexDetail[0] - '0' - 1)].getLastName ()
				  << std::endl;
		std::cout << std::setw (16) << "Nick Name     : " << ListContacts[(indexDetail[0] - '0' - 1)].getNickName ()
				  << std::endl;
		std::cout << std::setw (16) << "Phone Number  : " << ListContacts[(indexDetail[0] - '0' - 1)].getPhoneNumber ()
				  << std::endl;
		std::cout << std::setw (16) << "Darkest Secret: "
				  << ListContacts[(indexDetail[0] - '0' - 1)].getDarkestSecret () << std::endl;
	}
}
