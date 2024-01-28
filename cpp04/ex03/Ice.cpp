#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice") {} 

Ice::~Ice() {}

Ice::Ice(const Ice& ref) : AMateria(ref) {}

Ice& Ice::operator= (const Ice &ref) {
	if (this != &ref)
		type = ref.type;
	return *this;
}

Ice* Ice::clone() const {return new Ice();}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}