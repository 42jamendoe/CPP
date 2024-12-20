/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:34:15 by jamendoe          #+#    #+#             */
/*   Updated: 2024/06/13 09:34:19 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl{

private:

	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

public:

	void complain(std::string level);

};

#endif
