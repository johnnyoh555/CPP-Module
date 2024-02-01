#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
	rhs.getName();
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs) : AForm(rhs), target(rhs.target) {}

const std::string& PresidentialPardonForm::getTarget() const {return target;}

void PresidentialPardonForm::execute(Bureaucrat const& execute) const {
	if (!getSign())
		throw NotSignedException();
	if (execute.getGrade() <= getGradeToExecute()) {
		std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox\n";
	} else {
		throw GradeTooLowException();
	}
}
