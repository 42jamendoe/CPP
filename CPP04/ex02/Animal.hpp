/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{

protected:

	std::string _type;

public:

	//***** Orthodox Canonical Form *****
	Animal();
	Animal(const Animal& copy);
	Animal& operator=(const Animal& other);
	virtual ~Animal();
	//***** Orthodox Canonical Form *****

	std::string getType(void) const;
	virtual void makeSound() const;
};

#endif
