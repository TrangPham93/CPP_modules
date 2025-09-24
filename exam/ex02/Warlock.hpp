/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 10:27:26 by trpham            #+#    #+#             */
/*   Updated: 2025/09/24 11:50:57 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <vector>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock   
{
	private:
		std::string _name;
		std::string	_title;
		SpellBook*	_spellBook;

	public:
		Warlock() = delete;
		Warlock(const Warlock& other) = delete;
		Warlock& operator= (const Warlock& other) = delete;
		Warlock(std::string name, std::string title);
		~Warlock();
		
		std::string getName() const;
		std::string	getTitle() const;
		void		setTitle( const std::string& title);
		void		introduce() const;

		void		learnSpell(const ASpell* spell);
		void		forgetSpell(const std::string spellName);
		void		launchSpell(const std::string spellName, const ATarget& target);
};

#endif