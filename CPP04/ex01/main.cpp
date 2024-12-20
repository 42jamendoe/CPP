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
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	std::cout << "--- Teste de Criação e Destruição ---" << std::endl;

	Animal* animals[4];

	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();

	std::cout << "--- Teste de som do animal pelo tipo ---" << std::endl;
	
	for (int i = 0; i < 4; ++i)
	{
		std::cout << "Tipo do animal: " << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
	}

	std::cout << "--- Teste de Cópia e Atribuição ---" << std::endl;

	Dog originalDog;
	Dog copiedDog(originalDog);
	Dog assignedDog;
	assignedDog = originalDog;

	Cat originalCat;
	Cat copiedCat(originalCat);
	Cat assignedCat;
	assignedCat = originalCat;

	std::cout << "--- Teste de Destruição ---" << std::endl;

	for (int i = 0; i < 4; ++i)
	{
		delete animals[i];
	}

	return 0;
}
