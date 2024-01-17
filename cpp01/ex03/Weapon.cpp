#include "Weapon.hpp"

Weapon::Weapon() : type("") {}

Weapon::~Weapon() {}

Weapon::Weapon(const std::string& type) {
	this->type = type;
}

const std::string	Weapon::getType() const {
	return type;
}

void	Weapon::setType(const std::string& type) {
	this->type = type;
}