/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:34:15 by jamendoe          #+#    #+#             */
/*   Updated: 2024/06/10 09:34:19 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {

private:

	std::string _name;

public:

	Zombie(std::string& name);
	~Zombie();
	void announce();

};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
