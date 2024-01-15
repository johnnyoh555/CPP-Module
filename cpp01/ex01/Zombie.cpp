#include "Zombie.hpp"

Zombie::Zombie() : name("") {}

Zombie::Zombie(const std::string& name) : name(name) {}

Zombie::~Zombie() {
	std::cout << name << ": destroyed" << std::endl;
}

void	Zombie::announce(void) const {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(const std::string& name) {
	this->name = name;
}