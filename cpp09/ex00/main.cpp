#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char *av[]) {
	if (ac != 2) {
		std::cout << "The right usage is ./btc [file]\n";
		return 1;
	}
	BitcoinExchange	btc;
	try {
		btc.makeData();
		btc.parseInfile(av[1]);
	} catch (exception& e) {
		std::cout << e.what() << '\n';
		return 1;
	}
}