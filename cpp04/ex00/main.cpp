#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << "\n\n";

	const WrongAnimal* wmeta = new WrongAnimal();
	const WrongAnimal* w = new WrongCat();
	std::cout << w->getType() << " " << std::endl;
	w->makeSound();
	wmeta->makeSound();
	delete meta;
	delete j;
	delete i;
	delete wmeta;
	delete w;
	return 0;
}