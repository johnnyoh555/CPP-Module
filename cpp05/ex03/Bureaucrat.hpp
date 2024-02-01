#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class AForm;

class Bureaucrat {
	private:
		const static int	Highest_Rank = 1;
		const static int	Lowest_Rank = 150;
		const std::string	name;

		int	grade;
		Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& rhs);

	public:
		Bureaucrat(const std::string& name, const int grade);
		Bureaucrat(const Bureaucrat& rhs);
		~Bureaucrat();

		const std::string&	getName() const;
		int					getGrade() const;
		void				increment(int num);
		void				decrement(int num);

		void	signForm(AForm& rhs) const;
		void	executeForm(AForm& rhs);

		class GradeTooHighException : public std::logic_error {
			public:
				GradeTooHighException();
		};
		class GradeTooLowException : public std::logic_error {
			public:
				GradeTooLowException();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs);

#endif