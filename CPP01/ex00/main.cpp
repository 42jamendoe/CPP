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
	Zombie	*heap_zombie;

	std::cout << "First the heap zombie" << std::endl << std::endl;
	heap_zombie = newZombie("Heap");
	heap_zombie->announce();
	delete heap_zombie;
	std::cout << std::endl << "Now the stack zombie" << std::endl << std::endl;;
	randomChump ("Stack");
	return (0);
}
