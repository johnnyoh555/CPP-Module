#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	try {
		Bureaucrat	bu("jooh", 10);
		std::cout << bu;
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try {
		Bureaucrat	bu("jooh2", 10);
		Form		fm("abc", 20, 20);
		std::cout << fm;
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try {
		Bureaucrat	bu("jooh3", 140);
		Form		fm("abc", 20, 20);
		bu.signForm(fm);
		std::cout << fm;
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try {
		Bureaucrat	bu("jooh4", 10);
		Form		fm("abc", 20, 20);
		bu.signForm(fm);
		std::cout << fm;
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}