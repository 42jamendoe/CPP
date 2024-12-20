/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 11:59:07 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/06 11:59:11 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{

public:

	void setFirstName (const std::string &FirstName_p);
	void setLastName (const std::string &LastName_p);
	void setNickName (const std::string &NickName_p);
	void setPhoneNumber (const std::string &PhoneNumber_p);
	void setDarkestSecret (const std::string &DarkestSecret_p);
	std::string getFirstName () const;
	std::string getLastName () const;
	std::string getNickName () const;
	std::string getPhoneNumber () const;
	std::string getDarkestSecret () const;

private:

	std::string FirstName;
	std::string LastName;
	std::string NickName;
	std::string PhoneNumber;
	std::string DarkestSecret;

};

#endif
