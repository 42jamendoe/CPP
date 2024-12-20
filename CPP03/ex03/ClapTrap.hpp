/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{

protected:

	std::string		_name;
	unsigned int	_Hit;
	unsigned int	_Energy;
	unsigned int	_Attack;

public:

	ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& copy);
	ClapTrap& operator=(const ClapTrap& from);
	~ClapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void setName (const std::string& name);
	void setHit (const unsigned int& Hit);
	void setEnergy (const unsigned int& Energy);
	void setAttack (const unsigned int& Attack);
	std::string getName (void) const;
	unsigned int getHit (void) const;
	unsigned int getEnergy (void) const;
	unsigned int getAttack (void) const;

};

#endif
