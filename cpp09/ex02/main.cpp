#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char* av[]) {
	if (ac == 1) return 0;
	VectorFJ v;
	DequeFJ dq;

	v.makeVector(ac, av);
	v.execute();
	dq.makeDeque(ac, av);
	dq.execute();
	std::cout << "Before:  ";
	for (int i = 1; i < ac; i++) {
		std::cout << av[i] << ' ';
	}
	std::cout << '\n';
	v.print();
	dq.print();
	v.result();
	dq.result();
}