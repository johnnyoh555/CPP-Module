#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    for (int i = 0; i < MAX_VAL; i++) {
        const int value = i;
        numbers[i] = value;
        mirror[i] = value;
    }
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        for (int i = 0; i <= MAX_VAL && i <= 10; i++) {
            std::cout << "test: " << tmp[i] << "\ntmp: " << test[i] << '\n';
        }
    }

    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try {
        numbers[-2] = 0;
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    try {
        numbers[MAX_VAL] = 0;
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    Array<std::string> str(2);
    str[0] = "hello\n";
    str[1] = "bye\n";
    const Array<std::string> arr(str);
    std::cout << arr[0] << arr[1];

    delete [] mirror;
    return 0;
}