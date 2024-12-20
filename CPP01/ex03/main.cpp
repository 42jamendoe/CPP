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
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{
		Weapon sword = Weapon("sharp sword");
		HumanA alice("Alice", sword);
		alice.attack();
		sword.setType("rusty sword");
		alice.attack();
	}
	{
		Weapon axe = Weapon("battle axe");
		HumanB tom("Tom");
		tom.attack(); // Teste sem arma
		tom.setWeapon(axe);
		tom.attack();
		axe.setType("double-edged axe");
		tom.attack();
	}
	{
		Weapon spear = Weapon ("long spear");
		HumanB john ("John");
		john.attack (); // Teste sem arma
		john.setWeapon (spear);
		john.attack ();
		spear.setType ("short spear");
		john.attack ();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attack(); // Teste sem arma
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{
		Weapon sword = Weapon("sharp sword");
		HumanA alice("Alice", sword);
		alice.attack();
		sword.setType("rusty sword");
		alice.attack();
	}
	{
		Weapon axe = Weapon("battle axe");
		HumanB tom("Tom");
		tom.attack(); // Teste sem arma
		tom.setWeapon(axe);
		tom.attack();
		axe.setType("double-edged axe");
		tom.attack();
	}
	{
		Weapon spear = Weapon("long spear");
		HumanB john("John");
		john.attack(); // Teste sem arma
		john.setWeapon(spear);
		john.attack();
		spear.setType("short spear");
		john.attack();
	}
	{
		Weapon dagger = Weapon("sharp dagger");
		Weapon mace = Weapon("heavy mace");

		HumanA alice("Alice", dagger);
		HumanB tom("Tom");
		tom.setWeapon(mace);

		alice.attack();
		tom.attack();

		dagger.setType("blunt dagger");
		mace.setType("light mace");

		alice.attack();
		tom.attack();

		tom.setWeapon(dagger); // Tom troca de arma

		tom.attack();
	}
	{
		Weapon spear = Weapon("long spear");
		HumanA alice("Alice", spear);
		HumanB bob("Bob");
		bob.setWeapon(spear);

		alice.attack();
		bob.attack();

		spear.setType("short spear");

		alice.attack();
		bob.attack();
	}
	{
		HumanB tom("Tom");
		tom.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		Weapon sword = Weapon("sharp sword");

		HumanA bob("Bob", club);
		HumanB jim("Jim");
		jim.setWeapon(sword);

		bob.attack();
		jim.attack();

		club.setType("some other type of club");
		sword.setType("rusty sword");

		bob.attack();
		jim.attack();

		jim.setWeapon(club); // Jim troca de arma

		bob.attack();
		jim.attack();
	}
	{
		Weapon bow = Weapon("long bow");
		HumanA robin("Robin", bow);
		robin.attack();

		bow.setType("short bow");
		robin.attack();

		Weapon crossbow = Weapon("crossbow");
		robin.attack();

		robin.attack();
		crossbow.setType("automatic crossbow");
		robin.attack();
	}
	return 0;
}
