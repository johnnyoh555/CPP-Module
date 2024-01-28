#include "ScavTrap.hpp"

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

	ScavTrap	ScavTrapA("ScavTrapA");
	ScavTrap	ScavTrapB(ScavTrapA);
	ScavTrap	ScavTrapC("ScavTrapC");

	ScavTrapB = ScavTrapC;

	ScavTrapA.attack(ScavTrapB.getname());
	ScavTrapB.takeDamage(ScavTrapA.getattack_damage());
	std::cout << "ScavTrapA EP: " << ScavTrapA.getenergy_point() << std::endl;
	std::cout << "ScavTrapB HP: " << ScavTrapB.gethit_point() << std::endl;
	ScavTrapB.beRepaired(10);
	std::cout << "ScavTrapB HP: " << ScavTrapB.gethit_point() << std::endl;
	std::cout << "ScavTrapB EP: " << ScavTrapB.getenergy_point() << std::endl;
	ScavTrapB.guardGate();
}