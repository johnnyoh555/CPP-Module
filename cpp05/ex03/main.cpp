#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(void) {
	Intern someRandomIntern;
	AForm* rrf;

	try {
		Bureaucrat				bu("jooh1", 20);
		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		bu.signForm(*rrf);
		bu.executeForm(*rrf);
		delete rrf;
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << '\n';


	try {
		Bureaucrat				bu("jooh2", 20);
		rrf = someRandomIntern.makeForm("robotomy request", "Tommy");
		bu.signForm(*rrf);
		bu.executeForm(*rrf);
		delete rrf;
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << '\n';


	try {
		Bureaucrat				bu("jooh3", 20);
		rrf = someRandomIntern.makeForm("presidential pardon", "jac");
		bu.signForm(*rrf);
		bu.executeForm(*rrf);
		delete rrf;
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << '\n';

	try {
		Bureaucrat				bu("jooh3", 20);
		rrf = someRandomIntern.makeForm("none", "jac");
		bu.signForm(*rrf);
		bu.executeForm(*rrf);
		delete rrf;
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << '\n';
	return 0;
}