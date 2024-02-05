#include "iter.hpp"

char uppercase(char c) {
	if (c >= 'a' && c <= 'z')
		return c + ('A' - 'a');
	return c;
}

int	plusone(int i) {
	return i + 1;
}

int main(void) {
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	char str[6] = {"Hello"};

	::iter(arr, 10, plusone);
	::iter(str, 6, uppercase);

	for (int i = 0; i < 10; i++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
	for (int i = 0; i < 6; i++) {
		std::cout << str[i];
	}
	std::cout << '\n';

}