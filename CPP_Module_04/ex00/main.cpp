/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:07:19 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/09/28 02:47:50 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

void	subjectTests( void ) {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete i;
	delete j;
	delete(meta);
}

void	execTests( void ) {
	const Animal* g = new Animal("Cat");
	const Animal* h = new Animal("Dog");
	std::cout << g->getType() << " " << std::endl;
	std::cout << h->getType() << " " << std::endl;
	std::cout << g << " " << std::endl;
	std::cout << h << " " << std::endl;
	std::cout << &g << " " << std::endl;
	std::cout << &h << " " << std::endl;
	g->makeSound();
	h->makeSound();

	delete(g);
	delete(h);
}

int	main(void) {
	// Subject tests
	subjectTests();

	// my Own tests
	execTests();

	return 0;
}
