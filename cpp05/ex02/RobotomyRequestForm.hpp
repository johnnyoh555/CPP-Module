#ifndef ROBOTOMYREQUESTFORM_CPP
#define ROBOTOMYREQUESTFORM_CPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		const std::string target;

		RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);

	public:
		RobotomyRequestForm(const std::string& target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& rhs);

		const std::string&	getTarget() const;
		
		void	execute(Bureaucrat const & executor) const;

		class RobotomizeFailException : public std::logic_error {
			public:
				RobotomizeFailException();
		};
};

#endif
