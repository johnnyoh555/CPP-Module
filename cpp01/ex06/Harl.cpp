#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug(void) {
	std::cout << "[ DEBUG ]" << '\n';
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n" << std::endl;
}

void	Harl::info(void) {
	std::cout << "[ INFO ]" << '\n';
	std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void	Harl::warning(void) {
	std::cout << "[ WARNING ]" << '\n';
	std::cout <<  "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void	Harl::error(void) {
	std::cout << "[ ERROR ]" << '\n';
	std::cout << "This is unacceptable, I want to speak to the manager now.\n" << std::endl;
}

void	Harl::complain(std::string level) {
	std::string	strs[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {
		if (strs[i] == level) {
			switch (i) {
				case 0:
					debug();
					__attribute__((fallthrough));
				case 1:
					info();
					__attribute__((fallthrough));
				case 2:
					warning();
					__attribute__((fallthrough));
				case 3:
					error();
					break;
			}
			return ;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
