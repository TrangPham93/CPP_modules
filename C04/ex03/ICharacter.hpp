/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:50:31 by trpham            #+#    #+#             */
/*   Updated: 2025/09/12 13:03:47 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AMateria.hpp"

/*  pure abstract class:

    All methods of pure abstract class are only declared but not defined (pure virtual methods).
    Its methods can be defined either public, protected or private.
    Any class can inherit pure abstract class.
    The implementing class must provide the definition of the methods otherwise it will become abstract class.
    Instance of pure virtual class cannot be created.*/
class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};