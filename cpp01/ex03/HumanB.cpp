#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : name(name), MyWeapon(0) {}

HumanB::~HumanB() {}

void	HumanB::attack() {
	if (MyWeapon == 0)
		std::cout << name << " attacks with their " << "hand" << std::endl;
	else
		std::cout << name << " attacks with their " << MyWeapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &Weapon) {
	MyWeapon = &Weapon;
}