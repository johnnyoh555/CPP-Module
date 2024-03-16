#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat Default constructor called" << std::endl;
	type = "Cat";
	brain = new Brain;
}

Cat::~Cat() {
	std::cout << "Cat Destructor called" << std::endl;
	delete brain;
}

Cat::Cat(const Cat &ref) : Animal(ref) {
	std::cout << "Cat Copy constructor called" << std::endl;
	brain = new Brain(*ref.brain);
}

Cat& Cat::operator= (const Cat &ref) {
	if (this != &ref) {
		type = ref.type;
		delete brain;
		brain = new Brain(*ref.brain);
	}
	return *this;
}

void	Cat::makeSound() const {std::cout << "Meeeeeeooooooooowwwwww" << '\n';}

std::string Cat::getBrainIdea(const int i) const {return brain->getIdea(i);}