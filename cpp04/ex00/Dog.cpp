#include "Dog.hpp"

Dog::Dog() {
	this->type = "Dog";
	std::cout << "Dog Default constructor called" << std::endl;	
}

Dog::~Dog() {std::cout << "Dog Destructor called" << std::endl;}

Dog::Dog(const Dog &ref) : Animal(ref) {std::cout << "Dog Copy constructor called" << std::endl;}

Dog& Dog::operator= (const Dog &ref) {
	if (this != &ref) type = ref.type;
	return *this;
}

void	Dog::makeSound() const {std::cout << "Bowwow Bowwow" << '\n';}