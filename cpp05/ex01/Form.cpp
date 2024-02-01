#include "Form.hpp"

Form::Form(): name(""), sign(false), grade_to_sign(0), grade_to_execute(0) {}

Form& Form::operator= (const Form& rhs) {
	sign = rhs.sign;
	return *this;
}

Form::Form(const std::string name, const int sign, const int execute) : name(name), sign(false), grade_to_sign(sign), grade_to_execute(execute) {
	if (sign < Highest_Rank || execute < Highest_Rank)
		throw GradeTooHighException();
	if (sign < Highest_Rank || execute < Highest_Rank)
		throw GradeTooLowException();
}

Form::Form(const Form& rhs) : name(rhs.name), sign(false), grade_to_sign(rhs.grade_to_sign), grade_to_execute(rhs.grade_to_execute) {}

Form::~Form() {}

const	std::string& Form::getName() const {return name;}

bool	Form::getSign() const {return sign;}

int		Form::getGradeToSign() const {return grade_to_sign;}

int		Form::getGradeToExecute() const {return grade_to_execute;}

void	Form::beSigned(const Bureaucrat& rhs) {
	if (rhs.getGrade() <= grade_to_sign)
		sign = true;
	else
		throw GradeTooLowException();
}

Form::GradeTooHighException::GradeTooHighException() : logic_error("Grade is too high") {}

Form::GradeTooLowException::GradeTooLowException() : logic_error("Grade is too Low") {}

std::ostream& operator<<(std::ostream& os, const Form& rhs) {
	os << "Name: " << rhs.getName() << '\n';
	os << "Sign: " << rhs.getSign() << '\n';
	os << "Grade to Sign: " << rhs.getGradeToSign() << '\n';
	os << "Grade to Execute: " << rhs.getGradeToExecute() << '\n';
	return os;
}