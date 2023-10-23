/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:48:16 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/10/23 16:51:03 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void	execTests0( void ) {
	std::cout << "\n		||_____----[ClapTrap]----____||" << std::endl;
	std::string name = "Jokin";
	// std::string name = ""; // error-case
	ClapTrap one(name);
	std::cout << std::endl;	

	std::cout << "		: ClapTrap base stats : \n	Health : 10\n	EnergyPoints : 10\n	AttackDmg : 0\n" << std::endl;
	
	std::cout << "___---attack()---____\n";
	one.attack(""); // error-case
	one.attack("Pablo");
	one.attack("Enaitz");
	std::cout << "\n___---takeDamage()---____\n";
	one.takeDamage(2);
	one.takeDamage(2);
	one.takeDamage(5);
	std::cout << "\n___---beRepaired()---____\n";
	// one.beRepaired(900); // error-case
	// one.takeDamage(600);
	one.beRepaired(40);
	one.takeDamage(-40);
	one.beRepaired(9);
	one.takeDamage(7); 
	one.attack("Mikel");

	std::cout << std::endl;

}

void	execTests1( void ) {

	std::cout << "\n		||_____----[ScavTrap]----____||" << std::endl;
	std::string name = "Jokin";
	// std::string name = ""; // error-case
	ScavTrap one(name);
	std::cout << std::endl;
	
	std::cout << "HitPoints -> " << one.getHealth() << std::endl;
	std::cout << "EnergyPoints -> " << one.getEnergyPoints() << std::endl;
	std::cout << "AttackDmg -> " << one.getAttackDmg() << std::endl << std::endl;

	one.attack("Pablo");
	one.takeDamage(99); // inherited
	one.takeDamage(0); // inherited (error-case)
	// one.takeDamage(43278484); // inherited (error-case)
	one.beRepaired(50); // inherited
	one.guardGate();
	one.attack("Pablo");

	std::cout << "\nHitPoints -> " << one.getHealth() << std::endl;
	std::cout << "EnergyPoints -> " << one.getEnergyPoints() << std::endl;
	std::cout << "AttackDmg -> " << one.getAttackDmg() << std::endl;
	std::cout << std::endl;
}

int	main(void) {
	
	//ClapTrap
	// execTests0();
	
	// ScavTrap
	execTests1();

	return 0;
}
