/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:34:15 by jamendoe          #+#    #+#             */
/*   Updated: 2024/06/13 09:34:19 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie{

private:

	std::string _name;

public:

	Zombie();
	~Zombie();
	void	setName(std::string& name);
	void	announce();

};

Zombie*	zombieHorde(int N, std::string name);

#endif
