#include "Bureaucrat.hpp"

int main(void) {
	try {
		Bureaucrat	bu("jooh1", 1);
		std::cout << bu;
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try {
		Bureaucrat	bu("jooh2", 0);
		std::cout << bu;
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try {
		Bureaucrat	bu("jooh3", 151);
		std::cout << bu;
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try {
		Bureaucrat	bu("jooh4", 1);
		bu.increment(5);
		std::cout << bu;
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try {
		Bureaucrat	bu("jooh5", 1);
		bu.decrement(4);
		std::cout << bu;
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try {
		Bureaucrat	bu("jooh6", 130);
		bu.decrement(30);
		std::cout << bu;
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try {
		Bureaucrat	bu("jooh7", 50);
		bu.increment(10);
		std::cout << bu;
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}