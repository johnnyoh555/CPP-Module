#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	PhoneBook;
	std::string	str;

	while (1)
	{
		std::cout << "Command: " << std::flush;
		std::getline(std::cin, str);
		if (std::cin.fail())
		{
			std::cin.clear();
			std::clearerr(stdin);
			std::cout << std::endl;
		}
		if (str == "ADD")
			PhoneBook.ft_add();
		else if (str == "SEARCH")
			PhoneBook.ft_search();
		else if (str == "EXIT")
			break;
	}
	return (0);
}
