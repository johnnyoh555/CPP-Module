#ifndef FORM_HPP
#define FORM_HPP

# include <iostream>
# include <exception>

# include "Bureaucrat.hpp"

class Form {
	private:
		const static int	Highest_Rank = 1;
		const static int	Lowest_Rank = 150;

		const std::string	name;
		bool				sign;
		const int 			grade_to_sign;
		const int			grade_to_execute;

		Form();
		Form& operator= (const Form& rhs);

	public:
		Form(const std::string name, const int sign, const int execute);
		Form(const Form& rhs);
		~Form();

		const std::string&	getName() const;
		bool				getSign() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		void 				beSigned(const Bureaucrat& rhs);

		class GradeTooHighException : public std::logic_error {
			public:
				GradeTooHighException();
		};
		class GradeTooLowException : public std::logic_error {
			public:
				GradeTooLowException();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& rhs);

#endif