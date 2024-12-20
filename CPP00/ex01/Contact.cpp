/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 11:58:53 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/06 11:58:58 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setFirstName (const std::string &FirstName_p)
{
	this->FirstName = FirstName_p;
}

void Contact::setLastName (const std::string &LastName_p)
{
	this->LastName = LastName_p;
}

void Contact::setNickName (const std::string &NickName_p)
{
	this->NickName = NickName_p;
}

void Contact::setPhoneNumber (const std::string &PhoneNumber_p)
{
	this->PhoneNumber = PhoneNumber_p;
}

void Contact::setDarkestSecret (const std::string &DarkestSecret_p)
{
	this->DarkestSecret = DarkestSecret_p;
}

std::string Contact::getFirstName () const
{
	return (this->FirstName);
}

std::string Contact::getLastName () const
{
	return (this->LastName);
}

std::string Contact::getNickName () const
{
	return (this->NickName);
}

std::string Contact::getPhoneNumber () const
{
	return (this->PhoneNumber);
}

std::string Contact::getDarkestSecret () const
{
	return (this->DarkestSecret);
}
