#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
	rhs.getName();
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs) : AForm(rhs), target(rhs.target) {}

const std::string& RobotomyRequestForm::getTarget() const {return target;}

RobotomyRequestForm::RobotomizeFailException::RobotomizeFailException() : logic_error("Failed to Robotomize") {}

void RobotomyRequestForm::execute(Bureaucrat const& execute) const {
	if (!getSign())
		throw NotSignedException();
	if (execute.getGrade() <= getGradeToExecute()) {
		std::srand(std::time(0));
		int r_value = std::rand();
		if (r_value % 2 == 0)
			std::cout << getTarget() << " has been robotomized\n";
		else
			throw RobotomizeFailException();
	} else {
		throw GradeTooLowException();
	}
}