#include "Span.hpp"

int main()
{
	try {
		Span sp = Span(10000);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::vector<int> V;
		for (int i = 0; i < 10000; i++) {
			V.push_back(i * 30);
		}

		sp.addNumber(V.begin(), V.end());
	
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::logic_error& e) {
		std::cout << e.what() << '\n';
	}

	try {
		Span sp = Span(15000);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::vector<int> V;
		for (int i = 0; i < 10000; i++) {
			V.push_back(i * 30);
		}

		sp.addNumber(V.begin(), V.end());
	
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::logic_error& e) {
		std::cout << e.what() << '\n';
	}

	try {
		Span sp = Span(10000);
		sp.addNumber(6);
	
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::logic_error& e) {
		std::cout << e.what() << '\n';
	}

	return 0;
}