#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap Default constructor called" << std::endl;
	hit_point = 100;
	energy_point = 50;
	attack_damage = 20;
}

ScavTrap::~ScavTrap() {std::cout << "ScavTrap Destructor called" << std::endl;}

ScavTrap::ScavTrap(const ScavTrap &ref) : ClapTrap(ref) {
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator= (const ScavTrap &ref) {
	ClapTrap::operator=(ref);
	return *this;
}

void	ScavTrap::attack(const std::string& target) {
	if (hit_point <= 0) {
		std::cout << "ScavTrap " << name << " Dead" << std::endl;
		return;
	}
	if (energy_point == 0) {
		std::cout << "ScavTrap Not enough energy" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << name << " attacks " << target \
		<< ", causing " << attack_damage << " points of damage!" << std::endl;
	energy_point--;
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}