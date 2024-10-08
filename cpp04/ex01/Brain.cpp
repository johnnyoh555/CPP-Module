#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain Default constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		ideas[i] = "None idea";
		std::stringstream ss;
		ss << i;
		ideas[i] += ss.str();
	}
}

Brain::~Brain() {std::cout << "Brain Destructor called" << std::endl;}

Brain::Brain(const Brain &ref) {
	std::cout << "Brain Copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		ideas[i] = ref.ideas[i];
	}
}

Brain& Brain::operator= (const Brain &ref) {
	if (this != &ref) {
		for (int i = 0; i < 100; i++) ideas[i] = ref.ideas[i];
	}
	return *this;
}

std::string Brain::getIdea(const int i) const {return ideas[i];}