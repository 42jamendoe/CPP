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
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


int main()
{
	std::cout << "--- Teste de Criação e Destruição ---" << std::endl;

	AAnimal* animals[4];

	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();

	for (int i = 0; i < 4; ++i)
	{
		std::cout << "Tipo do animal: " << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
	}

	std::cout << "--- Teste de Cópia e Atribuição ---" << std::endl;

	Dog _Dog;
	Dog copyDog(_Dog);
	Dog assignedDog;
	assignedDog = _Dog;

	Cat _Cat;
	Cat copyCat(_Cat);
	Cat assignedCat;
	assignedCat = _Cat;

	std::cout << "--- Teste de Destruição ---" << std::endl;

	for (int i = 0; i < 4; ++i)
	{
		delete animals[i];
	}

	return 0;
}
