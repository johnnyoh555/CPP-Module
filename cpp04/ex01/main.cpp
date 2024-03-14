#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal* meta[10];

	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0)
			meta[i] = new Dog();
		else
			meta[i] = new Cat();
	}
	for (int i = 0; i < 10; i++) {
		std::cout << i << ": " << meta[i]->getType() << '\n';
	}

	for (int i = 0 ; i < 10; i++) {
		delete meta[i];
	}

	Dog *d = new Dog;
	Dog d2;
	for (int i = 0; i < 10; i++) {
		std::cout << d->getBrainIdea(i * 10) << '\n';
	}
	for (int i = 0; i < 10; i++) {
		std::cout << d2.getBrainIdea(i * 5) << '\n';
	}
	delete d;
	return 0;
}