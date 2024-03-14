#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {} 

Cure::~Cure() {}

Cure::Cure(const Cure& ref) : AMateria(ref) {}

Cure& Cure::operator= (const Cure &ref) {
	if (this != &ref) type = ref.type;
	return *this;
}

Cure* Cure::clone() const {return new Cure();}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}