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
#include "easyfind.hpp"
#include <algorithm>
#include <deque>
#include <list>
#include <vector>

int main( void )
{
	std::cout << "List container {30, 50, 80, 140, 190}" << std::endl;

	int value = 190;
	std::list<int> First_List;
	First_List.push_back(30);
	First_List.push_back(50);
	First_List.push_back(80);
	First_List.push_back(140);
	First_List.push_back(190);
	try
	{
		easyfind< std::list<int> >(First_List, value);
	}
	catch(std::exception& e)
	{
		std::cout << "The value " << value << e.what() << std::endl;
	}
	value = 74;
	try
	{
		easyfind< std::list<int> >(First_List, value);
	}
	catch(std::exception& e)
	{
		std::cout << "The value " << value << e.what() << std::endl;
	}
	std::cout << std::endl << "Deque container {30, 50, 80, 140, 190}" << std::endl;
	std::deque<int> First_Deque;
	First_Deque.push_back(30);
	First_Deque.push_back(50);
	First_Deque.push_back(80);
	First_Deque.push_back(140);
	First_Deque.push_back(190);
	value = 80;
	try
	{
		easyfind< std::deque<int> >(First_Deque, value);
	}
	catch(std::exception& e)
	{
		std::cout << "The value " << value << e.what() << std::endl;
	}
	value = 154;
	try
	{
		easyfind< std::deque<int> >(First_Deque, value);
	}
	catch(std::exception& e)
	{
		std::cout << "The value " << value << e.what() << std::endl;
	}
	std::cout << std::endl << "Vector container {30, 50, 80, 140, 190}" << std::endl;
	std::vector<int> First_Vector;
	First_Vector.push_back(30);
	First_Vector.push_back(50);
	First_Vector.push_back(80);
	First_Vector.push_back(140);
	First_Vector.push_back(190);
	value = 30;
	try
	{
		easyfind< std::vector<int> >(First_Vector, value);
	}
	catch(std::exception& e)
	{
		std::cout << "The value " << value << e.what() << std::endl;
	}
	value = 54;
	try
	{
		easyfind< std::vector<int> >(First_Vector, value);
	}
	catch(std::exception& e)
	{
		std::cout << "The value " << value << e.what() << std::endl;
	}
	return 0;
}