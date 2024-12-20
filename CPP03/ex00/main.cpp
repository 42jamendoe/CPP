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
#include "ClapTrap.hpp"

int main( void )
{
	std::cout << "Create ClapTrap" << std::endl;
	std::cout << std::endl;
	std::cout << "create Claptrap nr1, name: nbr_1" << std::endl;
	ClapTrap nr1("nbr_1");
	std::cout << "set Claptrap nr1, name: nbr_2" << std::endl;
	nr1.setName ("nbr_2");
	std::cout << "Print ClapTrap nr1 - name: output should be *nbr_2*" << std::endl;
	std::cout << nr1.getName() << std::endl;
	std::cout << std::endl;
	std::cout << "Copy constructor test" << std::endl;
	std::cout << std::endl;
	std::cout << "create Claptrap nr2, copied from nbr_1 with name *nbr_3*" << std::endl;
	ClapTrap nr2("nbr_3");
	std::cout << std::endl;
	std::cout << "Tests:" << std::endl;
	std::cout << "Print ClapTrap nr1 - name: output should be *nbr_2*" << std::endl;
	std::cout << nr1.getName() << std::endl;
	std::cout << "Print ClapTrap nr2 - name: output should be *nbr_3*" << std::endl;
	std::cout << nr2.getName() << std::endl;
	std::cout << std::endl;
	std::cout << "********************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "overload assignment operator =" << std::endl;
	std::cout << "set nr1 = nr2" << std::endl;
	std::cout << std::endl;
	nr1 = nr2;
	std::cout << std::endl;
	std::cout << "Tests:" << std::endl;
	std::cout << "Print ClapTrap nr1 - name: output should be *nbr_3*" << std::endl;
	std::cout << nr1.getName() << std::endl;
	std::cout << "Print ClapTrap nr2 - name: output should be *nbr_3*" << std::endl;
	std::cout << nr2.getName() << std::endl;
	std::cout << "set Claptrap nr1, name: nbr_4" << std::endl;
	nr1.setName ("nbr_4");
	std::cout << "Print ClapTrap nr1 - name: output should be *nbr_4*" << std::endl;
	std::cout << nr1.getName() << std::endl;
	std::cout << "Print ClapTrap nr2 - name: output should be *nbr_3*" << std::endl;
	std::cout << nr2.getName() << std::endl;
	std::cout << std::endl;
	std::cout << "********************************************" << std::endl;
	std::cout << std::endl;
		nr1.attack ("nbr_3");
	nr2.takeDamage (3);
	nr1.beRepaired (4);
	std::cout << std::endl << "Energy to 0:" << std::endl;
	nr1.attack("Target");
	nr1.attack("Target");
	nr1.attack("Target");
	nr1.attack("Target");
	nr1.attack("Target");
	nr1.attack("Target");
	nr1.attack("Target");
	nr1.attack("Target");
	std::cout << ":::::nr1 Energy equals 0:::::" << std::endl;
	nr1.attack("Target");
	nr1.attack("Target");
	nr1.attack("Target");
	std::cout << std::endl;
	std::cout << ":Destroy nr1(nbr_4) and nr2(nbr_3)" << std::endl;
	return 0;
}