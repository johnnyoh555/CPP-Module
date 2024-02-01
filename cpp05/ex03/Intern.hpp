#ifndef INTERN_HPP
#define INTERN_HPP

# include "Bureaucrat.hpp"
# include <exception>

class Intern {
	public:
		Intern();
		~Intern();
		Intern(const Intern& rhs);
		Intern& operator=(const Intern& rhs);

		AForm*	makeForm(const std::string& name, const std::string& target);

		AForm* makeShrubberyCreationForm(const std::string& target);
		AForm* makeRobotomyRequestForm(const std::string& target);
		AForm* makePresidentialPardonForm(const std::string& target);

		class	FailToMakeFormException : public std::invalid_argument {
			public:
				FailToMakeFormException();
		};
};

#endif