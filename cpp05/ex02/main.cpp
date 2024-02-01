#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void) {
	try {
		Bureaucrat				bu("jooh", 10);
		ShrubberyCreationForm	afm("target1");
		std::cout << bu;
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << '\n';
	try {
		Bureaucrat				bu("jooh2", 140);
		ShrubberyCreationForm	afm("target2");
		bu.signForm(afm);
		bu.executeForm(afm);
		std::cout << afm;
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << '\n';
	try {
		Bureaucrat				bu("jooh3", 10);
		ShrubberyCreationForm	afm("target3");
		bu.executeForm(afm);
		std::cout << afm;
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << '\n';
	try {
		Bureaucrat				bu("jooh4", 10);
		ShrubberyCreationForm	afm("target4");
		bu.signForm(afm);
		bu.executeForm(afm);
		std::cout << afm;
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << '\n';
	try {
		Bureaucrat				bu("jooh2", 70);
		RobotomyRequestForm		afm("target2");
		bu.signForm(afm);
		bu.executeForm(afm);
		std::cout << afm;
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << '\n';
	try {
		Bureaucrat				bu("jooh3", 10);
		RobotomyRequestForm		afm("target3");
		bu.executeForm(afm);
		std::cout << afm;
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << '\n';
	try {
		Bureaucrat				bu("jooh4", 10);
		RobotomyRequestForm		afm("target4");
		bu.signForm(afm);
		bu.executeForm(afm);
		std::cout << afm;
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << '\n';
	try {
		Bureaucrat				bu("jooh2", 20);
		PresidentialPardonForm	afm("target2");
		bu.signForm(afm);
		bu.executeForm(afm);
		std::cout << afm;
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << '\n';
	try {
		Bureaucrat				bu("jooh3", 5);
		PresidentialPardonForm	afm("target3");
		bu.executeForm(afm);
		std::cout << afm;
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << '\n';
	try {
		Bureaucrat				bu("jooh4", 5);
		PresidentialPardonForm	afm("target4");
		bu.signForm(afm);
		bu.executeForm(afm);
		std::cout << afm;
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << '\n';
	return 0;
}