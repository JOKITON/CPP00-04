/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:26:59 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/10/04 23:47:30 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "AMateria.hpp"

class ICharacter
{
public:
	virtual	~ICharacter() {}
	virtual	std::string const & getName() const = 0;
	virtual	void unequip(int idx) = 0;
	virtual	void equip(AMateria* m) = 0;
	virtual	void use(int idx, ICharacter& target) = 0;
};

#endif
