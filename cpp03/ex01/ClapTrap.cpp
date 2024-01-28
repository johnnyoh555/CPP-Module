#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {std::cout << "ClapTrap Default constructor called" << std::endl;}

ClapTrap::ClapTrap(const std::string name) {
	std::cout << "ClapTrap Default constructor called" << std::endl;
	this->name = name;
	hit_point = 10;
	energy_point = 10;
	attack_damage = 0;
}

ClapTrap::~ClapTrap() {std::cout << "ClapTrap Destructor called" << std::endl;}

ClapTrap::ClapTrap(const ClapTrap &ref) : name(ref.name), hit_point(ref.hit_point), energy_point(ref.energy_point), attack_damage(ref.attack_damage) {
	std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator= (const ClapTrap &ref) {
	this->name = ref.name;
	this->hit_point = ref.hit_point;
	this->energy_point = ref.energy_point;
	this->attack_damage = ref.attack_damage;
	return *this;
}

std::string ClapTrap::getname() const {return name;}

int	ClapTrap::gethit_point() const {return hit_point;}

int ClapTrap::getenergy_point() const {return energy_point;}

int ClapTrap::getattack_damage() const {return attack_damage;}

void	ClapTrap::attack(const std::string& target) {
	if (hit_point <= 0) {
		std::cout << "ClapTrap " << name << " Dead" << std::endl;
		return;
	}
	if (energy_point == 0) {
		std::cout << "Not enough energy" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " attacks " << target \
		<< ", causing " << attack_damage << " points of damage!" << std::endl;
	energy_point--;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (hit_point <= 0) {
		std::cout << "ClapTrap " << name << " Dead" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " takes " << amount << " damage!" << std::endl;
	hit_point -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (hit_point <= 0) {
		std::cout << "ClapTrap " << name << " Dead" << std::endl;
		return;
	}
	if (energy_point == 0) {
		std::cout << "Not enough energy" << std::endl;
		return ;
	}
	if (amount > 1)
		std::cout << "ClapTrap " << name << " repaired " << amount << " hit points" << std::endl;
	else 
		std::cout << "ClapTrap " << name << " repaired " << amount << " hit point" << std::endl;
	energy_point--;
	hit_point += amount;
}