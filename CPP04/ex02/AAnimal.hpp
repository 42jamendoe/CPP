/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{

protected:

	std::string _type;

public:

	//***** Orthodox Canonical Form *****
	AAnimal();
	AAnimal(const AAnimal& copy);
	AAnimal& operator=(const AAnimal& other);
	virtual ~AAnimal();
	//***** Orthodox Canonical Form *****

	std::string getType(void) const;
	virtual void makeSound() const = 0;
};

#endif
