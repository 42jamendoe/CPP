/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	setHit(100);
	setEnergy(50);
	setAttack (20);
	std::cout << "ScavTrap " << _name << " was created with: "<< _Hit <<
			  " Hit points, " << _Energy << " Energy points and " << _Attack <<
			  " Attack points." << std::endl;
	std::cout << ":::::ScavTrap default constructor:::::" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	setHit(100);
	setEnergy(50);
	setAttack (20);
	std::cout << "ScavTrap " << _name << " set the inicial values with: "<< _Hit <<
			  " Hit points, " << _Energy << " Energy points and " << _Attack <<
			  " Attack points." << std::endl;
	std::cout << ":::::ScavTrap parametrised constructor:::::" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
	setHit(100);
	setEnergy(50);
	setAttack (20);
	std::cout << "ScavTrap " << _name << " was created with: "<< _Hit <<
			  " Hit points, " << _Energy << " Energy points and " << _Attack <<
			  " Attack points." << std::endl;
	std::cout << ":::::ScavTrap copy constructor:::::" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& from)
{
	if (this == &from)
        return (*this);
	ClapTrap::operator=(from);
	std::cout << "ScavTrap " << _name << " was created with: "<< _Hit <<
			  " Hit points, " << _Energy << " Energy points and " << _Attack <<
			  " Attack points." << std::endl;
	std::cout << ":::::ScavTrap overload assignment:::::" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " was destroyed!" << std::endl;
	std::cout << ":::::ScavTrap Destructor:::::" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (getHit() == 0)
		std::cout << getName() << " don't have health, can't do anything!" << std::endl;
	else if (getEnergy() == 0)
		std::cout << getName() << " don't have energy, can't do anything!" << std::endl;
	else
		std::cout << "ScavTrap " << getName() << " attacks " <<  target << 
		" causing " << getAttack() << " points of damage (and lost 1 energy point)!" << std::endl;
}

void ScavTrap::guardGate()
{
	if (getEnergy() == 0)
		std::cout << getName() << " don't have energy, can't do anything!" << std::endl;
	else if (getHit() == 0)
		std::cout << getName() << " don't have health, can't do anything!" << std::endl;
	else
		std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode!" << std::endl;
}