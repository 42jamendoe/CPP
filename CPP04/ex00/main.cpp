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
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main()
{
	// Subject Test
	std::cout << "---------- Animal, Dog and Cat Pointer----------" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl << "Animal type: three categories" << std::endl;
	std::cout << "First (new Animal): " << meta->getType() << " (should be empty type)" << std::endl;
	std::cout << "Second (new Dog): " << j->getType() << std::endl;
	std::cout << "Third (New Cat): " << i->getType() << std::endl;
	std::cout << std::endl << "Animal sound: Animal has a -Animal Base Class Sound-" << std::endl;
	std::cout << "First (new Animal): ";
	meta->makeSound();
	std::cout << "Second (new Dog): ";
	j->makeSound();
	std::cout << "Third (New Cat): ";
	i->makeSound();
	std::cout << std::endl;

	// no pointer Test
	std::cout << "---------- Animal, Dog and Cat No pointer----------" << std::endl;
	Animal meta_s;
	Dog j_s;
	Cat i_s;
	std::cout << std::endl << "Animal type: three categories" << std::endl;
	std::cout << "First (new Animal): " << meta_s.getType() << std::endl;
	std::cout << "Second (new Dog): " << j_s.getType() << std::endl;
	std::cout << "Third (New Cat): " << i_s.getType() << std::endl;
	std::cout << std::endl << "Animal sound: Animal has a -Animal Base Class Sound-" << std::endl;
	std::cout << "First (new Animal): ";
	meta_s.makeSound();
	std::cout << "Second (new Dog): ";
	i_s.makeSound();
	std::cout << "Third (New Cat): ";
	j_s.makeSound();
	std::cout << std::endl;

	//Test Copy constructor
	std::cout << ":::::Testing Copy constructor:::::" << std::endl;
	std::cout << "Testing Animal class:" << std::endl;
	const Animal* meta_copy(meta);
	std::cout << meta_copy->getType() << std::endl;
	meta_copy->makeSound();
	std::cout << "Testing Dog class:" << std::endl;
	const Animal* j_copy(j);
	std::cout << j_copy->getType() << std::endl;
	j_copy->makeSound();
	std::cout << "Testing Cat class:" << std::endl;
	const Animal* i_copy(i);
	std::cout << i_copy->getType() << std::endl;
	i_copy->makeSound();

	//Test overload assignment
	std::cout << ":::::Testing Overload assignment:::::" << std::endl;
	std::cout << "Testing Animal class:" << std::endl;
	const Animal* meta_oa = meta;
	std::cout << meta_copy->getType() << std::endl;
	meta_oa->makeSound();
	std::cout << "Testing Dog class:" << std::endl;
	const Animal* j_oa(j);
	std::cout << j_oa->getType() << std::endl;
	j_oa->makeSound();
	std::cout << "Testing Cat class:" << std::endl;
	const Animal* i_oa(i);
	std::cout << i_oa->getType() << std::endl;
	i_oa->makeSound();

	std::cout << "---------- WrongAnimal & WrongCat ----------" << std::endl;
	const WrongAnimal* meta_wrong_animal = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();
	std::cout << std::endl << "Call Animal MakeSound" << std::endl;
	meta_wrong_animal->makeSound();
	std::cout << std::endl << "Call Animal MakeSound *wrong_cat*" << std::endl;;
	wrong_cat->makeSound();
	std::cout << std::endl;
	std::cout << "---------- Destructors ----------" << std::endl;
	delete meta;
	delete j;
	delete i;
	delete wrong_cat;
	delete meta_wrong_animal;

	return 0;
}