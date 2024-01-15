#include "Zombie.hpp"

int	main(void) {
	Zombie a("ZombieA");
	Zombie* b = newZombie("ZombieB");

	a.announce();
	b->announce();

	randomChump("ZombieC");
	delete b;
	return 0;
}