/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap(), _name("Default")
{
	setHit(100);
	setEnergy(50);
	setAttack(30);
	std::cout << "DiamondTrap " << this->_name << " was created with: " << getHit() <<
			  " Hit points, " << getEnergy() << " Energy points and " <<getAttack() <<
			  " Attack points." << std::endl;
	std::cout << ":::::DiamondTrap default constructor:::::" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), _name(name)
{
	setHit(100);
	setEnergy(50);
	setAttack(30);
	std::cout << "DiamondTrap " << this->_name << " set the initial values with: "<< getHit() <<
			  " Hit points, " << getEnergy() << " Energy points and " << getAttack() <<
			  " Attack points." << std::endl;
	std::cout << ":::::DiamondTrap parametrised constructor:::::" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap(copy), FragTrap(copy), ScavTrap(copy), _name(copy._name)
{
	setHit(100);
	setEnergy(50);
	setAttack(30);
	std::cout << "DiamondTrap " << this->_name << " was created with: "<< getHit() <<
			  " Hit points, " << getEnergy() << " Energy points and " << getAttack() <<
			  " Attack points." << std::endl;
	std::cout << ":::::DiamondTrap copy constructor:::::" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& from)
{
	ClapTrap::operator=(from);
	ScavTrap::operator=(from);
	FragTrap::operator=(from);
	_name = from._name;
	setHit(100);
	setEnergy(50);
	setAttack(30);
	std::cout << "DiamondTrap " << this->_name << " was created with: "<< getHit() <<
			  " Hit points, " << getEnergy() << " Energy points and " << getAttack() <<
			  " Attack points." << std::endl;
	std::cout << ":::::DiamondTrap overload assignment:::::" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " was destroyed!" << std::endl;
	std::cout << ":::::DiamondTrap Destructor:::::" << std::endl;
}

void DiamondTrap::whoAmI()
{
	if (getEnergy() == 0)
		std::cout << getName() << " don't have energy, can't do anything!" << std::endl;
	else if (getHit() == 0)
		std::cout << getName() << " don't have health, can't do anything!" << std::endl;
	else
    {
        std::cout << "DiamondTrap Class - ClapTrap name: " << getName() << std::endl;
        std::cout << "DiamondTrap Class name string: " << DiamondTrap::_name << std::endl;
    }
}
