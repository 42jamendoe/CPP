/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BRAIN_HPP
#define BRAIN_HPP

# include <iostream>
# include <string>

#define ARRAY_SIZE 100

class Brain
{

private:

	std::string _ideas[ARRAY_SIZE];

public:

	//***** Orthodox Canonical Form *****
	Brain();
	Brain(const Brain& copy);
	Brain& operator=(const Brain& other);
	virtual ~Brain();
	//***** Orthodox Canonical Form *****

};


#endif
