#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact{
	private:
		std::string	firstname;
		std::string lastname;
		std::string	nickname;
		std::string	phonenumber;
		std::string	darkestsecret;

	public:
		Contact();
		~Contact();

		void	set_firstname(const std::string& str);
		void	set_lastname(const std::string& str);
		void	set_nickname(const std::string& str);
		void	set_phonenumber(const std::string& str);
		void	set_darkestsecret(const std::string& str);

		const std::string& get_firstname(void) const;
		const std::string& get_lastname(void) const;
		const std::string& get_nickname(void) const;
		const std::string& get_phonenumber(void) const;
		const std::string& get_darkestsecret(void) const;

		void	print_info(void) const;
};

#endif