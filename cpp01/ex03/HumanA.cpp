#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon &Weapon) : MyWeapon(Weapon),  name(name) {}

HumanA::~HumanA() {}

void	HumanA::attack() {
	std::cout << name << " attacks with their " << MyWeapon.getType() << std::endl;
}