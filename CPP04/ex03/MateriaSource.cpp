/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource()
{
	int i;

	i = 0;
	while (i < 4)
	{
		_templates[i] = NULL;
		i++;
	}
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (_templates[i])
			delete _templates[i];
		if (copy._templates[i])
			_templates[i] = copy._templates[i]->clone();
		else
			_templates[i] = NULL;
		i++;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this == &other)
		return (*this);
	int i;

	i = 0;
	while (i < 4)
	{
		if (_templates[i])
			delete _templates[i];
		if (other._templates[i])
			_templates[i] = other._templates[i]->clone();
		else
			_templates[i] = NULL;
		i++;
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (_templates[i])
			delete _templates[i];
		_templates[i] = NULL;
		i++;
	}
}

void MateriaSource::learnMateria(AMateria* tmp)
{
	int i;

	i = 0;
	if (!tmp)
		return ;
	while (i < 4)
	{
		if (!_templates[i])
		{
			_templates[i] = tmp->clone();
			break;
		}
		i++;
	}
	delete tmp;
	if (i == 4)
		std::cout << "a new Material can't be learned" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (_templates[i] && _templates[i]->getType() == type)
			return (_templates[i]->clone());
		i++;
	}
	return NULL;
}
