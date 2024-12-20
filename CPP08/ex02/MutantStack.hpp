/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <string>
#include <iostream>
#include <deque>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
public:

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin();
	iterator end();
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	const_iterator begin() const;
	const_iterator end() const;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	reverse_iterator rbegin();
	reverse_iterator rend();
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;
	//***** Orthodox Canonical Form *****
	MutantStack();
	MutantStack(const MutantStack& copy);
	MutantStack& operator=(const MutantStack& other);
	~MutantStack();
	//***** Orthodox Canonical Form *****

};

# include "MutantStack.tpp"
#endif
