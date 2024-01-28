#include "Animal.hpp"

Animal::Animal() : type("Animal") {std::cout << "Animal Default constructor called" << std::endl;}

Animal::~Animal() {
	std::cout << "Animal Destructor called" << std::endl;
}

Animal::Animal(const Animal &ref) : type(ref.type) {
	std::cout << "Animal Copy constructor called" << std::endl;
}

Animal& Animal::operator= (const Animal &ref) {
	type = ref.type;
	return *this;
}

// void	Animal::makeSound() const {std::cout << "(Silence)" << '\n';}

std::string Animal::getType() const {return this->type;}