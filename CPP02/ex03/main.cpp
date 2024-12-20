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
#include "Point.hpp"

int main() {
	Point a(0.0f, 0.0f);
	Point b(2.0f, 0.0f);
	Point c(1.0f, 2.0f);
	Point point1(1.0f, 1.0f); // Dentro do triângulo
	Point point2(2.0f, 2.0f); // Fora do triângulo

	if (bsp(a, b, c, point1)) {
		std::cout << "point1 está dentro do triângulo" << std::endl;
	} else {
		std::cout << "point1 está fora do triângulo" << std::endl;
	}

	if (bsp(a, b, c, point2)) {
		std::cout << "point2 está dentro do triângulo" << std::endl;
	} else {
		std::cout << "point2 está fora do triângulo" << std::endl;
	}

	return 0;
}