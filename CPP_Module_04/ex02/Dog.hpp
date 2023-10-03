/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:25:50 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/10/02 19:44:51 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain* dogBrain;
	public:
		Dog(void);
		Dog( const Dog& p);
	
		~Dog(void);
	
		void	makeSound(void) const;
	
		Dog&	operator=(const Dog& p);

		Brain*	getBrain( void ) const;
};

#endif
