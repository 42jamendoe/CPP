/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

typedef struct s_floor{
	AMateria* item;
	struct s_floor* next;
}	t_floor;

class Character : public ICharacter
{

private:

	std::string _name;
	AMateria* _inventory[4];
	t_floor* _floor;

public:
	//***** Orthodox Canonical Form *****
	Character();
	Character(const Character& copy);
	Character& operator=(const Character& other);
	~Character();
	//***** Orthodox Canonical Form *****

	Character(const std::string& name);
	std::string const& getName() const;
	void MateriaToFloor(AMateria* notused);
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif
