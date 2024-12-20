/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:34:15 by jamendoe          #+#    #+#             */
/*   Updated: 2024/06/10 09:34:19 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB{

private:

	std::string _name;
	Weapon *_weapon;

public:

	HumanB(const std::string& name);
	void	setWeapon(Weapon& weapon);
	void attack(void);

};

#endif
