#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
	std::cout << "FragTrap Default constructor called" << std::endl;
	hit_point = 100;
	energy_point = 100;
	attack_damage = 30;
}

FragTrap::~FragTrap() {std::cout << "FragTrap Destructor called" << std::endl;}

FragTrap::FragTrap(const FragTrap &ref) : ClapTrap(ref) {
	std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator= (const FragTrap &ref) {
	ClapTrap::operator=(ref);
	return *this;
}

void	FragTrap::highFivesGuys() {
	std::cout << "FragTrap let`s HighFive guys" << std::endl;
}