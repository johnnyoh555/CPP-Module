#include "ClapTrap.hpp"

int main(void) {
	ClapTrap	ClapTrapA("ClapTrapA");
	ClapTrap	ClapTrapB("ClapTrapB");
	ClapTrap	ClapTrapC(ClapTrapA);
	ClapTrap	ClapTrapD("ClapTrapD");

	ClapTrapD = ClapTrapB;

	ClapTrapC.attack(ClapTrapD.getname());
	ClapTrapD.takeDamage(ClapTrapC.getattack_damage());
	ClapTrapD.beRepaired(10);
	std::cout << ClapTrapC.getenergy_point() << std::endl;
	std::cout << ClapTrapD.gethit_point() << std::endl;
	std::cout << ClapTrapD.getenergy_point() << std::endl;
}