#include "WrongCat.hpp"

WrongCat::WrongCat() {
	type = "WrongCat";
	std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::~WrongCat() {std::cout << "WrongCat Destructor called" << std::endl;}

WrongCat::WrongCat(const WrongCat &ref) : WrongAnimal(ref) {std::cout << "WrongCat Copy constructor called" << std::endl;}

WrongCat& WrongCat::operator= (const WrongCat &ref) {
	type = ref.type;
	return *this;
}

void	WrongCat::makeSound() const {std::cout << "Meeeeeeooooooooowwwwww" << '\n';}