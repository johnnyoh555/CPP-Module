#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : type("AMateria") {}

AMateria::AMateria(std::string const &type) : type(type) {}

AMateria::AMateria(const AMateria &ref) {this->type = ref.type;}

AMateria& AMateria::operator=(const AMateria &ref) {
	if (this != &ref)
		this->type = ref.type;
	return *this;
}

AMateria::~AMateria() {}

std::string const& AMateria::getType() const {return type;}

void AMateria::use(ICharacter& target) {
	std::cout << "Use AMatria to " << target.getName() << '\n';
}