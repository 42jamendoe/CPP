/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:32:43 by jamendoe          #+#    #+#             */
/*   Updated: 2024/06/10 09:33:10 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#define VALUE_TO_ATTACK 8
#define VALUE_TO_REPAIR 5


void    reset(ClapTrap &type) {
	type.setHit(10);
	type.setEnergy(10);
	type.setAttack(0);
}

void    reset(ScavTrap &type) {
	type.setHit(100);
	type.setEnergy(50);
	type.setAttack(20);
}

void	values(ClapTrap &type) {
	std::cout << std::endl << "ClapTrap Points" << std::endl;
	std::cout << "Name: " << type.getName() << std::endl;
	std::cout << "Hit Points: " << type.getHit() << std::endl;
	std::cout << "Energy Points: " << type.getEnergy() << std::endl;
	std::cout << "Attack Points: " << type.getAttack() << std::endl;
}
void	values(ScavTrap &type) {
	std::cout << std::endl << "ScavTrap" << std::endl;
	std::cout << "Name: " << type.getName() << std::endl;
	std::cout << "Hit Points: " << type.getHit() << std::endl;
	std::cout << "Energy Points: " << type.getEnergy() << std::endl;
	std::cout << "Attack Points: " << type.getAttack() << std::endl;
}

int main() {
	std::cout << std::endl << "Creating ClapTrap instances..." << std::endl;
	std::cout << std::endl << "**ClapTrap**" << std::endl;
	ClapTrap nr1("nbr_1");
	std::cout << std::endl << "**ScavTrap**" << std::endl;
	std::cout << "**First create an object ClapTrap**" << std::endl;
	std::cout << "**Then set the ScavTrap initial values**" << std::endl;
	ScavTrap nr2("nbr_2");

	values(nr1);
	values(nr2);

	std::cout << "**copy ScavTrap nr3 from nr2**" << std::endl;
	ScavTrap nr3(nr2);
	std::cout << "set ScavTrap nr3, name: nbr_3" << std::endl;
	nr3.setName ("nbr_3");
	std::cout << "Print ScavTrap nr1 - name: output should be *nbr_1*" << std::endl;
	std::cout << nr1.getName() << std::endl;
	std::cout << "Print ScavTrap nr2 - name: output should be *nbr_2*" << std::endl;
	std::cout << nr2.getName() << std::endl;
	std::cout << "Print ScavTrap nr3 - name: output should be *nbr_3*" << std::endl;
	std::cout << nr3.getName() << std::endl;
	std::cout << "set ScavTrap nr3 = nr2" << std::endl;
	nr3 = nr2;
	std::cout << "Print ScavTrap nr3 - name: output should be *nbr_2*" << std::endl;
	std::cout << nr3.getName() << std::endl;
	std::cout << "set ScavTrap nr3, name: nbr_3" << std::endl;
	nr3.setName ("nbr_3");
	std::cout << "Print ScavTrap nr1 - name: output should be *nbr_1*" << std::endl;
	std::cout << nr1.getName() << std::endl;
	std::cout << "Print ScavTrap nr2 - name: output should be *nbr_2*" << std::endl;
	std::cout << nr2.getName() << std::endl;
	std::cout << "Print ScavTrap nr3 - name: output should be *nbr_3*" << std::endl;
	std::cout << nr3.getName() << std::endl;
	std::cout << std::endl << "Member Functions" << std::endl;
	std::cout << std::endl << "Attack <> Class" << std::endl;
	nr1.attack("Target");
	nr2.attack("Target");
	std::cout << std::endl << "Energy and Hit - ClapTrap and ScavTrap -> Claptrap Function" << std::endl;
	nr1.beRepaired(VALUE_TO_REPAIR);
	nr2.beRepaired(VALUE_TO_REPAIR);
	nr1.takeDamage(VALUE_TO_ATTACK);
	nr2.takeDamage(VALUE_TO_ATTACK);
	reset(nr1);
	reset(nr2);
	std::cout << std::endl << "Energy to 0:" << std::endl;
	nr1.attack("Target");
	nr1.attack("Target");
	nr1.attack("Target");
	nr1.attack("Target");
	nr1.attack("Target");
	nr1.attack("Target");
	nr1.attack("Target");
	nr1.attack("Target");
	nr1.attack("Target");
	nr1.attack("Target");
	nr1.attack("Target");
	std::cout << std::endl << "Function Guard Gate" << std::endl;
	std::cout << "ScavTrap nr2" << std::endl;
	nr2.guardGate();
	std::cout << std::endl;
	std::cout << std::endl << "Function Guard Gate" << std::endl;
	std::cout << "ScavTrap nr3" << std::endl;
	nr3.guardGate();
	std::cout << std::endl;
	return 0;
}
