#include "Zombie.hpp"

int	main(void) {
	int		N = 10;
	Zombie* a = zombieHorde(N, "Cat");

	if (a == 0)
		return 1;
	for (int i = 0; i < N; i++)
		a[i].announce();
	delete[] a;
	return 0;
}