#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
	std::cout << "Cat Default constructor called" << std::endl;
}

Cat::~Cat() {std::cout << "Cat Destructor called" << std::endl;}

Cat::Cat(const Cat &ref) : Animal(ref) {std::cout << "Cat Copy constructor called" << std::endl;}

Cat& Cat::operator= (const Cat &ref) {
	type = ref.type;
	return *this;
}

void	Cat::makeSound() const {std::cout << "Meeeeeeooooooooowwwwww" << '\n';}