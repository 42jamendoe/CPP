/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:32:43 by jamendoe          #+#    #+#             */
/*   Updated: 2024/06/10 09:33:10 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl << "I love having extra bacon for my "
				"7XL-double-cheese-triple-pickle "
				"-specialketchup burger." << std::endl << "I really do!" << std::endl;
};

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl << "I cannot believe adding extra bacon costs more money."
				<< std::endl << "You didn’t put "
				"enough bacon in my burger!" << std::endl << "If you did, I wouldn’t be asking for more!"
				<< std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl << "I think I deserve to have some extra bacon for free."
				<< std::endl << "I’ve been coming for "
				"years whereas you started working here since last month."
				<< std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl << "This is unacceptable! I want to speak to the manager now."
			  << std::endl;
}

void Harl::complain(std::string level)
{
	int i;
	int levelIndex;

	i = 0;
	levelIndex = -1;
	std::string type[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	while (i < 4)
	{
		if (level == type[i])
		{
			levelIndex = i;
			break ;
		}
		i++;
	}
	switch (levelIndex) {
		case 0:
			(this->*f[0])();

		case 1:
			(this->*f[1])();

		case 2:
			(this->*f[2])();

		case 3:
			(this->*f[3])();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
