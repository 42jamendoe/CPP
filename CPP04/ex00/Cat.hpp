/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : virtual public Animal{

public:

	//***** Orthodox Canonical Form *****
	Cat();
	Cat(const Cat& copy);
	Cat& operator=(const Cat& other);
	virtual ~Cat();
	//***** Orthodox Canonical Form *****

	virtual void makeSound()  const;

};


#endif
