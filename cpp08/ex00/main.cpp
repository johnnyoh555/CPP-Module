#include "easyfind.hpp"

int main() {
	std::vector<int> V;
	std::deque<int> DQ;
	std::array<int, 10> arr;

	for (int i = 0; i < 10; i++){
		V.push_back(i);
		DQ.push_back(i);
		arr[i] = i;
	}
	try {
		std::cout << *(easyfind(V, 5)) << '\n';
	} catch (std::exception& e) {
		std::cout << e.what() << '\n';
	}
	try {
		std::cout << *(easyfind(DQ, 3)) << '\n';
	} catch (std::exception& e) {
		std::cout << e.what() << '\n';
	}
	try {
		std::cout << *(easyfind(V, 1)) << '\n';
	} catch (std::exception& e) {
		std::cout << e.what() << '\n';
	}
	try {
		std::cout << *(easyfind(arr, -20)) << '\n';
	} catch (std::exception& e) {
		std::cout << e.what() << '\n';
	}
	try {
		std::cout << *(easyfind(V, 10)) << '\n';
	} catch (std::exception& e) {
		std::cout << e.what() << '\n';
	}
}