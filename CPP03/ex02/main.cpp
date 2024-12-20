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
#include "FragTrap.hpp"

#define VALUE_TO_ATTACK 80
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

void    reset(FragTrap &type) {
	type.setHit(100);
	type.setEnergy(100);
	type.setAttack(50);
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
void	values(FragTrap &type) {
	std::cout << std::endl << "FragTrap" << std::endl;
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
	std::cout << std::endl << "**FragTrap**" << std::endl;
	std::cout << "**First create an object ClapTrap**" << std::endl;
	std::cout << "**Then set the FragTrap initial values**" << std::endl;
	FragTrap nr3("nbr_3");

	values(nr1);
	std::cout << std::endl;
	values(nr2);
	std::cout << std::endl;
	values(nr3);
	std::cout << std::endl;
	std::cout << "**copy FragTrap nr4 from nr3**" << std::endl;
	FragTrap nr4(nr3);
	std::cout << "Print FragTrap nr4 - name: output should be *nbr_3*" << std::endl;
	std::cout << nr4.getName() << std::endl;
	std::cout << "set FragTrap nr4, name: nbr_4" << std::endl;
	nr4.setName ("nbr_4");
	std::cout << "Print ScavTrap nr1 - name: output should be *nbr_1*" << std::endl;
	std::cout << nr1.getName() << std::endl;
	std::cout << "Print ScavTrap nr2 - name: output should be *nbr_2*" << std::endl;
	std::cout << nr2.getName() << std::endl;
	std::cout << "Print ScavTrap nr3 - name: output should be *nbr_3*" << std::endl;
	std::cout << nr3.getName() << std::endl;
	std::cout << "Print FragTrap nr4 - name: output should be *nbr_4*" << std::endl;
	std::cout << nr4.getName() << std::endl;
	std::cout << "set FragTrap nr4 = nr3" << std::endl;
	nr4 = nr3;
	std::cout << "Print FragTrap nr4 - name: output should be *nbr_3*" << std::endl;
	std::cout << nr4.getName() << std::endl;
	std::cout << "set FragTrap nr4, name: nbr_4" << std::endl;
	nr4.setName ("nbr_4");
	std::cout << "Print ScavTrap nr1 - name: output should be *nbr_1*" << std::endl;
	std::cout << nr1.getName() << std::endl;
	std::cout << "Print ScavTrap nr2 - name: output should be *nbr_2*" << std::endl;
	std::cout << nr2.getName() << std::endl;
	std::cout << "Print FragTrap nr3 - name: output should be *nbr_3*" << std::endl;
	std::cout << nr3.getName() << std::endl;
	std::cout << "Print FragTrap nr4 - name: output should be *nbr_4*" << std::endl;
	std::cout << nr4.getName() << std::endl;
	std::cout << std::endl << "Member Functions" << std::endl;
	std::cout << std::endl << "Attack <> Class - FragTrap uses ClapTrap attack" << std::endl;
	nr1.attack("Target");
	nr2.attack("Target");
	nr3.attack("Target");
	nr4.attack("Target");
	std::cout << std::endl << "Energy and Hit - ClapTrap and ScavTrap -> Claptrap Function" << std::endl;
	nr1.beRepaired(VALUE_TO_REPAIR);
	nr2.beRepaired(VALUE_TO_REPAIR);
	nr3.beRepaired(VALUE_TO_REPAIR);
	nr4.beRepaired(VALUE_TO_REPAIR);
	nr1.takeDamage(VALUE_TO_ATTACK);
	nr2.takeDamage(VALUE_TO_ATTACK);
	nr3.takeDamage(VALUE_TO_ATTACK);
	nr4.takeDamage(VALUE_TO_ATTACK);
	reset(nr1);
	reset(nr2);
	reset(nr3);
	reset(nr4);
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
	std::cout << std::endl << "Function High Fives Guys" << std::endl;
	std::cout << "FragTrap nr3" << std::endl;
	nr3.highFivesGuys();
	std::cout << std::endl;
	std::cout << "FragTrap nr4" << std::endl;
	nr4.highFivesGuys();
	return 0;
}
