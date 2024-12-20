/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : virtual public Animal{

private:

	Brain* _brain;

public:

	//***** Orthodox Canonical Form *****
	Dog();
	Dog(const Dog& copy);
	Dog& operator=(const Dog& other);
	virtual ~Dog();
	//***** Orthodox Canonical Form *****

	virtual void makeSound() const;
};
#endif
