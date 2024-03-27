#include "AForm.hpp"

AForm::AForm(): name(""), sign(false), grade_to_sign(0), grade_to_execute(0) {}

AForm& AForm::operator= (const AForm& rhs) {
	sign = rhs.sign;
	return *this;
}

AForm::AForm(const std::string name, const int sign, const int execute) : name(name), sign(false), grade_to_sign(sign), grade_to_execute(execute) {
	if (sign < Highest_Rank || execute < Highest_Rank)
		throw GradeTooHighException();
	if (sign > Lowest_Rank || execute > Lowest_Rank)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& rhs) : name(rhs.name), sign(false), grade_to_sign(rhs.grade_to_sign), grade_to_execute(rhs.grade_to_execute) {}

AForm::~AForm() {}

const	std::string& AForm::getName() const {return name;}

bool	AForm::getSign() const {return sign;}

int		AForm::getGradeToSign() const {return grade_to_sign;}

int		AForm::getGradeToExecute() const {return grade_to_execute;}

void	AForm::beSigned(const Bureaucrat& rhs) {
	if (rhs.getGrade() <= grade_to_sign)
		sign = true;
	else
		throw GradeTooLowException();
}

AForm::GradeTooHighException::GradeTooHighException() : logic_error("Grade is too high") {}

AForm::GradeTooLowException::GradeTooLowException() : logic_error("Grade is too Low") {}

AForm::NotSignedException::NotSignedException() : logic_error("The Form is Not Signed") {}

std::ostream& operator<<(std::ostream& os, const AForm& rhs) {
	os << "Name: " << rhs.getName() << '\n';
	os << "Sign: " << rhs.getSign() << '\n';
	os << "Grade to Sign: " << rhs.getGradeToSign() << '\n';
	os << "Grade to Execute: " << rhs.getGradeToExecute() << '\n';
	return os;
}