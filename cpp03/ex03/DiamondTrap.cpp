#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_trap"), FragTrap(name + "_clap_trap"), ScavTrap(name + "_clap_trap") {
	std::cout << "DiamondTrap Default constructor called" << std::endl;
	this->name = name; 
	attack_damage = 30;
}

DiamondTrap::~DiamondTrap() {std::cout << "DiamondTrap Destructor called" << std::endl;}

DiamondTrap::DiamondTrap(const DiamondTrap &ref) : ClapTrap(ref), FragTrap(ref), ScavTrap(ref), name(ref.name) {
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator= (const DiamondTrap &ref) {
	ClapTrap::operator=(ref);
	return *this;
}

void	DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap " << name << std::endl;
	std::cout << "ClapTrap " << ClapTrap::name << std::endl;
}
