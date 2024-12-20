/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _Hit(10), _Energy(10), _Attack(0)
{
	std::cout << "ClapTrap " << _name << " was created with: "<< _Hit <<
			  " Hit points, " << _Energy << " Energy points and " << _Attack <<
			  " Attack points." << std::endl;
	std::cout << ":::::ClapTrap default constructor:::::" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _Hit(10), _Energy(10),
											  _Attack(0)
{
	std::cout << "ClapTrap " << _name << " was created with: "<< _Hit <<
			  " Hit points, " << _Energy << " Energy points and " << _Attack <<
			  " Attack points." << std::endl;
	std::cout << ":::::ClapTrap parametrised constructor:::::" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy) : _name(copy._name), _Hit(copy._Hit),
										   _Energy(copy._Energy), _Attack(copy._Attack)
{
	std::cout << "ClapTrap " << _name << " was copied with: "<< _Hit <<
			  " Hit points, " << _Energy << " Energy points and " << _Attack <<
			  " Attack points." << std::endl;
	std::cout << ":::::ClapTrap copy constructor:::::" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& from)
{
	if (this == &from)
        return (*this);
    setName(from.getName());
	setHit(from.getHit());
	setEnergy(from.getEnergy());
	setAttack(from.getAttack());
	std::cout << "ClapTrap " << _name << " was assigned: "<< _Hit <<
			  " Hit points, " << _Energy << " Energy points and " << _Attack <<
			  " Attack points." << std::endl;
	std::cout << ":::::ClapTrap overload assignment:::::" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " was destroyed!" << std::endl;
	std::cout << ":::::ClapTrap destructor:::::" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_Energy == 0)
		std::cout << _name << " don't have energy, can't do anything!" << std::endl;
	else if (_Hit == 0)
		std::cout << _name << " don't have health, can't do anything!" << std::endl;
	else
	{
		_Energy -= 1;
		std::cout << "ClapTrap " << getName () << " attacks " << target <<
				  " causing " << getAttack () << " points of damage (and lost 1 energy point)!"
				  << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_Energy == 0)
        std::cout << _name << " don't have energy, can't do anything!" << std::endl;
    else if (_Hit == 0)
		std::cout << _name << " don't have health, can't do anything!" << std::endl;
	else if (_Hit <= amount)
	{
		std::cout << "ClapTrap " << getName () << " took damage and it lost " <<
				  _Hit << " hit points! ClapTrap has 0 health!" << std::endl;
		_Hit = 0;
	}
	else
	{
		_Hit -= amount;
		std::cout << "ClapTrap " << getName () << " took damage and it lost " <<
				  amount << " hit points!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_Energy == 0)
		std::cout << _name << " don't have energy, can't do anything!" << std::endl;
	else if (_Hit == 0)
		std::cout << _name << " don't have health, can't do anything!" << std::endl;
	else
	{
		_Energy -= 1;
		_Hit += amount;
		std::cout << "ClapTrap " << getName () <<
				  " is repairing itself and it got back " << amount <<
				  " hit points back (and lost 1 energy point)!" << std::endl;
	}
}

void ClapTrap::setName (const std::string& name)
{
	this->_name = name;
}

void ClapTrap::setHit (const unsigned int& Hit)
{
	this->_Hit = Hit;
}

void ClapTrap::setEnergy (const unsigned int& Energy)
{
	this->_Energy = Energy;
}

void ClapTrap::setAttack (const unsigned int& Attack)
{
	this->_Attack = Attack;
}

std::string ClapTrap::getName (void) const
{
	return (this->_name);
}

unsigned int ClapTrap::getHit(void) const
{
	return (this->_Hit);
}

unsigned int ClapTrap::getEnergy(void) const
{
	return (this->_Energy);
}

unsigned int ClapTrap::getAttack(void) const
{
	return (this->_Attack);
}
