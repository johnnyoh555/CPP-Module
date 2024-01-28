#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {std::cout << "WrongAnimal Default constructor called" << std::endl;}

WrongAnimal::~WrongAnimal() {std::cout << "WrongAnimal Destructor called" << std::endl;}

WrongAnimal::WrongAnimal(const WrongAnimal &ref) : type(ref.type) {std::cout << "WrongAnimal Copy constructor called" << std::endl;}

WrongAnimal& WrongAnimal::operator= (const WrongAnimal &ref) {
	type = ref.type;
	return *this;
}

void	WrongAnimal::makeSound() const {std::cout << "(Silence)" << '\n';}

std::string WrongAnimal::getType() const {return this->type;}