/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "AMateria.hpp"

AMateria::AMateria() : _type("Default"){}

AMateria::AMateria(const AMateria& copy) : _type(copy._type){}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

AMateria::~AMateria(){}

AMateria::AMateria(std::string const& type) : _type(type){}

std::string const& AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << target.getName() << std::endl;
}
