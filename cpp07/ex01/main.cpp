#include "iter.hpp"

void uppercase(char c) {
	if (c >= 'a' && c <= 'z')
		c = c + ('A' - 'a');
	std::cout << c;
}

void	plusone(int i) {
	std::cout << i + 1;
}

int main(void) {
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	char str[6] = {"Hello"};

	::iter(arr, 10, plusone);
	std::cout << '\n';
	::iter(str, 6, uppercase);
	std::cout << '\n';
}