/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 10:27:26 by trpham            #+#    #+#             */
/*   Updated: 2025/09/23 17:57:12 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <vector>

class Warlock
{
	private:
		std::string _name;
		std::string	_title;

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
};

#endif