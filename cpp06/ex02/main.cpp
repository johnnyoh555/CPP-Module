#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

Base*	generate(void) {
	A*	ap;
	B*	bp;
	C*	cp;

	int r_value = std::rand();
	if (r_value % 3 == 0) {
		ap = new A;
		return ap;
	}
	else if (r_value % 3 == 1) {
		bp = new B;
		return bp;
	}
	cp = new C;
	return cp;
}

void	identify(Base* p) {
	A*	ptr_a;
	B*	ptr_b;
	C*	ptr_c;

	ptr_a = dynamic_cast<A*>(p);
	ptr_b = dynamic_cast<B*>(p);
	ptr_c = dynamic_cast<C*>(p);
	if (ptr_a)
		std::cout << "A\n";
	else if (ptr_b)
		std::cout << "B\n";
	else if (ptr_c)
		std::cout << "C\n";
}

void	identify(Base& p) {
	try {
		A& ref_a = dynamic_cast<A&>(p);
		std::cout << "A\n";
		(void)ref_a;
	} catch (std::bad_cast) {}
	try {
		B& ref_b = dynamic_cast<B&>(p);
		std::cout << "B\n";
		(void)ref_b;
	} catch (std::bad_cast) {}
	try {
		C& ref_c = dynamic_cast<C&>(p);
		std::cout << "C\n";
		(void)ref_c;
	} catch (std::bad_cast) {}
}

int	main(void) {
	std::srand(std::time(0));

	for(int i = 0; i < 10; i++) {
		Base*	base;

		base = generate();

		identify(base);
	
		identify(*base);

		delete base;
	}
}