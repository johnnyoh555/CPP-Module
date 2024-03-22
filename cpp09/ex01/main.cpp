#include "RPN.hpp"

int main(int ac, char *av[]) {
	if (ac == 1)
		return (0);
	else if (ac != 2) {
		std::cerr << "I think you're giving me too many arguments\n"; 
		return (1);
	}

	RPN	rpn;
	try {
		rpn.calculate(av[1]);
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
		return (1);
	}
	return (0);
}