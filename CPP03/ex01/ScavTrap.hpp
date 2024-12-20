/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:

	//***** Orthodox Canonical Form *****
	ScavTrap();
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& copy);
	ScavTrap& operator=(const ScavTrap& from);
	~ScavTrap();
	//***** Orthodox Canonical Form *****

	void attack(const std::string& target);
	void guardGate();

};

#endif
