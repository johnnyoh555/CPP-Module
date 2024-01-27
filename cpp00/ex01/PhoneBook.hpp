#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip> // std::setw
# include <string> // substr
# include <cstdio> // stdin

# include "Contact.hpp"

class PhoneBook{
	private:
		static const int	MAX_INDEX = 8;
		
		Contact	contact[MAX_INDEX];
		int 	idx;
		int 	cnt;

		int		is_printalbe(std::string& str) const;
		int		is_digit(std::string& str) const;

		const	std::string cut_info(const std::string str);

	public:
		PhoneBook();
		~PhoneBook();

		void	ft_add();
		void	ft_search();
		void	print_Contact(int idx);
		void	ft_search(int idx);
};

#endif