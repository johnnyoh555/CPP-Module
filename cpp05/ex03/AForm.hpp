#ifndef FORM_HPP
#define FORM_HPP

# include <iostream>
# include <exception>

# include "Bureaucrat.hpp"

class AForm {
	private:
		const static int	Highest_Rank = 1;
		const static int	Lowest_Rank = 150;

		const std::string	name;
		bool				sign;
		const int 			grade_to_sign;
		const int			grade_to_execute;

		AForm();
		AForm& operator= (const AForm& rhs);

	public:
		AForm(const std::string name, const int sign, const int execute);
		AForm(const AForm& rhs);
		virtual ~AForm();

		const std::string&	getName() const;
		bool				getSign() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		void 				beSigned(const Bureaucrat& rhs);
		virtual void		execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::logic_error {
			public:
				GradeTooHighException();
		};
		class GradeTooLowException : public std::logic_error {
			public:
				GradeTooLowException();
		};
		class NotSignedException : public std::logic_error {
			public:
				NotSignedException();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& rhs);

#endif