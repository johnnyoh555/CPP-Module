#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
	grade = rhs.grade;
	return *this;
}

Bureaucrat::Bureaucrat(const std::string& name, const int grade) : name(name), grade(grade) {
	if (this->grade < Highest_Rank)
		throw GradeTooHighException();
	if (this->grade > Lowest_Rank)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs) : name(rhs.name), grade(rhs.grade) {}

const std::string& Bureaucrat::getName() const {return name;}

int Bureaucrat::getGrade() const {return grade;}

void	Bureaucrat::increment(int num) {
	if (this->grade - num < Highest_Rank)
		throw GradeTooHighException();
	grade -= num;
}

void	Bureaucrat::decrement(int num) {
	if (this->grade + num > Lowest_Rank)
		throw GradeTooLowException();
	grade += num;
}

Bureaucrat::GradeTooHighException::GradeTooHighException() : logic_error("Grade is Too High") {}

Bureaucrat::GradeTooLowException::GradeTooLowException() : logic_error("Grade is Too Low") {}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs) {
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << '\n';
	return os;
}