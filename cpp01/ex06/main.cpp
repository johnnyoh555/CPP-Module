#include "Harl.hpp"

int	main(int ac, char **av) {
	Harl	Harl;

	if (ac != 2)
		return 0;
	Harl.complain(av[1]);
	return (0);
}