/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Character.hpp"
#include <iostream>

Character::Character() : _name("Default"), _floor(NULL)
{
	int i;

	i = 0;
	while (i < 4)
	{
		_inventory[i] = NULL;
		i++;
	}
}

Character::Character(const Character& copy)
{
	int i;

	i = 0;
	_name = copy._name;
	while (i < 4)
	{
		if (copy._inventory[i])
			_inventory[i] = copy._inventory[i]->clone();
		else
			_inventory[i] = NULL;
		i++;
	}
	if (copy._floor)
	{
		_floor = new t_floor;
		_floor->item = copy._floor->item->clone();
		_floor->next = NULL;

		t_floor* current = _floor;
		t_floor* copy_current = copy._floor->next;

		while (copy_current)
		{
			current->next = new t_floor;
			current = current->next;
			current->item = copy_current->item->clone();
			current->next = NULL;
			copy_current = copy_current->next;
		}
	}
	else
		_floor = NULL;
}

Character& Character::operator=(const Character& other)
{
	int i;

	i = 0;
	if (this == &other)
		return (*this);
	_name = other._name;
	while (i < 4)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
		i++;
	}
	if (other._floor)
	{
		_floor = new t_floor;
		_floor->item = other._floor->item->clone();
		_floor->next = NULL;

		t_floor* current = _floor;
		t_floor* other_current = other._floor->next;

		while (other_current)
		{
			current->next = new t_floor;
			current = current->next;
			current->item = other_current->item->clone();
			current->next = NULL;
			other_current = other_current->next;
		}
	}
	else
		_floor = NULL;
	return (*this);
}

Character::~Character()
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
		i++;
	}
	while (_floor)
	{
		t_floor* tmp = _floor;
		_floor = _floor->next;
		delete tmp->item;
		delete tmp;
	}
	_floor = NULL;
}

Character::Character(const std::string& name) : _name(name), _floor(NULL)
{
	int i;

	i = 0;
	while (i < 4)
	{
		_inventory[i] = NULL;
		i++;
	}
}

std::string const& Character::getName() const
{
	return (this->_name);
}

void Character::MateriaToFloor(AMateria* notused)
{
	t_floor* actual = _floor;

	if (notused)
	{
		t_floor *new_item = new t_floor;
		new_item->item = notused;
		new_item->next = NULL;
		if (_floor)
		{
			while (actual->next)
				actual = actual->next;
			actual->next = new_item;
		}
		else
			_floor = new_item;			
		std::cout << "a new Material left on the floor" << std::endl;
	}
}

void Character::equip(AMateria* m)
{
	int i;

	i = 0;
	if (!m)
		return ;
	while (i < 4)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			i = 4;
		}
		i++;
	}
	if (i == 4)
		MateriaToFloor(m);
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
	{
		MateriaToFloor(_inventory[idx]);
		_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
	{
		_inventory[idx]->use(target);
		std::cout << _name << " used a " << _inventory[idx]->getType() << " on " << target.getName() << std::endl;
	}
	else
		std::cout << "No material or invalid slot" << std::endl;
}
