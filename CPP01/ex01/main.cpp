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
#include <string>
#include "Zombie.hpp"

int main()
{
	int N;
	int i;
	std::string name;

	i = 0;
	N = 30;
	name = "42 Porto";
	std::cout << "Take care! a horde of " << N << " zombies will be created and will be named: "<< name << "!"<< std::endl;
	Zombie *zh;
	zh = zombieHorde(N, name);
	while(i < N)
	{
		std::cout << "Zombie " << (i + 1) << " announces itself!" << std::endl;
		zh[i].announce();
		i++;
	}
	delete[] zh;
	std::cout << "The horde of zombies has been killed and we can go out now!" << std::endl;
	return (0);
}
