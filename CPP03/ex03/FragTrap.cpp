/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	setHit(100);
	setEnergy(100);
	setAttack (30);
	std::cout << "FragTrap " << _name << " was created with: "<< _Hit <<
			  " Hit points, " << _Energy << " Energy points and " << _Attack <<
			  " Attack points." << std::endl;
	std::cout << ":::::FragTrap default constructor:::::" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	setHit(100);
	setEnergy(100);
	setAttack (30);
	std::cout << "FragTrap " << _name << " set the inicial values with: "<< _Hit <<
			  " Hit points, " << _Energy << " Energy points and " << _Attack <<
			  " Attack points." << std::endl;
	std::cout << ":::::FragTrap parametrised constructor:::::" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
	std::cout << "FragTrap " << _name << " was created with: "<< _Hit <<
			  " Hit points, " << _Energy << " Energy points and " << _Attack <<
			  " Attack points." << std::endl;
	std::cout << ":::::FragTrap copy constructor:::::" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& from)
{
	if (this == &from)
        return (*this);
	ClapTrap::operator=(from);
	std::cout << "FragTrap " << _name << " was created with: "<< _Hit <<
			  " Hit points, " << _Energy << " Energy points and " << _Attack <<
			  " Attack points." << std::endl;
	std::cout << ":::::FragTrap overload assignment:::::" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " was destroyed!" << std::endl;
	std::cout << ":::::FragTrap Destructor:::::" << std::endl;
}

void FragTrap::highFivesGuys ()
{
	if (getEnergy() == 0)
		std::cout << getName() << " don't have energy, can't do anything!" << std::endl;
	else if (getHit() == 0)
		std::cout << getName() << " don't have health, can't do anything!" << std::endl;
	else
		std::cout << "FragTrap " << getName() << " gives you an high five!" << std::endl;
}