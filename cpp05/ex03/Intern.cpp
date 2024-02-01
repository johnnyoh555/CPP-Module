#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& rhs) {(void)rhs;};

Intern& Intern::operator=(const Intern& rhs) {(void)rhs;return *this;}

AForm* Intern::makeShrubberyCreationForm(const std::string& target) {
	ShrubberyCreationForm	*ret = new ShrubberyCreationForm(target);
	std::cout << "Intern creates ShrubberyCreationForm\n";
	return ret;
}

AForm* Intern::makeRobotomyRequestForm(const std::string& target) {
	RobotomyRequestForm	*ret = new RobotomyRequestForm(target);
	std::cout << "Intern creates RobotomyRequestForm\n";
	return ret;
}

AForm* Intern::makePresidentialPardonForm(const std::string& target) {
	PresidentialPardonForm	*ret = new PresidentialPardonForm(target);
	std::cout << "Intern creates PresidentialPardonForm\n";
	return ret;
}

Intern::FailToMakeFormException::FailToMakeFormException() : invalid_argument("Failed to make Form. Check Form Name") {}

AForm*	Intern::makeForm(const std::string& name, const std::string& target) {
	std::string strs[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*f[3])(const std::string& target) = {&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};

	for (int i = 0; i < 3; i++) {
		if (strs[i] == name) {
			return (this->*f[i])(target);
		}
	}
	throw FailToMakeFormException();
}