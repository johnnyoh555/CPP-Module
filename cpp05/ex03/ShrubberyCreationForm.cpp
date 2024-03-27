#include "ShrubberyCreationForm.hpp"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
	rhs.getName();
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs) : AForm(rhs), target(rhs.target) {}

const std::string& ShrubberyCreationForm::getTarget() const {return target;}

void ShrubberyCreationForm::execute(Bureaucrat const& execute) const {
	if (!getSign())
		throw NotSignedException();
	if (execute.getGrade() <= getGradeToExecute()) {
		std::string	tmp = getTarget() + "_shrubbery";
		std::ofstream out(tmp.c_str());

		if (out.is_open()) {
			out << "        +       \n";
			out << "       < >      \n";
			out << "      << >>     \n";
			out << "     <<< >>>    \n";
			out << "    <<<< >>>>   \n";
			out << "   <<<<< >>>>>  \n";
			out << "  <<<<<< >>>>>> \n";
			out << "       | |      \n";
			out << "       | |      \n";
			out << "       | |      \n";
			out.close();
		}
		else {
			throw OpenFailException();
		}
	} else {
		throw GradeTooLowException();
	}
}

ShrubberyCreationForm::OpenFailException::OpenFailException() : logic_error("Failed to Make file") {}