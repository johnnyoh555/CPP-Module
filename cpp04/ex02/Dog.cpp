#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog Default constructor called" << std::endl;
	this->type = "Dog";
	brain = new Brain;
}

Dog::~Dog() {
	std::cout << "Dog Destructor called" << std::endl;
	delete brain;
}

Dog::Dog(const Dog &ref) : Animal(ref) {
	std::cout << "Dog Copy constructor called" << std::endl;
	brain = new Brain;
}

Dog& Dog::operator= (const Dog &ref) {
	type = ref.type;
	delete brain;
	brain = new Brain(*ref.brain);
	return *this;
}

void	Dog::makeSound() const {std::cout << "Bowwow Bowwow" << '\n';}

std::string Dog::getBrainIdea(const int i) const {return brain->getIdea(i);}